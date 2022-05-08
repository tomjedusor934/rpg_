/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** ch_open_menu
*/

#include "../../include/my_rpg.h"

void key_open_mm(general_t *g)
{
    if (g->game->event.type == sfEvtKeyReleased &&
    g->game->event.key.code == sfKeyEscape) {
        if (g->surscene == NOTHING) {
            (g->scene < LOGIN ? g->surscene = SETTINGS :
            g->scene >= LOGIN ? g->surscene = MAIN_MENU : 0);
            return;
        } else {
            (g->old_scene == NOTHING ? g->surscene = NOTHING :
            g->old_scene == MAIN_MENU ? g->surscene = MAIN_MENU : 0);
            return;
        }
    }
}
