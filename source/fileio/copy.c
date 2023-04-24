/*将文件"agrv[1]"内容复制到文件"argv[2]"中
 * */
#include  <sys/stat.h>
#include <sys/fcntl.h>
#include "../lib/tlpi_hdr.h"

#ifndef  BUF_SIZE
#define BUF_SIZE  1024
#endif


int main(int argc,char** argv){
	int inputFd,outPutFd,openFlags;
	mode_t filePerms;
	ssize_t numRead;
	char buf[BUF_SIZE];
	
	if(argc !=3  || strcmp(argv[1],"--help")==0)
		usageErr("%s old-file new-file\n",argv[0]);	
	return 0;
}
