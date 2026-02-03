/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** open_window
*/

#include "radar.h"
#include "my.h"

radar_t *alloc_struct(void)
{
    radar_t *radar = malloc(sizeof(radar_t));

    if (!radar)
        return NULL;
    radar->window = NULL;
    radar->clock = NULL;
    radar->background = NULL;
    radar->planes_raw = NULL;
    radar->towers_raw = NULL;
    radar->planes = NULL;
    radar->towers = NULL;
    radar->plane_raw_count = 0;
    radar->tower_raw_count = 0;
    radar->plane_count = 0;
    radar->tower_count = 0;
    radar->show_hitbox = 1;
    radar->show_sprite = 1;
    return radar;
}

radar_t *open_window(void)
{
    radar_t *radar;
    sfVideoMode mode = {1920, 1080, 32};

    radar = alloc_struct();
    if (!radar)
        return NULL;
    radar->window = sfRenderWindow_create(mode, "MY RADAR",
        sfResize | sfClose, NULL);
    if (!radar->window) {
        free(radar);
        return NULL;
    }
    init_timer(radar);
    radar->clock = sfClock_create();
    radar->background = load_sprite("assets/sprites/world_map.png");
    sfRenderWindow_setFramerateLimit(radar->window, 60);
    return radar;
}
