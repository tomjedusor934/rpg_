/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** ch_loaded
*/

#include "../../include/my_rpg.h"

void ch_loaded(general_t *g)
{
    if (g->surscene != SETTINGS) {
        if (is_on_button(g->menu->play_but, g)) {
            g->scene = LOGIN;
            return;
        } if (is_on_button(g->menu->option_but, g)) {
            g->surscene = SETTINGS;
            return;
        } if (is_on_button(g->menu->exit_but, g))
            sfRenderWindow_close(g->game->window);
    }
}
