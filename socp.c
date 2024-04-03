#include "shell.h"

int BUFFSIZE = 128;


void socp (char *fonte, char *destino)
{

  int fdIn = open (fonte, O_RDONLY);
  
  if (fdIn < 0)
  {
    fprintf (stderr, "Erro! Não foi possível abrir ficheiro!\n");
		return;
	}
	
  int fdOut = creat (destino, S_IRUSR | S_IWUSR);
  if (fdOut < 0)
  {
  	fprintf (stderr, "Erro! Não foi possível criar ficheiro!\n");
  	return;
  }

  ioCopy (fdIn, fdOut);

  fprintf (stderr, "Copia bem sucedida. BlockSize: %d\n", BUFFSIZE);
}

void ioCopy (int IN, int OUT)
{
  int n;
  char *buf = malloc (BUFFSIZE);

  while ((n = read (IN, buf, BUFFSIZE)) > 0)
    {
      if (write (OUT, buf, n) != n)
	perror ("Erro de escrita!\n");
    }

  if (n < 0)
    perror ("Erro de leitura!\n");
}

void *socpwrapper(void *args)
{
	copiar_t *ptr = (copiar_t *)args;
	
	socp(ptr->fonte, ptr->destino);
	
	free(ptr);
	
	return NULL;
}
