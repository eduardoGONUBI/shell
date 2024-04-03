#include "shell.h"

char prompt[100];

int main()
{
  int len;
  char linha[1024];
  char *args[64];

  strcpy(prompt, "SOSHELL: introduza um comando: prompt > ");
  while (1)
  {
    printf("%s", prompt);

    if (fgets(linha, 1023, stdin) == NULL)
    {
      printf("\n");
      exit(0);
    }
    len = strlen(linha);
    if (1 == len)
      continue;
    if (linha[len - 1] == '\n')
      linha[len - 1] = '\0';
    int numargs = parse(linha, args);

    if (!builtin(args, numargs))
    {
      execute(numargs, args);
    }
  }
  return 0;
}

int builtin(char **args, int numargs){

 if(strcmp(args[0],"maior")==0){
 	if(args[1] !=NULL && args[2]!=NULL){
 		FILE *file1=fopen(args[1],"r");
 		FILE *file2=fopen(args[2],"r");
 		
 		fseek(file1,0L,SEEK_END);
 		float size_1=ftell(file1);
 		fseek(file2,0L,SEEK_END);
 		float size_2=ftell(file2);
 		if(size_1>size_2){
 			printf("Nome:%s Tamanho:%0.2f\n",args[1],size_1);
 			return 1;
 		}else if(size_2>size_1){
 			printf("Nome:%s Tamanho:%0.2f\n",args[2],size_2);
 			return 1;
 		}else if(size_2==size_1){
 			printf("Os ficheiros tem o mesmo tamanho! Tamanho:%0.2f\n",size_1);
 			return 1;
 		}
 
 	}else{
 		printf("Faltam argumentos!\n");
 	}
 		return 1;
 }



  if (strcmp(args[0], "isjpg")==0){
    int fd = open(args[1], O_RDONLY);
    int flag = isjpg(fd);

    if (flag == 1){
      printf("O ficheiro é JPG.\n");
    }else{
      printf("Atenção, o ficheiro não é JPG.\n");
    }
    return 1;
  }
  if (strcmp(args[0], "avisoTeste") == 0)
  {
    aviso(args[1], atoi(args[2]));

    return 1;
  }

if(strcmp(args[0], "isdoc")==0){
    int fd = open(args[1], O_RDONLY);
    int flag = isdoc(fd);
    
    if(flag == 1){
        printf("O ficheiro é DOCX.\n");
    }else{
        printf("O ficheiro nao é DOCX.\n");
}
    return 1;
}

  if (strcmp(args[0], "aviso") == 0)
  {
    pthread_t th;
    aviso_t *ptr = (aviso_t *)malloc(sizeof(aviso_t));
    strcpy(ptr->msg, args[1]);
    ptr->tempo = atoi(args[2]);
    pthread_create(&th, NULL, avisowrapper, (void *)ptr);
    return 1;
  }

  if (strcmp(args[0], "socpth") == 0)
  {
    pthread_t th;
    copiar_t *ptr = (copiar_t *)malloc(sizeof(copiar_t));
    strcpy(ptr->fonte, args[1]);
    strcpy(ptr->destino, args[2]);
    pthread_create(&th, NULL, socpwrapper, (void *)ptr);
    return 1;
  }

  if (0 == strcmp(args[0], "bits") && (numargs == 4 || numargs == 3))
  {
    if (numargs == 4)
      bits(args[1], args[2], args[3]);

    if (numargs == 3)
      bits_not(args[1], args[2]);

    return 1;
  }

  if (0 == strcmp(args[0], "calc") && numargs == 4)
  {
    calc(args[1], args[2], args[3]);
    return 1;
  }
  if (0 == strcmp(args[0], "socp"))
  {
    socp(args[1], args[2]);
    return 1;
  }
  if (0 == strcmp(args[0], "obterinfo"))
  {
    printf("SoShell 2022 versão 1.0\n");
    return 1;
  }
  if (0 == strcmp(args[0], "cd"))
  {
    int err;
    if (NULL == args[1] || (strcmp(args[1], "~")) == 0)
      err = chdir(getenv("HOME"));
    else
      err = chdir(args[1]);

    if (err < 0)
      perror(args[1]);
    return 1;
  }
  if (0 == strcmp(args[0], "quemsoueu"))
  {
    system("id");
    return 1;
  }
  if (strlen(args[0]) > 4 && 0 == strncmp(args[0], "PS1=", 4))
  {
    strcpy(prompt, args[0] + 4);
    return 1;
  }
  if (strcmp(args[0], "sair") == 0)
  {
    exit(0);
    return 1;
  }
  if (strncmp(args[0], "42", 2) == 0)
  {
    printf("42 is the answer to life the universe and everything\n");
    return 1;
  }
  return 0;
}
