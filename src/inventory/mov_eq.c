/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-romain.bolze
** File description:
** drack_and_drop
*/

#include "../../include/my_rpg.h"

void move_eq2(general_t *g, equip_t *tmp)
{
    int i = 0;
    g->inv->slot->name = tmp->name;
    g->inv->slot->item = tmp->item;
    g->inv->slot->is_empty = 1;
    g->inv->slot->item_type = tmp->item_type;
    g->inv->dad_itemx = g->inv->slot->item->pos.x;
    g->inv->dad_itemy = g->inv->slot->item->pos.y;
    sfSprite_setPosition(g->inv->slot->item->sprite,
    g->inv->slot->slots->pos);
    while (g->inv->dad_eq > i) {
        i++;
        g->inv->equip = g->inv->equip->next;
    }
    g->inv->equip->is_eq = 0;
}

void move_eq3(general_t *g, equip_t *tmp, equip_t *elemen)
{
    int i = 0;
    g->inv->equip->name = tmp->name;
    g->inv->equip->item = tmp->item;
    g->inv->dad_itemx = g->inv->equip->eq->pos.x;
    g->inv->dad_itemy = g->inv->equip->eq->pos.y;
    g->inv->equip->is_eq = 1;
    sfSprite_setPosition(g->inv->equip->item->sprite, g->inv->equip->eq->pos);
    g->inv->equip = elemen;
    while (g->inv->dad_eq > i) {
        i++;
        g->inv->equip = g->inv->equip->next;
    }
    g->inv->equip->is_eq = 0;
}

void move_eq4(general_t *g, equip_t *elemen)
{
    int i = 0;
    g->inv->equip = elemen;
    while (g->inv->dad_eq > i) {
        i++;
        g->inv->equip = g->inv->equip->next;
    }
    g->inv->equip->item->pos.x = g->inv->dad_itemx;
    g->inv->equip->item->pos.y = g->inv->dad_itemy;
    sfSprite_setPosition(g->inv->equip->item->sprite,
    g->inv->equip->item->pos);
}

void move_eq(general_t *g)
{
    slot_t *tmp2 = g->inv->slot;
    equip_t *tmp = g->inv->equip;
    equip_t *elemen = g->inv->equip;
    int i = 0;
    while (g->inv->dad_eq > i) {
        i++;
        tmp = tmp->next;
    }
    if (bouton_inv_item_move(g) == 1) {
       move_eq2(g, tmp);
    } else if (bouton_eq_toinv(g, tmp) == 1) {
       move_eq3(g, tmp, elemen);
    } else {
        move_eq4(g, elemen);
    }
    g->inv->equip = elemen;
    g->inv->equip = elemen;
    g->inv->slot = tmp2;
}
