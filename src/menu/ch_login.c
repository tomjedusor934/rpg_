/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** ch_login
*/

#include "../../include/my_rpg.h"

static void ch_gender(general_t *g)
{
    if (g->gender != UNKNOWN && g->selected != NOTHING &&
    is_on_button(g->menu->lock_but, g)) {
        g->scene = LOCKED;
        g->game->file = 4;
        return;
    } if (g->selected != NOTHING &&
    is_on_button(g->menu->logo_female, g)) {
        g->gender = WOMEN;
        return;
    } if (g->selected != NOTHING &&
    is_on_button(g->menu->logo_male, g)) {
        g->gender = MAN;
        return;
    } if (g->selected != NOTHING &&
    is_on_button(g->menu->logo_unidentified, g)) {
        g->gender = UNKNOWN;
        return;
    }
    g->selected = NOTHING;
    g->gender = WOMEN;
}

static void ch_class(general_t *g)
{
    if (is_on_button(g->menu->class_eniripsa, g)) {
        g->selected = ENIRIPSA;
        return;
    } if (is_on_button(g->menu->class_cra, g)) {
        g->selected = CRA;
        return;
    } if (is_on_button(g->menu->class_iop, g)) {
        g->selected = IOP;
        return;
    } if (is_on_button(g->menu->class_sacrieur, g)) {
        g->selected = SACRIEUR;
        return;
    }
    ch_gender(g);
}

static void ch_login(general_t *g)
{
    user_name_and_login(g);
    if (is_on_button(g->menu->connect_but, g)) {
        sfSound_stop(g->menu->s_intro);
        g->scene = GAME;
        return;
    }
    ch_class(g);
}

void ch_login_and_locked(general_t *g)
{
    if (g->scene == LOGIN && g->surscene == NOTHING) {
        ch_login(g);
        return;
    } if (g->scene == LOCKED && g->surscene == NOTHING) {
        if (is_on_button(g->menu->connect_but, g)) {
            g->scene = GAME;
            user_name_and_login(g);
            return;
        }
    }
}
