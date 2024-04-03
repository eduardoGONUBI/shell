#include "shell.h"

int isdoc(int fileDescriptor)
{
	unsigned char b[4];
	read(fileDescriptor,b,4);
	lseek(fileDescriptor,0,SEEK_SET);
	
	if(b[0]==0x50 && b[1] == 0x4b && b[2]==0x03 && b[3]==0x04)
		return 1;
	return 0;
}
