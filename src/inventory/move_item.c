/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-romain.bolze
** File description:
** drack_and_drop
*/

#include "../../include/my_rpg.h"

void move_item2(general_t *g, slot_t *tmp, slot_t *elemen)
{
    int i = 0;
    g->inv->slot->name = tmp->name;
    g->inv->slot->item = tmp->item;
    g->inv->slot->item_type = tmp->item_type;
    g->inv->slot->is_empty = 1;
    g->inv->dad_itemx = g->inv->slot->item->pos.x;
    g->inv->dad_itemy = g->inv->slot->item->pos.y;
    sfSprite_setPosition(g->inv->slot->item->sprite,
    g->inv->slot->slots->pos);
    g->inv->slot = elemen;
    while (g->inv->dad_item > i) {
        i++;
        g->inv->slot = g->inv->slot->next;
    }
    g->inv->slot->item_type = 0;
    g->inv->slot->is_empty = 0;
}

void move_item3(general_t *g, slot_t *elemen)
{
    int i = 0;
    g->inv->slot = elemen;
    while (g->inv->dad_item > i) {
        i++;
        g->inv->slot = g->inv->slot->next;
    }
    g->inv->equip->name = g->inv->slot->name;
    g->inv->equip->item = g->inv->slot->item;
    g->inv->equip->is_eq = 1;
    g->inv->slot->is_empty = 0;
    sfSprite_setPosition(g->inv->equip->item->sprite, g->inv->equip->eq->pos);
}

void move_item4(general_t *g, slot_t *elemen)
{
    int i = 0;
    g->inv->slot = elemen;
    while (g->inv->dad_item > i) {
        i++;
        g->inv->slot = g->inv->slot->next;
    }
    g->inv->slot->item->pos.x = g->inv->dad_itemx;
    g->inv->slot->item->pos.y = g->inv->dad_itemy;
    sfSprite_setPosition(g->inv->slot->item->sprite, g->inv->slot->item->pos);
}

void move_item(general_t *g)
{
    equip_t *tmp2 = g->inv->equip;
    slot_t *tmp = g->inv->slot;
    slot_t *elemen = g->inv->slot;
    int i = 0;
    while (g->inv->dad_item > i) {
        i++;
        tmp = tmp->next;
    }
    if (bouton_inv_item_move(g) == 1) {
        move_item2(g, tmp, elemen);
    } else if (bouton_inv_toeq(g, tmp) == 1) {
        move_item3(g, elemen);
    } else {
        move_item4(g, elemen);
    }
    g->inv->equip = tmp2;
    g->inv->slot = elemen;
}
