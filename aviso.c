#include "shell.h"

void aviso (char *mesage, int time)
{
	while(time > 0)
	{
		sleep(1);
		time--;
	}
	fprintf(stderr, "AVISO: %s\n", mesage);
}

void *avisowrapper(void *args)
{
	aviso_t *ptr = (aviso_t *)args;
	
	aviso(ptr->msg, ptr->tempo);
	
	free(ptr);
	
	return NULL;
}
