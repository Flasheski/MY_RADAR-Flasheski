/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** init_towers
*/

#include "radar.h"
#include "my.h"

int setup_tower_sprite(tower_t *tower)
{
    const float cx = 25.f;
    const float cy = 25.f;

    tower->sprite = load_sprite("assets/sprites/tower.png");
    if (!tower->sprite)
        return 84;
    sfSprite_setPosition(tower->sprite, (sfVector2f){
            tower->position.x - cx,
            tower->position.y - cy
    });
    return 0;
}

int setup_tower_area(tower_t *tower)
{
    const float new_radius = 100.f;

    tower->area = sfCircleShape_create();
    if (!tower->area)
        return 84;
    sfCircleShape_setRadius(tower->area, new_radius);
    tower->radius = new_radius;
    sfCircleShape_setOrigin(tower->area,
        (sfVector2f){tower->radius, tower->radius});
    sfCircleShape_setPosition(tower->area, tower->position);
    sfCircleShape_setFillColor(tower->area, sfTransparent);
    sfCircleShape_setOutlineThickness(tower->area, 2.f);
    sfCircleShape_setOutlineColor(tower->area, sfBlue);
    return 0;
}

tower_t *create_tower(const tower_data_t *data)
{
    tower_t *tower = malloc(sizeof(tower_t));

    if (!tower)
        return NULL;
    tower->position = (sfVector2f){(float)data->x_pos, (float)data->y_pos};
    tower->radius = (float)data->radius;
    tower->sprite = NULL;
    tower->area = NULL;
    if (setup_tower_sprite(tower) == 84) {
        free(tower);
        return NULL;
    }
    if (setup_tower_area(tower) == 84) {
        destroy_sprite_and_texture(tower->sprite);
        free(tower);
        return NULL;
    }
    return tower;
}
