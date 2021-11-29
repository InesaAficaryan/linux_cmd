#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define SBUF 256
#define DBUF 256

    int main(int argc, char *argv[])
    {
      DIR* dir_ptr;     
      struct dirent* direntp;

      if(argc != 3)
      {
        return 1;
       } 

        char src_folder[SBUF];
        char dest_folder[DBUF];
        strcpy(src_folder, argv[1]);
        strcpy(dest_folder, argv[2]);


        dir_ptr = opendir("."); //open directory
        if ( dir_ptr == NULL )
        {
           return 1; 
        }

        while( (direntp = readdir( dir_ptr )) != NULL ) 
        {
            if (  strcmp(direntp->d_name, dest_folder) !=0) //search file or directory
            {
                printf("found the file %s", dest_folder);

                break;
            }else
                printf("not found");
                break;
        }
        rename(src_folder, dest_folder);
        closedir( dir_ptr );

        return 0;
    }
