/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** mouse_on
*/

#include "../../include/my_rpg.h"

static void on_crack(general_t *g)
{
    if (g->mouse_on == CRACK) {
        sfRenderWindow_drawSprite(g->game->window,
        g->menu->sm_crack->sprite, NULL);
    }
}

void mouse_on(general_t *g)
{
    if (g->mouse_on == ENIRIPSA) {
        sfRenderWindow_drawSprite(g->game->window,
        g->menu->carac_eniripsa->sprite, NULL);
        return;
    } if (g->mouse_on == CRA) {
        sfRenderWindow_drawSprite(g->game->window,
        g->menu->carac_cra->sprite, NULL);
        return;
    } if (g->mouse_on == IOP) {
        sfRenderWindow_drawSprite(g->game->window,
        g->menu->carac_iop->sprite, NULL);
        return;
    } if (g->mouse_on == SACRIEUR) {
        sfRenderWindow_drawSprite(g->game->window,
        g->menu->carac_sacrieur->sprite, NULL);
        return;
    }
    on_crack(g);
}
