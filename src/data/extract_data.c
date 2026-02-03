/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** extract_data
*/

#include "my.h"
#include "radar.h"

int extract_data(radar_t *radar, char *line)
{
    char **tokens;
    int len;
    int ret_cd;

    tokens = my_split(line, ' ');
    if (!tokens)
        return 84;
    len = my_array_len(tokens);
    ret_cd = parse_entity(radar, tokens, len);
    free_tokens(tokens, len);
    return ret_cd;
}
