/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** my_array_len
*/

#include "my.h"

int my_array_len(char **arr)
{
    int len;

    if (!arr)
        return 0;
    len = 0;
    for (len = 0; arr[len] != NULL; len++);
    return len;
}
