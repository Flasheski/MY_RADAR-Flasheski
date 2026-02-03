/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** update_planes
*/

#define _GNU_SOURCE
#include "radar.h"
#include "my.h"
#include <math.h>

int is_plane_arrived(plane_t *plane)
{
    float dx = plane->finish.x - plane->current_pos.x;
    float dy = plane->finish.y - plane->current_pos.y;
    float dist = sqrtf(dx * dx + dy * dy);

    return (dist < 5.0f);
}

void manage_plane_state(plane_t *plane, float delta, float total)
{
    if (plane->is_flying == 0 && total >= plane->delay)
        plane->is_flying = 1;
    if (plane->is_flying != 1)
        return;
    move_plane(plane, delta);
    if (is_plane_arrived(plane))
        plane->is_flying = -1;
}

void update_planes(radar_t *radar, float delta_time, float updated_time)
{
    plane_t *plane = NULL;
    int planes_active = 0;

    update_timer(radar);
    for (int i = 0; i < radar->plane_count; i++) {
        plane = radar->planes[i];
        manage_plane_state(plane, delta_time, updated_time);
        if (plane->is_flying != -1)
            planes_active++;
    }
    check_all_collisions(radar);
    if (planes_active == 0)
        sfRenderWindow_close(radar->window);
}
