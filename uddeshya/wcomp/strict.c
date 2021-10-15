#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void strict(FILE *f, char *word)
{
  char *line,*ch;
  size_t size=0;
  while(f!=EOF)
  {
    getline(&line,&size,f);
    fscanf(line,"%s",ch);
  
    if(*ch== *word)
    {
      printf("%s\n",line);
    }
      
  }
  return 0;
  
  
}
