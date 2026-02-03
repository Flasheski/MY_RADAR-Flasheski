/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** planes
*/

#include "radar.h"
#include "my.h"

void destroy_one_plane(plane_t *plane)
{
    if (!plane)
        return;
    else {
        destroy_sprite_and_texture(plane->sprite);
        if (plane->hitbox)
            sfRectangleShape_destroy(plane->hitbox);
        free(plane);
    }
}

void destroy_planes(plane_t **planes, int count)
{
    if (!planes)
        return;
    for (int i = 0; i < count; i++)
        destroy_one_plane(planes[i]);
    free(planes);
}
