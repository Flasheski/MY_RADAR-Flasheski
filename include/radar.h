/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-6
** File description:
** radar
*/

#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Network.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>


#ifndef HUNTER_H_
    #define HUNTER_H_

typedef struct plane_data_s {
    int x_start;
    int y_start;
    int x_end;
    int y_end;
    int speed;
    int delay;
} plane_data_t;

typedef struct tower_data_s {
    int x_pos;
    int y_pos;
    int radius;
} tower_data_t;

typedef struct plane_s {
    sfSprite *sprite;
    sfRectangleShape *hitbox;
    sfVector2f start;
    sfVector2f finish;
    sfVector2f current_pos;
    sfVector2f direction;
    float speed;
    float delay;
    float angle;
    int is_flying;
} plane_t;

typedef struct tower_s {
    sfSprite *sprite;
    sfCircleShape *area;
    sfVector2f position;
    float radius;
} tower_t;

typedef struct radar_s {
    sfRenderWindow *window;
    sfSprite *background;
    sfClock *clock;
    sfClock *timer_clock;
    sfText *timer_txt;
    sfFont *timer_font;
    plane_data_t *planes_raw;
    tower_data_t *towers_raw;
    tower_t **towers;
    plane_t **planes;
    int plane_count;
    int plane_raw_count;
    int tower_raw_count;
    int tower_count;
    int show_hitbox;
    int show_sprite;
    char timer_str[10];
} radar_t;

// Parsing
int parse_plane(radar_t *radar, char **tokens, int len);
int parse_tower(radar_t *radar, char **tokens, int len);
int parse_entity(radar_t *radar, char **tokens, int len);
int parse_script(radar_t *radar, char *filepath);
int extract_data(radar_t *radar, char *line);
// init functions
sfSprite *load_sprite(char *filepath);
plane_t *create_plane(const plane_data_t *data);
tower_t *create_tower(const tower_data_t *data);
int init_entities(radar_t *radar);
// events
void analyse_events(radar_t *radar, sfEvent event);
void display_all(radar_t *radar);
float calculate_angle(const sfVector2f *start, const sfVector2f *finish);
void move_plane(plane_t *plane, float delta_time);
void update_planes(radar_t *radar, float delta_time, float updated_time);
void handle_plane_collision(radar_t *radar, int i, int j);
void check_all_collisions(radar_t *radar);
void init_timer(radar_t *radar);
void update_timer(radar_t *radar);
// destroy functions
void destroy_sprite_and_texture(sfSprite *sprite);
void destroy_planes(plane_t **planes, int count);
void destroy_towers(tower_t **towers, int count);
void destroy_radar(radar_t *radar);
// window
radar_t *open_window(void);
int run_loop(radar_t *radar);

#endif /* !HUNTER_H_ */
