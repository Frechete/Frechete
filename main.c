#include <stdio.h>
#include <stdlib.h>
#define CHARS 40
#define LINES 80

//C a simple pager (similar to the Unix tool “more”, or “less”). 
//Using geany on a Raspberry pi. Gcc: gcc (Raspbian 8.3.0-6+rpi1) 8.3.0

int main() {
    FILE *fptr;

    char filename[100];
    int lines = 0, chars = 0, ch;

    printf("Enter the filename to open \n");
    scanf("%s", filename);

    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Cannot open file \n");
        exit(0);
    }

    while ((ch = fgetc(fptr)) != EOF) {
        // print current character
        putchar(ch);
        chars++;
        if ((ch == '\n') || (chars == CHARS)) {
            lines++;
            chars = 0;
            putchar('\n');
            if (lines == LINES) {
                lines = 0;
                printf("\n--More: Hit Enter to continue --\n");
                getchar();
            }
        }
    }

    fclose(fptr);
    printf("\n End of file \n");
    return 0;
}
