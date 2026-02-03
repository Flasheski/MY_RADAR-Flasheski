/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** move_planes
*/

#define _GNU_SOURCE
#include "radar.h"
#include "my.h"
#include <math.h>

void calculate_direction(plane_t *plane)
{
    float rad = plane->angle * (M_PI / 180.0f);

    plane->direction.x = cos(rad) * plane->speed;
    plane->direction.y = sin(rad) * plane->speed;
}

void move_plane(plane_t *plane, float delta_time)
{
    sfVector2f movement;

    if (plane->is_flying != 1)
        return;
    movement.x = plane->direction.x * delta_time;
    movement.y = plane->direction.y * delta_time;
    plane->current_pos.x += movement.x;
    plane->current_pos.y += movement.y;
    sfSprite_move(plane->sprite, movement);
    sfRectangleShape_move(plane->hitbox, movement);
}
