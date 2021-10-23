#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"strict.h"
void strict(FILE *f, char *word)
{
  char *lookup=NULL , *temp = NULL;
  char *line =NULL,*ch;
  int l,line_size,lookup_size;
  
  l=strlen(*word);
  size_t size=0;
  while(f!=EOF)
  {
    getline(&line,&size,f);
    sscanf(line,"%s",ch);
  
    if(strncmp(ch,word,l)==0)
    {
      line_size=strlen(line);
      
      if(lookup==NULL)
      {
        lookup = calloc(line_size,sizeof(char));
        lookup=*line;
        lookup_size=strlen(lookup);
        temp=calloc(lookup_size,sizeof(char));
        *temp= *lookup;
        
      }
      else
      {
       lookup_size=strlen(lookup); 
      temp=realloc(temp,lookup_size*sizeof(int));
      *temp= *lookup;
      lookup=realloc(lookup,(lookup_size+line_size)*sizeof(int));
      lookup=*temp;
      lookup = *line;
      }
      
    }
      
  }
  free(temp);
  return lookup;
  
  
}
