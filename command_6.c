// Write a program that takes a file name as a command-line argument (you might start with the program from the previous task) and that prints the last two lines of this file (if there are fewer than two lines, then the program will print what is available; watch the edge cases here).

// This program must use getline to read the lines from the file (on the department servers, and perhaps on your own machine, you will need to add #define _GNU_SOURCE to your source file before #include <stdio.h> to properly include getline). You might also find strdup to be helpful (include #define _GNU_SOURCE before #include <string.h>) and will need to use free to deallocate memory allocated by getline and strdup. You can find information about these functions in the man pages, though you should also ask if the man pages are not clear to you (it can take a while to get used to reading these). Note: your program is not allowed to explictly allocate memory through the use of any of the *alloc functions.

// Your program should report any issues encountered when opening the file and terminate with a meaningful error message.
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    /* ARGUMENT CHECK */
    if (argc != 2) {
        printf("ERROR: expected usage ./task6 <filename> \n");
        return 1;
    }

    FILE *fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("ERROR: could not open file %s\n", argv[1]);
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read_lines;
    char *last_line = NULL;
    char *second_last_line = NULL;

    while ((read_lines = getline(&line, &len, fp)) != -1) {
        free(second_last_line);
        second_last_line = last_line;
        last_line = strdup(line);
    }

    // PRINTING LAST TWO LINES (only if it exists)
    if (second_last_line) {
        printf("%s", second_last_line);
    }
    if (last_line) {
        printf("%s", last_line);
    }

    // FREE UP SPACE AND CLOSE FILES
    free(second_last_line);
    free(last_line);
    free(line);
    fclose(fp);

    return 0;
}