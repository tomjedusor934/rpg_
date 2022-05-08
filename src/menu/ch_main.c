/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** ch_main
*/

#include "../../include/my_rpg.h"

static void ch_exit(general_t *g)
{
    if (is_on_button(g->menu->mm_exit, g))
        sfRenderWindow_close(g->game->window);
    if (!is_on_button(g->menu->main_menu, g))
        g->surscene = NOTHING;
}

static void ch_resume(general_t *g)
{
    if (is_on_button(g->menu->mm_resume, g)) {
        g->surscene = NOTHING;
        return;
    }
    ch_exit(g);
}

static void ch_options(general_t *g)
{
    if (is_on_button(g->menu->mm_option, g)) {
        g->old_scene = MAIN_MENU;
        g->surscene = SETTINGS;
        return;
    }
    ch_resume(g);
}

void ch_main(general_t *g)
{
    if (is_on_button(g->menu->mom_cross, g)) {
        (g->old_scene == NOTHING ? g->surscene = NOTHING :
        g->old_scene == MAIN_MENU ? g->surscene = MAIN_MENU : 0);
        return;
    }
    ch_options(g);
}
