/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** analyse_events
*/

#include "radar.h"
#include "my.h"

void handle_key_pressed(radar_t *radar, sfEvent event)
{
    if (event.key.code == sfKeyEscape)
        sfRenderWindow_close(radar->window);
    if (event.key.code == sfKeyL)
        radar->show_hitbox = 1 - radar->show_hitbox;
    if (event.key.code == sfKeyS)
        radar->show_sprite = 1 - radar->show_sprite;
}

void analyse_events(radar_t *radar, sfEvent event)
{
    if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
        sfRenderWindow_close(radar->window);
    if (event.type == sfEvtKeyPressed) {
        handle_key_pressed(radar, event);
    }
}
