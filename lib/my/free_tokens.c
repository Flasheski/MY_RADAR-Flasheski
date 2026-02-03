/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** free_tokens
*/

#include "my.h"

void free_tokens(char **tokens, int count)
{
    if (!tokens)
        return;
    for (int i = 0; i < count; i++) {
        if (tokens[i]) {
            free(tokens[i]);
            tokens[i] = NULL;
        }
    }
    free(tokens);
}
