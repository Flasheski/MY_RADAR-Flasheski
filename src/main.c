/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** main
*/

#include "radar.h"
#include "my.h"

void print_h(void)
{
    my_putstr("Air traffic simulation panel\n");
    my_putstr("USAGE\n");
    my_putstr("  ./my_radar [OPTIONS] path_to_script\n");
    my_putstr("    path_to_script    The path to the script file.\n");
    my_putstr("OPTIONS\n");
    my_putstr("  -h\t\t    print the usage and quit.\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("  'L' key\t enable/disable hitboxes and areas.\n");
    my_putstr("  'S' key\t enable/disable sprites.\n");
}

int handle_args(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        print_h();
        return 1;
    }
    if (argc != 2) {
        my_puterror("./my_radar: bad arguments: 0 given but 1 is required\n");
        my_puterror("retry with -h\n");
        return 84;
    }
    return 0;
}

int main(int argc, char **argv)
{
    radar_t *radar = NULL;
    int idx = 0;

    idx = handle_args(argc, argv);
    if (idx != 0)
        return (idx == 84) ? 84 : 0;
    radar = open_window();
    if (!radar)
        return 84;
    if (parse_script(radar, argv[1]) != 0) {
        destroy_radar(radar);
        return 84;
    }
    if (init_entities(radar) != 0) {
        destroy_radar(radar);
        return 84;
    }
    idx = run_loop(radar);
    destroy_radar(radar);
    return idx;
}
