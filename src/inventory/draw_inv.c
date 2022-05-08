/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** draw_inv
*/

#include "../../include/my_rpg.h"

void draw_inv(general_t *g)
{
    slot_t *tmp = g->inv->slot;
    equip_t *tmp2 = g->inv->equip;
    sfRenderWindow_drawSprite(g->game->window, g->inv->inventaire->sprite,
    NULL);
    while (tmp) {
        sfRenderWindow_drawSprite(g->game->window, tmp->slots->sprite, NULL);
        tmp = tmp->next;
    }
    while (tmp2) {
        if (tmp2->is_eq == 1)
            sfRenderWindow_drawSprite(g->game->window, tmp2->item->sprite,
            NULL);
        tmp2 = tmp2->next;
    }
}

void draw_items(general_t *g)
{
    slot_t *tmp = g->inv->slot;
    while (tmp) {
        if (tmp->is_empty == 1)
            sfRenderWindow_drawSprite(g->game->window, tmp->item->sprite,
            NULL);
        tmp = tmp->next;
    }
}
