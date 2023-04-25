#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "../lib/tlpi_hdr.h"

int main(int argc, char** argv){
	size_t len;
	off_t offset;
	int fd,ap,j;
	unsigned char* buf;
	ssize_t numRead,numWritten;
	
	if(argc < 3 || strcmp(argv[1],"--help")  == 0)
		usageErr("%s file {r<length>|R<length>|w<string>|s<offset>}...\n",argv[0]);

	fd = open(argv[1],O_RDWR|O_CREAT,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH|S_IWOTH);
	if(fd == -1)
		errExit("open");

	for(ap=2;ap <argc;ap++){
		switch(argv[ap][0]){
			case 'r':
			case 'R':
				len = getLong(&argv[ap][1],GN_ANY_BASE,argv[ap]);
				
				buf = malloc(len);
				if(buf == NULL)
					errExit("read");

				numRead = read(fd,buf,len);
				if(numRead == -1)
					errExit("read");

				if(numRead == 0){
					printf("%s:end of the file\n",argv[ap]);		
				}else{
					printf("%s",argv[ap]);
					for(j = 0;j < numRead;j++){
						if(argv[ap][0] == 'r'){
							printf("%c",isprint(buf[j])? buf[j]:'?');
						}else{
							printf("%02x",buf[j]);
						}
					}	
				}
				free(buf);
				break;
		 	case 'w':
				/*Write string at current offset*/
				numWritten =write(fd,&argv[ap][1],strlen(&argv[ap][1]));
				if(numWritten == -1)
					errExit("write");
				printf("%s:wrote %ld bytes\n",argv[ap],(long)numWritten);	
				break;
			case 's':
				offset =getLong(&argv[ap][1],GN_ANY_BASE,argv[ap]);
				if((offset=lseek(fd,offset,SEEK_SET))== -1)
					errExit("lseek");
				printf("%s:seek success,offset =%ld\n",argv[ap],offset);
				break;		
		}
	}
	if(close(fd) == -1)
		errExit("close");
	exit(EXIT_SUCCESS);
}
