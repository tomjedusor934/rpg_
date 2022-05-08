/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** draw_class
*/

#include "../../include/my_rpg.h"

void class_message(general_t *g)
{
    sfRenderWindow_drawSprite(g->game->window,
    g->menu->class_error_message->sprite, NULL);
}

void class_eniripsa(general_t *g)
{
    g->menu->select->pos.x = g->menu->class_eniripsa->pos.x - 2;
    g->menu->select->pos.y = g->menu->class_eniripsa->pos.y - 2;
    sfSprite_setPosition(g->menu->select->sprite, g->menu->select->pos);
    sfRenderWindow_drawSprite(g->game->window, g->menu->select->sprite, NULL);
    if (g->gender == WOMEN)
        sfRenderWindow_drawSprite(g->game->window,
        g->menu->caractere_female_eniripsa->sprite, NULL);
    if (g->gender == MAN)
        sfRenderWindow_drawSprite(g->game->window,
        g->menu->caractere_male_eniripsa->sprite, NULL);
    if (g->gender == UNKNOWN)
        sfRenderWindow_drawSprite(g->game->window,
        g->menu->caractere_unidentified->sprite, NULL);
    if (g->scene != LOCKED && g->gender != UNKNOWN)
        sfRenderWindow_drawSprite(g->game->window,
        g->menu->lock_but->sprite, NULL);
}

void class_cra(general_t *g)
{
    g->menu->select->pos.x = g->menu->class_cra->pos.x - 2;
    g->menu->select->pos.y = g->menu->class_cra->pos.y - 2;
    sfSprite_setPosition(g->menu->select->sprite, g->menu->select->pos);
    sfRenderWindow_drawSprite(g->game->window, g->menu->select->sprite, NULL);
    if (g->gender == WOMEN)
        sfRenderWindow_drawSprite(g->game->window,
        g->menu->caractere_female_cra->sprite, NULL);
    if (g->gender == MAN)
        sfRenderWindow_drawSprite(g->game->window,
        g->menu->caractere_male_cra->sprite, NULL);
    if (g->gender == UNKNOWN)
        sfRenderWindow_drawSprite(g->game->window,
        g->menu->caractere_unidentified->sprite, NULL);
    if (g->scene != LOCKED && g->gender != UNKNOWN)
        sfRenderWindow_drawSprite(g->game->window,
        g->menu->lock_but->sprite, NULL);
}

void class_sacrieur(general_t *g)
{
    g->menu->select->pos.x = g->menu->class_sacrieur->pos.x - 2;
    g->menu->select->pos.y = g->menu->class_sacrieur->pos.y - 2;
    sfSprite_setPosition(g->menu->select->sprite, g->menu->select->pos);
    sfRenderWindow_drawSprite(g->game->window, g->menu->select->sprite, NULL);
    if (g->gender == WOMEN)
        sfRenderWindow_drawSprite(g->game->window,
        g->menu->caractere_female_sacrieur->sprite, NULL);
    if (g->gender == MAN)
        sfRenderWindow_drawSprite(g->game->window,
        g->menu->caractere_male_sacrieur->sprite, NULL);
    if (g->gender == UNKNOWN)
        sfRenderWindow_drawSprite(g->game->window,
        g->menu->caractere_unidentified->sprite, NULL);
    if (g->scene != LOCKED && g->gender != UNKNOWN)
        sfRenderWindow_drawSprite(g->game->window,
        g->menu->lock_but->sprite, NULL);
}

void class_iop(general_t *g)
{
    g->menu->select->pos.x = g->menu->class_iop->pos.x - 2;
    g->menu->select->pos.y = g->menu->class_iop->pos.y - 2;
    sfSprite_setPosition(g->menu->select->sprite, g->menu->select->pos);
    sfRenderWindow_drawSprite(g->game->window, g->menu->select->sprite, NULL);
    if (g->gender == WOMEN)
        sfRenderWindow_drawSprite(g->game->window,
        g->menu->caractere_female_iop->sprite, NULL);
    if (g->gender == MAN)
        sfRenderWindow_drawSprite(g->game->window,
        g->menu->caractere_male_iop->sprite, NULL);
    if (g->gender == UNKNOWN)
        sfRenderWindow_drawSprite(g->game->window,
        g->menu->caractere_unidentified->sprite, NULL);
    if (g->scene != LOCKED && g->gender != UNKNOWN)
        sfRenderWindow_drawSprite(g->game->window,
        g->menu->lock_but->sprite, NULL);
}
