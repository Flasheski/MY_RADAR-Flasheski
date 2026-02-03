/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** sprites
*/

#include "radar.h"
#include "my.h"

sfSprite *load_sprite(char *filepath)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite *sprite;

    if (!texture)
        return NULL;
    sprite = sfSprite_create();
    if (!sprite) {
        sfTexture_destroy(texture);
        return NULL;
    }
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}
