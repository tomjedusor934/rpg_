/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** login_and_locked
*/

#include "../../include/my_rpg.h"

static void on_connect(general_t *g)
{
    if (is_on_button(g->menu->connect_but, g)) {
        g->menu->connect_but->rect.left = 383;
        sfSprite_setTextureRect(g->menu->connect_but->sprite,
        g->menu->connect_but->rect);
        return;
    }
    g->menu->create_but->rect.left = 0;
    sfSprite_setTextureRect(g->menu->create_but->sprite,
    g->menu->create_but->rect);
    if (g->scene != LOCKED)
        on_locked_scene(g);
}

static void on_create(general_t *g)
{
    if (is_on_button(g->menu->create_but, g)) {
        g->menu->create_but->rect.left = 383;
        sfSprite_setTextureRect(g->menu->create_but->sprite,
        g->menu->create_but->rect);
        return;
    }
    g->menu->connect_but->rect.left = 0;
    sfSprite_setTextureRect(g->menu->connect_but->sprite,
    g->menu->connect_but->rect);
    on_connect(g);
}

static void on_lock(general_t *g)
{
    if (is_on_button(g->menu->lock_but, g)) {
        g->menu->lock_but->rect.left = 383;
        sfSprite_setTextureRect(g->menu->lock_but->sprite,
        g->menu->lock_but->rect);
        return;
    }
    g->menu->lock_but->rect.left = 0;
    sfSprite_setTextureRect(g->menu->lock_but->sprite,
    g->menu->lock_but->rect);
    on_create(g);
}

void on_login_and_locked(general_t *g)
{
    on_lock(g);
}
