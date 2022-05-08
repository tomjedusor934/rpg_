/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** game_loop_menu
*/

#include "../../include/my_rpg.h"

void game_loop_menu(general_t *g)
{
    if (g->plan == MENU) {
        draw_all(g);
        if (g->file_load == 0) {
            init_map(g);
            g->file_load = 1;
        }
        draw_text(g);
        if (g->connect_ok == 1) {
            g->plan = GAME;
        }
    }
}
