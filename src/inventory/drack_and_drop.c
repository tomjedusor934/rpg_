/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-romain.bolze
** File description:
** drack_and_drop
*/

#include "../../include/my_rpg.h"

void dad_inv_slot(general_t *g)
{
    slot_t *tmp = g->inv->slot;
    int x = 0;
    int y = 0;
    while (g->inv->slot) {
        g->inv->slot->slots->pos.x = g->inv->inventaire->pos.x + 561 + 60 * x;
        g->inv->slot->slots->pos.y = g->inv->inventaire->pos.y + 134 + 60 * y;
        sfSprite_setPosition(g->inv->slot->slots->sprite,
        g->inv->slot->slots->pos);
        if (x == 4) {
            y++;
            x = -1;
        }
        if (g->inv->slot->is_empty == 1)
            sfSprite_setPosition(g->inv->slot->item->sprite,
            g->inv->slot->slots->pos);
        x++;
        g->inv->slot = g->inv->slot->next;
    }
    g->inv->slot = tmp;
}

void dad_ep_item(general_t *g)
{
    equip_t *tmp = g->inv->equip;
    while (g->inv->equip) {
        if (g->inv->equip->is_eq == 1)
            sfSprite_setPosition(g->inv->equip->item->sprite,
            g->inv->equip->eq->pos);
        g->inv->equip = g->inv->equip->next;
    }
    g->inv->equip = tmp;
}

void drack_and_drop(general_t *g)
{
    g->inv->inventaire->pos.y = g->game->pos_mouse.y - g->inv->dady;
    g->inv->inventaire->pos.x = g->game->pos_mouse.x - g->inv->dadx;
    sfSprite_setPosition(g->inv->inventaire->sprite, (sfVector2f)
    {g->inv->inventaire->pos.x, g->inv->inventaire->pos.y});
    dad_inv_slot(g);
    dad_inv_eq(g);
    dad_ep_item(g);
}

void dad_item(general_t *g)
{
    slot_t *tmp = g->inv->slot;
    int i = 0;
    while (g->inv->dad_item > i) {
        i++;
        g->inv->slot = g->inv->slot->next;
    }
    g->inv->slot->item->pos.x = g->game->pos_mouse.x -
    g->inv->slot->item->rect.height / 2;
    g->inv->slot->item->pos.y = g->game->pos_mouse.y -
    g->inv->slot->item->rect.width / 2;
    sfSprite_setPosition(g->inv->slot->item->sprite,
    g->inv->slot->item->pos);
    g->inv->slot = tmp;
}

void dad_eq(general_t *g)
{
    equip_t *tmp = g->inv->equip;
    int i = 0;
    while (g->inv->dad_eq > i) {
        i++;
        g->inv->equip =  g->inv->equip->next;
    }
    g->inv->equip->item->pos.x = g->game->pos_mouse.x -
    g->inv->equip->item->rect.height / 2;
    g->inv->equip->item->pos.y = g->game->pos_mouse.y -
    g->inv->equip->item->rect.width / 2;
    sfSprite_setPosition(g->inv->equip->item->sprite,
    g->inv->equip->item->pos);
    g->inv->equip = tmp;
}
