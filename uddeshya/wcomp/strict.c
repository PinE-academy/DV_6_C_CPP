#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void strict(FILE *f, char *wrd)
{
  char str[100],*ch;
  if(f==NULL)
    exit(0);
  else
  {
  while(f!=EOF)
  {
    fgets(str,100,f);
    fscanf(str,%s,ch);
    if(ch==word)
    {
      printf("%s\n",str);
    }
      
  }
  }
  
}
