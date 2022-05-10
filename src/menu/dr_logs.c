/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** logs
*/

#include "../../include/my_rpg.h"

void log_one(general_t *g)
{
    sfRenderWindow_drawSprite(g->game->window, g->menu->login_bg->sprite,
    NULL);
    sfRenderWindow_drawSprite(g->game->window, g->menu->connect_but->sprite,
    NULL);
    sfRenderWindow_drawSprite(g->game->window, g->menu->create_but->sprite,
    NULL);
    sfRenderWindow_drawSprite(g->game->window, g->menu->vertical_bar->sprite,
    NULL);
    sfRenderWindow_drawSprite(g->game->window, g->menu->login_message->sprite,
    NULL);
    sfRenderWindow_drawSprite(g->game->window, g->menu->login_username->sprite,
    NULL);
    sfRenderWindow_drawSprite(g->game->window, g->menu->login_password->sprite,
    NULL);
    sfRenderWindow_drawSprite(g->game->window, g->menu->create_message->sprite,
    NULL);
}

void log_two(general_t *g)
{
    sfRenderWindow_drawSprite(g->game->window,
    g->menu->create_username->sprite, NULL);
    sfRenderWindow_drawSprite(g->game->window,
    g->menu->create_password->sprite, NULL);
    sfRenderWindow_drawSprite(g->game->window, g->menu->class_message->sprite,
    NULL);
    sfRenderWindow_drawSprite(g->game->window, g->menu->class_iop->sprite,
    NULL);
    sfRenderWindow_drawSprite(g->game->window, g->menu->class_cra->sprite,
    NULL);
    sfRenderWindow_drawSprite(g->game->window, g->menu->class_sacrieur->sprite,
    NULL);
    sfRenderWindow_drawSprite(g->game->window, g->menu->class_eniripsa->sprite,
    NULL);
    sfRenderWindow_drawSprite(g->game->window,
    g->menu->caractere_plateform->sprite, NULL);
}

void log_three(general_t *g)
{
    sfRenderWindow_drawSprite(g->game->window, g->menu->logo_female->sprite,
    NULL);
    sfRenderWindow_drawSprite(g->game->window, g->menu->logo_male->sprite,
    NULL);
    // sfRenderWindow_drawSprite(g->game->window,
    // g->menu->logo_unidentified->sprite, NULL);
    if (g->error == 1 || g->error == 2)
        sfRenderWindow_drawSprite(g->game->window,
        g->menu->username_error_message->sprite, NULL);
    if (g->error == 2)
        sfRenderWindow_drawSprite(g->game->window,
        g->menu->password_error_message->sprite, NULL);
}
