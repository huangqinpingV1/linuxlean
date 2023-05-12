#include <execinfo.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../lib/tlpi_hdr.h"
#define BT_BUF_SIZE  100


void myfunc3(void){
	int j,nptrs;
	void* buffer[BT_BUF_SIZE];
	char** strings;

	nptrs = backtrace(buffer,BT_BUF_SIZE);
	printf("backtrace() returned %d addresses\n",nptrs);
	
	strings = backtrace_symbols(buffer,nptrs);

	if(strings  == NULL)
		errExit("backtrace_symbols");
	
	for (j =0;j<nptrs;j++){
		printf("%s\n",strings[j]);
	}
	free(strings);
	
}

static void myfunc2(void){
	myfunc3();
}
//ncalls： call stack lenght,递归函数
void myfunc(int ncalls){
	if(ncalls  > 1)
		myfunc(ncalls-1);
	else
		myfunc2();
		
}

int main(int argc,char** argv){
	if(argc != 2 || strcmp(argv[1],"--help")==0)
		usageErr("%s num-calls\n",argv[0]);

	myfunc(atoi(argv[1]));
	exit(EXIT_SUCCESS);	
}
