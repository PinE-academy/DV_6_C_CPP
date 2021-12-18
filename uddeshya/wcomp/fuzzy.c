#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"fuzzy.h"
void fuzzy(FILE *f, char *word)
{
  char *line,ch,wrd[50];
  int l,i;
  wrd[50]=*word;
  l = strlen(wrd);
  size_t size=0;
  while(f!=EOF)
  {
    getline(&line,&size,f);
    while(line != NULL)
    {
    ch=fgetc(line);
    if(ch==wrd[0])
    {
      ch=fgetc(line);
      for(i=1;i<l-1;i++)
      {
        if(ch=="")
        {
          i--;
        }
        else
        {
          if(ch==wrd[i])
          {
            
          }
        }
      }
    }
  
    /*if(strcmp(*ch,*word)==0)
    {
      printf("%s\n",line);
      continue;
    }
    */
    }
      
  }
  return 0;
  
  
}