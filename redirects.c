#include "shell.h"
#define FILE_MODE ( S_IRUSR | S_IWUSR )


int redirects (int numargs, char *args[])
{

  if (numargs < 3)
    return numargs;

  if (strcmp (args[numargs - 2], ">") == 0)
    {

      int fd = creat (args[numargs - 1], FILE_MODE);
      if (fd < 0)
	{
	  perror (NULL);
	  return -1;
	}

      dup2 (fd, STDOUT_FILENO);
      close (fd);
      args[numargs - 2] = NULL;
      numargs = numargs - 2;
    }

  if (strcmp (args[numargs - 2], ">>") == 0)
    {

      int fd = open (args[numargs - 1], O_WRONLY | O_APPEND | O_CREAT, FILE_MODE);
      if (fd < 0)
	{
	  perror (NULL);
	  return -1;
	}

      dup2 (fd, STDOUT_FILENO);
      close (fd);
      args[numargs - 2] = NULL;
      numargs = numargs - 2;
    }

  if (strcmp (args[numargs - 2], "<") == 0)
    {

      int fd = open (args[numargs - 1], O_RDONLY, FILE_MODE);
      if (fd < 0)
	{
	  perror ("Ficheiro não existe!");
	  return -1;
	}

      dup2 (fd, STDIN_FILENO);
      close (fd);
      args[numargs - 2] = NULL;
      numargs = numargs - 2;
    }

		if (strcmp(args[numargs -2], "2>") == 0)
			{
			
			int fd = open (args[numargs - 1], O_WRONLY | O_APPEND | O_CREAT, FILE_MODE);
			if (fd < 0)
			{
	  		perror (NULL);
	  		return -1;
			}
			
			dup2 (fd, STDERR_FILENO);
      close (fd);
      args[numargs - 2] = NULL;
      numargs = numargs - 2;
		}

  return numargs;
}
