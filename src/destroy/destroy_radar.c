/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** destroy_radar
*/

#include "radar.h"
#include "my.h"

void destroy_radar(radar_t *radar)
{
    if (!radar)
        return;
    destroy_planes(radar->planes, radar->plane_count);
    destroy_towers(radar->towers, radar->tower_count);
    if (radar->planes_raw)
        free(radar->planes_raw);
    if (radar->towers_raw)
        free(radar->towers_raw);
    if (radar->background)
        destroy_sprite_and_texture(radar->background);
    if (radar->clock)
        sfClock_destroy(radar->clock);
    if (radar->window)
        sfRenderWindow_destroy(radar->window);
    sfClock_destroy(radar->timer_clock);
    sfText_destroy(radar->timer_txt);
    sfFont_destroy(radar->timer_font);
    free(radar);
}
