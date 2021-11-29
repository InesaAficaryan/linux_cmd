
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
int  main(int argc, char* argv[])
{      
        if (argc < 2)
	{
	   printf("ERROR\n");
	   return 1;
        }

        int f = strcmp(argv[1], "-f");
        
        if (f == 0)
        { 
           for (int i = 2; i < argc; ++i)
           {
               int rem = remove(argv[i]);
           
               if ( rem != 0)
               {
                   printf("ERROR\n");
               }
           }
        
        return 0;
       }
       
       for (int i = 1; i < argc; ++i)
       {
           DIR* directory = opendir(argv[i]);
           if (directory != NULL)
           {
               closedir(directory);
               printf("ERROR\n");
           }
           
           int rem = remove(argv[i]);
           if (rem != 0)
           {
              printf("ERROR\n");
           }

       }
       
       return 0;
  }         
              
              
              
              
                  
 
 
