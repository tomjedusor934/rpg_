/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** init_variables
*/

#include "../../include/my_rpg.h"

void init_variables(general_t *g)
{
    g->scene = LOADING;
    g->mouse_on = NOTHING;
    g->selected = NOTHING;
    g->gender = WOMEN;
    g->plan = MENU;
    g->surscene = NOTHING;
    g->old_scene = NOTHING;
    g->var_frames = 4;
    g->music = 40.0;
    g->fx = 40.0;
    g->scene = LOADING;
    g->mouse_on = NOTHING;
    g->selected = NOTHING;
    g->gender = WOMEN;
    g->plan = MENU;
    g->f->mobs = NULL;
    g->f->mobs_fight = NULL;
    g->f->spells_file = NULL;
}
