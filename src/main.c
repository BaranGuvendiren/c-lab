// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

#define BUFFER_SIZE 255

int main(void) {
    char input[BUFFER_SIZE];

    while (1) {
        uint8_t input_len = shell_step(input, BUFFER_SIZE);
        if (input_len == 254)
            break;
        if (input_len == 255)
            continue;

        if (strcmp(input, "exit") == 0)
            break;
        if (input[input_len - 1] != ';')
            printf("%s\n", input);
    }

    return 0;
}