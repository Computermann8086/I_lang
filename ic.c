#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "libs\lexer.c"

FILE *fileptr;
char *mptr = NULL;
long fsize;
const char *smptr;

const char sampletoken[6] = " if  \0";
const char *sampleptr = &sampletoken[0];
Token rettoken;

long getfsize(FILE *fpointer);

int main(int argv, char* argc[]) {
    fileptr = fopen(argc[1], "r");
    if (fileptr == NULL){
        if (errno = EINVAL){
            printf("Fatal: No file specified");
        }
    }

    fsize = getfsize(fileptr);
    if (fsize == -1){
        ;
    } 


    mptr = (char *)malloc(sizeof(char)*fsize+1);
    fread(mptr, sizeof(char), fsize, fileptr);
    mptr[fsize] = '\0';
    smptr = &mptr[0];

    //for (int i = 0; i < fsize; i++){
    //    printf("Byte: %d, Value: %c \n", i, mptr[i]);
    //}

    int nfound = 0;

    for (int i = 0; nfound != 1; i++){
        tokenize(&smptr);
    }
    rettoken = tokenize(&smptr);
    printf("token.value: ");
    puts((char *)rettoken.value);

    free((void *)mptr);
    mptr = NULL;
    if (fsize != -1){
        fclose(fileptr);
    }
    return 0;
}



/*
int getfsize(FILE *fpointer) -> Gets the filesize of the file pointed to by fpointer
file must opened with fopen() before usage
*/
long getfsize(FILE *fpointer){
    
    long temp_pos = ftell(fpointer);

    if (ferror(fpointer)){
        return -1;
    }    

    fseek(fpointer, 0, SEEK_END);
    if (ferror(fpointer)){
        return -1;
    }

    long size = ftell(fpointer);
    if (ferror(fpointer)){
        return -1;
    }

    fseek(fpointer, 0, temp_pos);
    if (!ferror(fpointer)){
        return size;
    }

}