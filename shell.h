#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <errno.h>
#include <pthread.h>



int builtin(char **args, int numargs);


int parse(char *buf, char **args);


void execute(int numargs, char **args);
int containsPipe (int numArgs, char **args);


typedef struct { char fonte[100]; char destino[100]; } copiar_t;
void *socpwrapper(void *args);
void socp(char *fonte, char *destino);
void ioCopy(int IN, int OUT);


void calc( char *value1, char *op, char *value2);


void bits (char *op1, char *op, char *op2);
void bits_not(char *op, char *value);
int isjpg(int fileDescriptor);
int isdoc(int fileDescriptor);


int redirects (int numargs, char *args[]);


typedef struct{
    char msg[100];
    int tempo;
}aviso_t;

void aviso (char *mseg, int tempo);
void *avisowrapper(void *args);


#define BG 0
#define FG 1
