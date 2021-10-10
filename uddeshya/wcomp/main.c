#include<stdio.h>
#include<string.h>
#include"pattern.h"
#include"strict.h"
#include"fuzzy.h"
void main(int argc , const char argv[])
{
  char *scheme,*word;
  scheme = argv[4];
  word=argv[5];
  FILE *fp;
  fp=fopen("file.txt","r");//confirm file input
  if(scheme == "strict")
  {
    strict(fp,word);
  }
  else
  {
    if(scheme=="pattern")
    {
      pattern(fp,word);
    }
    else
    {
      if(scheme=="fuzzy");
      {
        fuzzy(fp,word);
      }
      else
      {
        printf("Wrong scheme");
      }
    }
    
  }
}
