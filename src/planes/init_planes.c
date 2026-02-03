/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** init_planes
*/

#define _GNU_SOURCE
#include "radar.h"
#include "my.h"
#include <math.h>

int setup_plane_sprite(plane_t *plane)
{
    const float cx = 10.f;
    const float cy = 10.f;

    plane->sprite = load_sprite("assets/sprites/plane.png");
    if (!plane->sprite)
        return 84;
    sfSprite_setPosition(plane->sprite, (sfVector2f){
            plane->start.x - cx,
            plane->start.y - cy
    });
    return 0;
}

int setup_plane_hitbox(plane_t *plane)
{
    const float width = 20.f;
    const float height = 20.f;
    const float cx = 10.f;
    const float cy = 10.f;

    plane->hitbox = sfRectangleShape_create();
    if (!plane->hitbox)
        return 84;
    sfRectangleShape_setSize(plane->hitbox,
        (sfVector2f){width, height});
    sfRectangleShape_setPosition(plane->hitbox, (sfVector2f){
            plane->start.x - cx,
            plane->start.y - cy
    });
    sfRectangleShape_setFillColor(plane->hitbox, sfTransparent);
    sfRectangleShape_setOutlineThickness(plane->hitbox, 1.f);
    sfRectangleShape_setOutlineColor(plane->hitbox, sfYellow);
    return 0;
}

void setup_plane_mvmt(plane_t *plane)
{
    float rad = plane->angle * (M_PI / 180.0f);
    sfVector2f render_pos = {plane->current_pos.x - 10.f,
        plane->current_pos.y - 10.f};

    plane->direction.x = cosf(rad) * plane->speed;
    plane->direction.y = sinf(rad) * plane->speed;
    sfSprite_setRotation(plane->sprite, plane->angle);
    sfRectangleShape_setRotation(plane->hitbox, plane->angle);
    sfSprite_setPosition(plane->sprite, render_pos);
    sfRectangleShape_setPosition(plane->hitbox, render_pos);
}

int init_plane_resources(plane_t *plane, const plane_data_t *data)
{
    plane->start = (sfVector2f){(float)data->x_start, (float)data->y_start};
    plane->finish = (sfVector2f){(float)data->x_end, (float)data->y_end};
    plane->speed = (float)data->speed;
    plane->delay = (float)data->delay;
    plane->current_pos.x = (float)data->x_start;
    plane->current_pos.y = (float)data->y_start;
    plane->angle = calculate_angle(&plane->start, &plane->finish);
    plane->is_flying = 0;
    if (setup_plane_sprite(plane) == 84) {
        return 84;
    }
    if (setup_plane_hitbox(plane) == 84) {
        destroy_sprite_and_texture(plane->sprite);
        return 84;
    }
    setup_plane_mvmt(plane);
    return 0;
}

plane_t *create_plane(const plane_data_t *data)
{
    plane_t *plane = malloc(sizeof(plane_t));

    if (!plane)
        return NULL;
    if (init_plane_resources(plane, data) == 84) {
        free(plane);
        return NULL;
    }
    return plane;
}
