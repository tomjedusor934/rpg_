/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** ch_uname_alogin
*/

#include "../../include/my_rpg.h"

static void connect_mess(general_t *g)
{
    if (is_on_button(g->menu->login_username, g)) {
        reset_rects(g);
        g->menu->login_username->rect.left = 450;
        sfSprite_setTextureRect(g->menu->login_username->sprite, g->menu->login_username->rect);
        g->game->file = 1;
        return;
    } if (is_on_button(g->menu->login_password, g)) {
        reset_rects(g);
        g->menu->login_password->rect.left = 450;
        sfSprite_setTextureRect(g->menu->login_password->sprite, g->menu->login_password->rect);
        g->game->file = 2;
        return;
    } if (is_on_button(g->menu->connect_but, g) == 0 && is_on_button(g->menu->create_but, g) == 0) {
        reset_rects(g);
        g->game->file = 0;
    }
}

void user_name_and_login(general_t *g)
{
    if (is_on_button(g->menu->create_username, g)) {
        reset_rects(g);
        g->menu->create_username->rect.left = 450;
        sfSprite_setTextureRect(g->menu->create_username->sprite, g->menu->create_username->rect);
        g->game->file = 3;
        return;
    } if (is_on_button(g->menu->create_password, g)) {
        reset_rects(g);
        g->menu->create_password->rect.left = 450;
        sfSprite_setTextureRect(g->menu->create_password->sprite, g->menu->create_password->rect);
        g->game->file = 4;
        return;
    }
    connect_mess(g);
}
