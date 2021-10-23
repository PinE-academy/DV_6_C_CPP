#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"pattern.h"
#include"strict.h"
#include"fuzzy.h"
void main(int argc , const char *argv[])
{
 char *scheme,*word;
  scheme = argv[4];
  word=argv[5];
  
  FILE *fp;
  
  fp=fopen(argv[2],"r");
  if(fp==NULL)
  {
    printf("Error in loding database");
    exit(0);
  }
  else
  {
   if(strlen(argv)>0 && strlen(argv)<7 && argv[0]=="wcomp" && argv[1]== "-f" && argv[3]== "-s")
   {
     if(strcmp(scheme,"strict")==0)
     {
       strict(fp,word);
     }
     
     else
     {
      if(strcmp(scheme,"pattern")==0)
      {
        pattern(fp,word);
      }  
      else
      {
        if(strcmp(scheme,"fuzzy")==0)
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
   
   else
   {
     printf("Wrong Input");
   }
   
   fclose(fp); 
  } 
}