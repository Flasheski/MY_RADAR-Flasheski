/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** loop_window
*/

#include "radar.h"
#include "my.h"

int run_loop(radar_t *radar)
{
    sfEvent event;
    sfClock *clock = sfClock_create();
    sfClock *global_clock = sfClock_create();
    float delta_time = 0;
    float total_time = 0;

    while (sfRenderWindow_isOpen(radar->window)) {
        delta_time = sfTime_asSeconds(sfClock_restart(clock));
        total_time = sfTime_asSeconds(sfClock_getElapsedTime(global_clock));
        while (sfRenderWindow_pollEvent(radar->window, &event))
            analyse_events(radar, event);
        update_planes(radar, delta_time, total_time);
        display_all(radar);
    }
    return 0;
}
