/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** get_timer
*/

#include "radar.h"
#include "my.h"

void init_timer(radar_t *radar)
{
    radar->timer_clock = sfClock_create();
    radar->timer_font = sfFont_createFromFile("assets/font/timer.ttf");
    radar->timer_txt = sfText_create();
    sfText_setFont(radar->timer_txt, radar->timer_font);
    sfText_setCharacterSize(radar->timer_txt, 30);
    sfText_setFillColor(radar->timer_txt, sfWhite);
    sfText_setPosition(radar->timer_txt, (sfVector2f){1650, 20});
}

void set_timer_string(radar_t *radar, int mins, int secs)
{
    radar->timer_str[0] = (mins / 10) + '0';
    radar->timer_str[1] = (mins % 10) + '0';
    radar->timer_str[2] = ':';
    radar->timer_str[3] = (secs / 10) + '0';
    radar->timer_str[4] = (secs % 10) + '0';
    radar->timer_str[5] = '\0';
}

void update_timer(radar_t *radar)
{
    sfTime time = sfClock_getElapsedTime(radar->timer_clock);
    int total_seconds = (int)sfTime_asSeconds(time);
    int mins = total_seconds / 60;
    int secs = total_seconds % 60;

    set_timer_string(radar, mins, secs);
    sfText_setString(radar->timer_txt, radar->timer_str);
}
