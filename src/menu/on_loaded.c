/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** loaded
*/

#include "../../include/my_rpg.h"

static void on_options(general_t *g)
{
    if (is_on_button(g->menu->play_but, g)) {
        g->menu->play_but->rect.left = 383;
        sfSprite_setTextureRect(g->menu->play_but->sprite,
        g->menu->play_but->rect);
        return;
    }
    g->menu->play_but->rect.left = 0;
    sfSprite_setTextureRect(g->menu->play_but->sprite,
    g->menu->play_but->rect);
}

static void on_start(general_t *g)
{
    if (is_on_button(g->menu->exit_but, g)) {
        g->menu->exit_but->rect.left = 383;
        sfSprite_setTextureRect(g->menu->exit_but->sprite,
        g->menu->exit_but->rect);
        return;
    }
    g->menu->exit_but->rect.left = 0;
    sfSprite_setTextureRect(g->menu->exit_but->sprite,
    g->menu->exit_but->rect);
    on_options(g);
}

static void on_exitb(general_t *g)
{
    if (is_on_button(g->menu->option_but, g)) {
        g->menu->option_but->rect.left = 383;
        sfSprite_setTextureRect(g->menu->option_but->sprite,
        g->menu->option_but->rect);
        return;
    }
    g->menu->option_but->rect.left = 0;
    sfSprite_setTextureRect(g->menu->option_but->sprite,
    g->menu->option_but->rect);
    on_start(g);
}

static void check_opt_st_exit(general_t *g)
{
    on_exitb(g);
}

void on_loaded(general_t *g)
{
    if (g->surscene == NOTHING)
        check_opt_st_exit(g);
}
