/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** parse_planes
*/

#include "radar.h"
#include "my.h"

int parse_plane(radar_t *radar, char **tokens, int len)
{
    plane_data_t *plane;

    if (len != 7 || tokens[0][0] != 'A')
        return 1;
    plane = &radar->planes_raw[radar->plane_raw_count];
    plane->x_start = my_getnbr(tokens[1]);
    plane->y_start = my_getnbr(tokens[2]);
    plane->x_end = my_getnbr(tokens[3]);
    plane->y_end = my_getnbr(tokens[4]);
    plane->speed = my_getnbr(tokens[5]);
    plane->delay = my_getnbr(tokens[6]);
    radar->plane_raw_count++;
    return 0;
}
