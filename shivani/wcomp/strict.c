#include < stdio.h>
#include <stdlib.h>
#include <string.h>
#include " strict.h"
 
char **strict(char *filename , char *word )
{
FILE *file ;
int i =0;
file = fopen(filename,"r");
     if (FILE == NULL)

     printf( "empty database file")
     exit(0);
 }     
int total_lines = countline(filename);    //total no of lines present in file 
char **match_string = malloc(sizeof(char*)*total_lines);

while (!feof(file)) 
{
    char *match = malloc(sizeof(char)*(strlen(word)+1));
    
     fget(match , strlen(word)+1 ,file);
     fseek(file,-strlen(match),SEEK_CUR);

    int character = countcharacter(FILE); //count no. of character 
    if(!strcmp(match,word))
    {
        char *line = malloc(sizeof(char)*(character+1));
}    
     fget(file , character,SEEK_CUR);
     fseek(file,-character+1,file);
     match_string [i]=line;
     i++;
    if(i==no_of_line)
      {
          free(match);
          free(line);
          break;
      }    

      }

      if (i==0)
      {
          return NULL ;
      }
      else{

         return match_string;
      }
       
    int countcharacter(FILE *file)          //for character
    {
        char c;
        int character =0 ;
        while ((c = fgetc(file))! =EOF)
        {
            character ++;
            if(c=='\n' || c == '\0')
            break;
        
            }
    }        
            int countline(char *filename)            //for line 
            {
                FILE *file = fopen(filename , "r")
                if(file == NULL)
                {
                    printf("error")
                    exit(0);
                }
                int linecount= 0;
                char c;
                while ((c = fgetc(file))! =EOF)
                if(c=='\n' || c== '\0')
                linecount ++;
                fclose(file);
                return linecount ;
            }
    

