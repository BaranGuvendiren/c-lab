// shell.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

// stores up to 254 characters from stdin into buffer
// returns stored character length on success, 254 on error and 255 on overflow
uint8_t shell_step(char *buffer, uint8_t buffer_size) {
    while(1) {
        printf(">> ");
        if (fgets(buffer, buffer_size, stdin) == NULL) {
            fprintf(stderr, "Error: Input stream read failed.\n");
            return buffer_size - 1;
        }
        if (buffer[0] == '\n')
            continue;
        break;
    }
    
    uint8_t len = strcspn(buffer, "\n");
    if (buffer[len] != '\n') {
        int16_t c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        fprintf(stderr, "Error: Input too long (max 255 characters).\n");
        return buffer_size;
    }
    buffer[len] = '\0';

    return len;
}