/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** check_planes
*/

#include "my.h"
#include "radar.h"
#include <math.h>

void check_plane_with_others(radar_t *radar, int i)
{
    for (int j = i + 1; j < radar->plane_count; j++) {
        if (radar->planes[j]->is_flying == 1)
            handle_plane_collision(radar, i, j);
    }
}

void check_all_collisions(radar_t *radar)
{
    for (int i = 0; i < radar->plane_count; i++) {
        if (radar->planes[i]->is_flying == 1)
            check_plane_with_others(radar, i);
    }
}
