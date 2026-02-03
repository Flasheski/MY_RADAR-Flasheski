/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** planes_collision
*/

#include "radar.h"
#include "my.h"
#include <math.h>

int is_colliding(plane_t *plane1, plane_t *plane2)
{
    sfVector2f size_plane1 = sfRectangleShape_getSize(plane1->hitbox);
    sfVector2f size_plane2 = sfRectangleShape_getSize(plane2->hitbox);
    float left_p1 = plane1->current_pos.x;
    float right_p1 = plane1->current_pos.x + size_plane1.x;
    float top_p1 = plane1->current_pos.y;
    float bot_p1 = plane1->current_pos.y + size_plane1.y;
    float left_p2 = plane2->current_pos.x;
    float right_p2 = plane2->current_pos.x + size_plane2.x;
    float top_p2 = plane2->current_pos.y;
    float bot_p2 = plane2->current_pos.y + size_plane2.y;

    if (right_p1 < left_p2 || left_p1 > right_p2 ||
        bot_p1 < top_p2 || top_p1 > bot_p2)
        return 0;
    return 1;
}

int is_protected(plane_t *plane, radar_t *radar)
{
    sfVector2f plane_pos = plane->current_pos;
    sfVector2f size_pos = sfRectangleShape_getSize(plane->hitbox);
    sfVector2f tower_pos;
    float dist_sq;

    plane_pos.x += size_pos.x / 2;
    plane_pos.y += size_pos.y / 2;
    for (int i = 0; i < radar->tower_count; i++) {
        tower_pos = radar->towers[i]->position;
        dist_sq = powf(plane_pos.x - tower_pos.x, 2)
            + powf(plane_pos.y - tower_pos.y, 2);
        if (dist_sq <= powf(radar->towers[i]->radius, 2))
            return 1;
    }
    return 0;
}

void handle_plane_collision(radar_t *radar, int i, int j)
{
    plane_t *plane1 = radar->planes[i];
    plane_t *plane2 = radar->planes[j];

    if (is_protected(plane1, radar) || is_protected(plane2, radar))
        return;
    if (is_colliding(plane1, plane2)) {
        plane1->is_flying = -1;
        plane2->is_flying = -1;
    }
}
