/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** parse_script
*/

#include "radar.h"
#include "my.h"

void clean_line_start(char *line)
{
    int i = 0;

    while (line[i] && (line[i] < 32 || line[i] == 127)) {
        i++;
    }
    if (i > 0)
        my_strcpy(line, line + i);
}

void count_entities(char *filepath, radar_t *radar)
{
    FILE *fp = fopen(filepath, "r");
    char *line = NULL;
    size_t len = 0;

    if (!fp)
        return;
    radar->plane_raw_count = 0;
    radar->tower_raw_count = 0;
    while (getline(&line, &len, fp) != -1) {
        if (line[0] == 'A')
            radar->plane_raw_count++;
        if (line[0] == 'T')
            radar->tower_raw_count++;
    }
    free(line);
    fclose(fp);
}

FILE *open_and_alloc_radar(radar_t *radar, char *filepath)
{
    FILE *fp = fopen(filepath, "r");

    if (!fp)
        return NULL;
    radar->planes_raw = malloc(sizeof(plane_data_t) * radar->plane_raw_count);
    radar->towers_raw = malloc(sizeof(tower_data_t) * radar->tower_raw_count);
    if (!radar->planes_raw || !radar->towers_raw) {
        fclose(fp);
        return NULL;
    }
    radar->plane_count = radar->plane_raw_count;
    radar->tower_count = radar->tower_raw_count;
    radar->plane_raw_count = 0;
    radar->tower_raw_count = 0;
    return fp;
}

int read_script_lines(radar_t *radar, FILE *fp)
{
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, fp) != -1) {
        clean_line_start(line);
        if (extract_data(radar, line) == 84) {
            free(line);
            return 84;
        }
    }
    if (line)
        free(line);
    return 0;
}

int parse_script(radar_t *radar, char *filepath)
{
    FILE *fp;
    int ret_cd;

    count_entities(filepath, radar);
    fp = open_and_alloc_radar(radar, filepath);
    if (!fp)
        return 84;
    ret_cd = read_script_lines(radar, fp);
    fclose(fp);
    if (ret_cd == 84)
        return 84;
    radar->plane_raw_count = radar->plane_count;
    radar->tower_raw_count = radar->tower_count;
    return 0;
}
