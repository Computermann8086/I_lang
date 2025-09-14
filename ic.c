#include <stdio.h>
#include <stdlib.h>
#include <c:\Users\Compu\OneDrive\Skrivebord\I lang\I_lang\libs\lexer.c>

FILE *fileptr;
char *mptr;

int getfsize(FILE *fpointer);

int main(int argv, char* argc[]) {
    fileptr = fopen(argc[1], "r");
    if (fileptr == NULL){
        perror("Failed to open file:");
    }
    int fsize = getfsize(fileptr);
    if (fsize == -1){
        perror("Failed to get file size");
    }
    mptr = (char *)malloc(sizeof(char)*fsize+1);
    fread(mptr, sizeof(char), fsize, fileptr);
    mptr[fsize] = 0;
    for (int i = 0; i < fsize; i++){
        printf("Byte: %d, Value: %c \n", i, mptr[i]);
    }

    free((void *)mptr);
    return 0;
}


/*
int getfsize(FILE *fpointer) -> Gets the filesize of the file pointed to by fpointer
file must opened with fopen() before usage
*/
int getfsize(FILE *fpointer){
    
    int temp_pos = ftell(fpointer);

    if (ferror(fpointer)){
        return -1;
    }    

    fseek(fpointer, 0, SEEK_END);
    if (ferror(fpointer)){
        return -1;
    }

    int size = ftell(fpointer);
    if (ferror(fpointer)){
        return -1;
    }

    fseek(fpointer, 0, temp_pos);
    if (!ferror(fpointer)){
        return size;
    }

}