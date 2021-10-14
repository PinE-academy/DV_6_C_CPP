#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void strict(FILE *f, char wrd)
{
  char str[100],*ch;
  while(f!=EOF)
  {
    getline();
  
    if(*ch== *wrd)
    {
      printf("%s\n",str);
    }
      
  }
  
  
}
