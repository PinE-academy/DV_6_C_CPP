#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void strict(FILE *f, char *word)
{
  char str[100],*ch;
  while(f!=EOF)
  {
    getline();
  
    if(*ch== *word)
    {
      printf("%s\n",str);
    }
      
  }
  
  
}
