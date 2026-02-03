/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** parse_towers
*/

#include "radar.h"
#include "my.h"

int parse_tower(radar_t *radar, char **tokens, int len)
{
    tower_data_t *tower;

    if (len != 4 || tokens[0][0] != 'T')
        return 1;
    tower = &radar->towers_raw[radar->tower_raw_count];
    tower->x_pos = my_getnbr(tokens[1]);
    tower->y_pos = my_getnbr(tokens[2]);
    tower->radius = my_getnbr(tokens[3]);
    radar->tower_raw_count++;
    return 0;
}
