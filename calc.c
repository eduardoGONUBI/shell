#include "shell.h"

void calc (char *v1, char *operation, char *v2)
{

  if (strcmp (operation, "+") == 0)
    printf ("%f\n", (atof (v1) + atof (v2)));

  if (strcmp (operation, "-") == 0)
    printf ("%f\n", (atof (v1) - atof (v2)));

  if (strcmp (operation, "*") == 0)
    printf ("%f\n", (atof (v1) * atof (v2)));

  if (strcmp (operation, "/") == 0)
    printf ("%f\n", (atof (v1) / atof (v2)));

  if (strcmp (operation, "^") == 0)
    printf ("%f\n", powf (atof (v1), atof (v2)));
}

void bits (char *v1, char *operation, char *v2)
{
	
	if (strcmp (operation, "&") == 0)
    printf ("%d\n", (atoi (v1) & atoi (v2)));
    
  if (strcmp (operation, "^") == 0)
    printf ("%d\n", (atoi (v1) ^ atoi (v2)));
    
  if (strcmp (operation, "|") == 0)
    printf ("%d\n", (atoi (v1) | atoi (v2)));
    
  if (strcmp (operation, ">>") == 0)
    printf ("%d\n", (atoi (v1) >> atoi (v2)));
    
  if (strcmp (operation, "<<") == 0)
    printf ("%d\n", (atoi (v1) << atoi (v2)));

}

void bits_not(char *operation, char *valor)
{
	
	if (strcmp (operation, "~") == 0)
    printf ("%d\n", ~(atoi(valor)));
}

int isjpg(int fileDescriptor) 
{
	unsigned char b[4];
	
	read(fileDescriptor,b,4);
 	lseek(fileDescriptor,0,SEEK_SET);
	
	if ( b[0]==0xff && b[1]==0xd8 && b[2]==0xff && b[3]==0xe0)
 		return 1;
	
	return 0;
}
