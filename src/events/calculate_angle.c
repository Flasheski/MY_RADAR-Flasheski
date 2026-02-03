/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** calculate_angle
*/

#define _GNU_SOURCE
#include "radar.h"
#include <math.h>

float calculate_angle(const sfVector2f *start, const sfVector2f *finish)
{
    float delta_x = finish->x - start->x;
    float delta_y = finish->y - start->y;
    float rad_angle = atan2(delta_y, delta_x);
    float deg_angle = rad_angle * (180.f / M_PI);

    return deg_angle;
}
