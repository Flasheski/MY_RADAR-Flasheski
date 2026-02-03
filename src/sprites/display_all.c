/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** display_sprites
*/

#include "radar.h"
#include "my.h"

void display_towers(radar_t *radar)
{
    tower_t *tower;

    for (int i = 0; i < radar->tower_count; i++) {
        tower = radar->towers[i];
        if (radar->show_hitbox && tower->area)
            sfRenderWindow_drawCircleShape(radar->window, tower->area, NULL);
        if (radar->show_sprite && tower->sprite) {
            sfRenderWindow_drawSprite(radar->window, tower->sprite, NULL);
        }
    }
}

void display_one_plane(radar_t *radar, plane_t *plane)
{
    if (!plane || plane->is_flying != 1)
        return;
    if (radar->show_hitbox && plane->hitbox)
        sfRenderWindow_drawRectangleShape(radar->window, plane->hitbox, NULL);
    if (radar->show_sprite && plane->sprite)
        sfRenderWindow_drawSprite(radar->window, plane->sprite, NULL);
}

void display_planes(radar_t *radar)
{
    plane_t *plane;

    for (int i = 0; i < radar->plane_count; i++) {
        plane = radar->planes[i];
        if (plane != NULL) {
            display_one_plane(radar, plane);
        }
    }
}

void display_all(radar_t *radar)
{
    sfRenderWindow_clear(radar->window, sfBlack);
    if (radar->background)
        sfRenderWindow_drawSprite(radar->window, radar->background, NULL);
    display_towers(radar);
    display_planes(radar);
    if (radar->timer_txt)
        sfRenderWindow_drawText(radar->window, radar->timer_txt, NULL);
    sfRenderWindow_display(radar->window);
}
