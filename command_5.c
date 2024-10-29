// Within the command_5.c file, write a program that takes command-line arguments and prints to the screen each argument that begins with a '-' character.
#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* ARGUMENT CHECK */
    // printf("argc: %d\n", argc);
    if (argc < 2) {
        printf("ERROR: expected usage ./task5 <text> \n");
        return 1;
    }

    /* FOR LOOP AND PRINT WHERE THERE ARE '=' */
    for (int i = 0; i < argc; i++)
    {
        // printf("i: %d\n", i);
        // printf("argv[i]: %s\n", argv[i]);
        // printf("argv[i][0]: %s\n", argv[i][0]);
        if (argv[i][0] == '-') {
            printf("%s\n", argv[i]);
        }
    }

    return 0;
}
