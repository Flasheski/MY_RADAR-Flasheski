/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** parse_entities
*/

#include "radar.h"
#include "my.h"

int parse_entity(radar_t *radar, char **tokens, int len)
{
    if (len == 0)
        return 0;
    if (parse_plane(radar, tokens, len) == 0)
        return 0;
    if (parse_tower(radar, tokens, len) == 0)
        return 0;
    return 84;
}
