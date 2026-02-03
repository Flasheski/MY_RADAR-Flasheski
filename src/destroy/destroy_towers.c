/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** destroy_towers
*/

#include "radar.h"
#include "my.h"

void destroy_single_tower(tower_t *tower)
{
    if (!tower)
        return;
    if (tower->sprite)
        destroy_sprite_and_texture(tower->sprite);
    if (tower->area)
        sfCircleShape_destroy(tower->area);
    free(tower);
}

void destroy_towers(tower_t **towers, int count)
{
    if (!towers)
        return;
    for (int i = 0; i < count; i++)
        destroy_single_tower(towers[i]);
    free(towers);
}
