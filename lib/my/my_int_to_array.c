/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** my_int_to_array
*/

#include "my.h"

int get_nbr_len(int nbr)
{
    int len = 0;

    if (nbr == 0)
        return 1;
    while (nbr > 0) {
        nbr /= 10;
        len++;
    }
    return len;
}

char *my_int_to_array(int nbr)
{
    int len = get_nbr_len(nbr);
    char *str = malloc(sizeof(char) * (len + 1));

    if (!str)
        return NULL;
    str[len] = '\0';
    if (nbr == 0) {
        str[0] = '0';
        return str;
    }
    for (int i = len - 1; i >= 0; i--) {
        str[i] = (nbr % 10) + '0';
        nbr /= 10;
    }
    return str;
}
