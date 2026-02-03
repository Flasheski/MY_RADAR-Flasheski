/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** init_all
*/

#include "radar.h"
#include "my.h"

void free_entities(radar_t *radar)
{
    free(radar->planes_raw);
    free(radar->towers_raw);
}

int init_entities(radar_t *radar)
{
    radar->plane_count = radar->plane_raw_count;
    radar->tower_count = radar->tower_raw_count;
    radar->planes = malloc(sizeof(plane_t *) * radar->plane_count);
    radar->towers = malloc(sizeof(tower_t *) * radar->tower_count);
    if (!radar->planes || !radar->towers)
        return 84;
    for (int i = 0; i < radar->plane_count; i++) {
        radar->planes[i] = create_plane(&radar->planes_raw[i]);
        if (!radar->planes[i])
            return 84;
    }
    for (int i = 0; i < radar->tower_count; i++) {
        radar->towers[i] = create_tower(&radar->towers_raw[i]);
        if (!radar->towers[i])
            return 84;
    }
    free_entities(radar);
    radar->planes_raw = NULL;
    radar->towers_raw = NULL;
    return 0;
}
