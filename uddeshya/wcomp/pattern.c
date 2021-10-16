#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"pattern.h"
void pattern(FILE *f, char *word)
{
  char *line,*ch;
  size_t size=0;
  while(f!=EOF)
  {
    getline(&line,&size,f);
    while(line != NULL)
    {
    fscanf(line,"%s",ch);
  
    if(strcmp(*ch,*word)==0)
    {
      printf("%s\n",line);
      break;
    }
    }
      
  }
  return 0;
  
  
}