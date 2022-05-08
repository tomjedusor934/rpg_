/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** button
*/

#include "../../include/my_rpg.h"

int is_on_button_mvinv(general_t *g)
{
    if (g->game->pos_mouse.x > g->inv->inventaire->pos.x && 
    g->game->pos_mouse.x < g->inv->inventaire->pos.x + g->inv->inventaire->
    rect.width * g->inv->inventaire->scale.x) {
        if (g->game->pos_mouse.y > g->inv->inventaire->pos.y && g->game->
        pos_mouse.y <g->inv->inventaire->pos.y +
        (g->inv->inventaire->rect.height
        *  g->inv->inventaire->scale.y * 0.075)) {
            return (1);
        }
    }
    return (0);
}

void bouton_inv_reset(general_t *g)
{
    g->inv->dad_inv = 0;
    g->inv->dad_item = -1;
    g->inv->dad_eq = -1;
}

int bouton_inv_item(general_t *g)
{
    slot_t *tmp = g->inv->slot;
    int i = 0;
    while (tmp) {
        if (g->game->pos_mouse.x > tmp->slots->pos.x && g->game->pos_mouse.x <
        tmp->slots->pos.x + tmp->slots->rect.width * tmp->slots->scale.x &&
        g->game->pos_mouse.y > tmp->slots->pos.y && g->game->pos_mouse.y <
        tmp->slots->pos.y + tmp->slots->rect.height * tmp->slots->scale.y &&
        tmp->is_empty == 1) {
            g->inv->dad_item = i;
            g->inv->dad_itemx = tmp->slots->pos.x;
            g->inv->dad_itemy = tmp->slots->pos.y;
            return(0);
        }
        i++;
        tmp = tmp->next;
    }
    return (0);
}

int bouton_inv_eq(general_t *g)
{
    equip_t *tmp = g->inv->equip;
    int i = 0;
    while (tmp) {
        if (g->game->pos_mouse.x > tmp->eq->pos.x && g->game->pos_mouse.x <
        tmp->eq->pos.x + tmp->eq->rect.width * tmp->eq->scale.x &&
        g->game->pos_mouse.y > tmp->eq->pos.y && g->game->pos_mouse.y <
        tmp->eq->pos.y + tmp->eq->rect.height * tmp->eq->scale.y && tmp->is_eq
        == 1) {
            g->inv->dad_eq = i;
            g->inv->dad_itemx = tmp->eq->pos.x;
            g->inv->dad_itemy = tmp->eq->pos.y;
            return(0);
        }
        i++;
        tmp = tmp->next;
    }
    return (0);
}

int bouton_inv_item_move(general_t *g)
{
    while (g->inv->slot) {
        if (g->game->pos_mouse.x > g->inv->slot->slots->pos.x &&
        g->game->pos_mouse.x <
        g->inv->slot->slots->pos.x + g->inv->slot->slots->rect.width * 
        g->inv->slot->slots->scale.x &&
        g->game->pos_mouse.y > g->inv->slot->slots->pos.y && 
        g->game->pos_mouse.y <
        g->inv->slot->slots->pos.y + g->inv->slot->slots->rect.height *
        g->inv->slot->slots->scale.y && g->inv->slot->is_empty == 0) {
            return(1);
        }
        g->inv->slot = g->inv->slot->next;
    }
    return (-1);
}
