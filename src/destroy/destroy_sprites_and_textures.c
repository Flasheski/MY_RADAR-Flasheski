/*
** EPITECH PROJECT, 2025
** MUL
** File description:
** destroy
*/

#include "radar.h"
#include "my.h"

void destroy_sprite_and_texture(sfSprite *sprite)
{
    const sfTexture *texture = sfSprite_getTexture(sprite);

    if (!sprite)
        return;
    sfSprite_destroy(sprite);
    if (texture)
        sfTexture_destroy((sfTexture *)texture);
}
