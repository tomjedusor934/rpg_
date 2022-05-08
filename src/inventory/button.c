/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** button
*/

#include "../../include/my_rpg.h"

void bouton_inv_move(general_t *g)
{
    if (g->inv->dad_inv == 0 && is_on_button_mvinv(g) == 1) {
        g->inv->dad_inv = 1;
        g->inv->dadx = g->game->pos_mouse.x - g->inv->inventaire->pos.x;
        g->inv->dady = g->game->pos_mouse.y - g->inv->inventaire->pos.y;
    }
}

int bouton_inv_toeq(general_t *g, slot_t *item)
{
    while (g->inv->equip) {
        if (g->game->pos_mouse.x > g->inv->equip->eq->pos.x &&
        g->game->pos_mouse.x < g->inv->equip->eq->pos.x + g->inv->equip->eq->
        rect.width * g->inv->equip->eq->scale.x && g->game->pos_mouse.y > g->
        inv->equip->eq->pos.y && g->game->pos_mouse.y < g->inv->equip->eq->
        pos.y + g->inv->equip->eq->rect.height * g->inv->equip->eq->scale.y
        && g->inv->equip->is_eq == 0 && g->inv->equip->item_type ==
        item->item_type) {
            return(1);
        }
        g->inv->equip = g->inv->equip->next;
    }
    return (0);
}

int bouton_eq_toinv(general_t *g, equip_t *item)
{
    while (g->inv->equip) {
        if (g->game->pos_mouse.x > g->inv->equip->eq->pos.x &&
        g->game->pos_mouse.x < g->inv->equip->eq->pos.x + g->inv->equip->eq->
        rect.width * g->inv->equip->eq->scale.x && g->game->pos_mouse.y > g->
        inv->equip->eq->pos.y && g->game->pos_mouse.y < g->inv->equip->eq->
        pos.y + g->inv->equip->eq->rect.height * g->inv->equip->eq->scale.y
        && g->inv->equip->is_eq == 0 && g->inv->equip->item_type ==
        item->item_type) {
            return(1);
        }
        g->inv->equip = g->inv->equip->next;
    }
    return (0);
}

int is_on_button_clinv(general_t *g)
{
    if (g->game->pos_mouse.x > g->inv->inventaire->pos.x + 865 && g->game->
    pos_mouse.x < g->inv->inventaire->pos.x + g->inv->inventaire->rect.width
    * g->inv->inventaire->scale.x - 14) {
        if (g->game->pos_mouse.y > g->inv->inventaire->pos.y + 10 && g->game->
        pos_mouse.y < g->inv->inventaire->pos.y + g->inv->inventaire->
        rect.height * g->inv->inventaire->scale.y - 792) {
            return (1);
        }
    }
    return (0);
}
