-#include<stdio.h>
#include <string.h>
#include "fuzzy.h"
#include "strict.h"
#include "pattern.h" 
 
 int main(int argc,int *argv[])

 if (argc>1 &&argc<7)
 {
     if (((strmp (argv[2]=="-f")))&& ((strmp (argv[4]=="-s"))))
     {
         char *filename =argv[3];
         char*word = argv[6];

     if(argv[5]=="strict")

      strict(filename,word);         //calling of strict function 

    else if(argv[5]=="pattern")
      
       pattern(filename,word);       //calling of pattern function

    else if(argv[5]=="fuzzy")
       
       fuzzy(filename,word);         //calling of fuzzy function 
    else 

        printf( "error,this schema is not defined %s ",argv[5]);
    
     }

 }