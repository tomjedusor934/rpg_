/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** ch_all_events
*/

#include "../../include/my_rpg.h"

void check_events(general_t *g)
{
    if (g->game->event.type == sfEvtClosed)
        sfRenderWindow_close(g->game->window);
    key_open_mm(g);
    if (g->plan == MENU) {
        (g->scene == LOADED ? on_loaded(g) :
        g->scene == LOGIN || g->scene == LOCKED ? on_login_and_locked(g) : 0);
    }
    (g->surscene == SETTINGS ? on_settings(g) :
    g->surscene == MAIN_MENU ? on_main(g) : 0);
    if (g->game->event.type == sfEvtMouseButtonReleased) {
        if (g->plan == MENU) {
            (g->scene == LOADED ? ch_loaded(g) :
            g->scene == LOGIN || g->scene == LOCKED ?
            ch_login_and_locked(g) : 0);
        }
        (g->surscene == SETTINGS ? ch_settings(g) :
        g->surscene == MAIN_MENU ? ch_main(g) : 0);
    }
}
