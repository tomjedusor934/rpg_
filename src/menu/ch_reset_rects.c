/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** reset_rects
*/

#include "../../include/my_rpg.h"

static void connect_username(general_t *g)
{
    if (g->game->login != NULL) {
        if (my_strlen(g->game->login) != 0) {
            g->menu->login_username->rect.left = 450;
            sfSprite_setTextureRect(g->menu->login_username->sprite,
            g->menu->login_username->rect);
            return;
        }
    }
    g->menu->login_username->rect.left = 0;
    sfSprite_setTextureRect(g->menu->login_username->sprite,
    g->menu->login_username->rect);
}

static void connect_password(general_t *g)
{
    if (g->game->pasword_login != NULL) {
        if (my_strlen(g->game->pasword_login) != 0) {
            g->menu->login_password->rect.left = 450;
            sfSprite_setTextureRect(g->menu->login_password->sprite,
            g->menu->login_password->rect);
            return;
        }
    }
    g->menu->login_password->rect.left = 0;
    sfSprite_setTextureRect(g->menu->login_password->sprite,
    g->menu->login_password->rect);
    connect_username(g);
}

static void create_username(general_t *g)
{
    if (g->game->user_name != NULL) {
        if (my_strlen(g->game->user_name) != 0) {
            g->menu->create_username->rect.left = 450;
            sfSprite_setTextureRect(g->menu->create_username->sprite,
            g->menu->create_username->rect);
            return;
        }
    }
    g->menu->create_username->rect.left = 0;
    sfSprite_setTextureRect(g->menu->create_username->sprite,
    g->menu->create_username->rect);
    connect_password(g);
}

void reset_rects(general_t *g)
{
    if (g->game->new_pasword != NULL) {
        if (my_strlen(g->game->new_pasword) != 0) {
            g->menu->create_password->rect.left = 450;
            sfSprite_setTextureRect(g->menu->create_password->sprite,
            g->menu->create_password->rect);
            return;
        }
    }
    g->menu->create_password->rect.left = 0;
    sfSprite_setTextureRect(g->menu->create_password->sprite,
    g->menu->create_password->rect);
    create_username(g);
}
