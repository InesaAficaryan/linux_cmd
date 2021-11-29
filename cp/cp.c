#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
int main(int argc, char** argv)
{
if(argc != 3)
{
printf("ERROR");
return 1;

}
    FILE *fp1, *fp2;
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "w");
    if (!fp1){
        printf("ERROR\n");
        return 1;
        }
    
    if (fp2)
    {
       char c;
       while ((c = fgetc(fp1)) != EOF)
       {
             fputc(c, fp2);
       }
     }
     fclose(fp1);
     fclose(fp2);        

    return 0;
    }
