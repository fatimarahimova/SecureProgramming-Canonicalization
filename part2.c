#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

void processFile(const char *filename) {
    printf("Process file executes\n");
    FILE *filepointer;
    int c;
    filepointer = fopen(filename, "r");

    if (filepointer == NULL) {
        printf("Could not open the file\n");
        return;
    }

    while ((c = fgetc(filepointer)) != EOF) {
        printf("%c", (char)c);
    }

    fclose(filepointer);
    return;
}

void main(int argc, char *argv[]) {
    const char *protectedfiles[] = {"naivepasswordfile.txt", "naivecreditcarddetails.txt"};
    const char *protectedpasswordfile = realpath ("naivepasswordfile.txt", NULL);
    const char *protectedcardfile = realpath("naivecreditcarddetails.txt", NULL);
    char *fn = argv[1];
    for(int i=0; fn[i] != '\0'; i++){
    //defeating case sensitivity attack
        if(fn[i]>='A' && fn[i]<='Z'){ // if the given input file name consists of uppercase letters
            fn[i]=tolower(fn[i]); // make them lowercase(with the help of tolower function)
        }
        // defeating 8.3 file naming convention attack
        if(fn[i] == '~'){ // if file includes any tilda
            printf("Invalid input!"); // print error message
            return; // do not accept the given invalid error
            
        }
    }

    if (strcmp(realpath(fn, NULL), protectedpasswordfile) != 0 && strcmp(realpath(fn, NULL), protectedcardfile) != 0) {
        processFile(fn);
    }
    else {
        printf("Access to the file specified is not permitted!\n");
        return;
    }

    return;
}