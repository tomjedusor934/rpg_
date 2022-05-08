/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** main_menu
*/

#include "../../include/my_rpg.h"

static void on_mm_exit(general_t *g)
{
    if (is_on_button(g->menu->mm_exit, g)) {
        g->menu->mm_exit->rect.left = 283;
        sfSprite_setTextureRect(g->menu->mm_exit->sprite,
        g->menu->mm_exit->rect);
        return;
    }
    g->menu->mm_exit->rect.left = 0;
    sfSprite_setTextureRect(g->menu->mm_exit->sprite,
    g->menu->mm_exit->rect);
}

static void on_mm_resume(general_t *g)
{
    if (is_on_button(g->menu->mm_resume, g)) {
        g->menu->mm_resume->rect.left = 283;
        sfSprite_setTextureRect(g->menu->mm_resume->sprite,
        g->menu->mm_resume->rect);
        return;
    }
    g->menu->mm_resume->rect.left = 0;
    sfSprite_setTextureRect(g->menu->mm_resume->sprite,
    g->menu->mm_resume->rect);
    on_mm_exit(g);
}

static void on_mm_options(general_t *g)
{
    if (is_on_button(g->menu->mm_option, g)) {
        g->menu->mm_option->rect.left = 283;
        sfSprite_setTextureRect(g->menu->mm_option->sprite,
        g->menu->mm_option->rect);
        return;
    }
    g->menu->mm_option->rect.left = 0;
    sfSprite_setTextureRect(g->menu->mm_option->sprite,
    g->menu->mm_option->rect);
    on_mm_resume(g);
}

void on_main(general_t *g)
{
    on_mm_options(g);
}
