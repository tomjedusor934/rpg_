/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** button
*/

#include "../../include/my_rpg.h"

void dad_inv_eq2(general_t *g)
{
    for (float i = 0, x = 0; i < 6; i++, x += 70.5) {
        g->inv->equip->eq->pos.x = g->inv->inventaire->pos.x + 38 + x;
        g->inv->equip->eq->pos.y = g->inv->inventaire->pos.y + 484;
        sfSprite_setPosition(g->inv->equip->eq->sprite,
        g->inv->equip->eq->pos);
        g->inv->equip = g->inv->equip->next;
    }
    g->inv->equip->eq->pos.x = g->inv->inventaire->pos.x + 38;
    g->inv->equip->eq->pos.y = g->inv->inventaire->pos.y + 393;
    sfSprite_setPosition(g->inv->equip->eq->sprite, g->inv->equip->eq->pos);
    g->inv->equip = g->inv->equip->next;
    g->inv->equip->eq->pos.x = g->inv->inventaire->pos.x + 38 + 70.5;
    g->inv->equip->eq->pos.y = g->inv->inventaire->pos.y + 393;
    sfSprite_setPosition(g->inv->equip->eq->sprite, g->inv->equip->eq->pos);
}

void dad_inv_eq(general_t *g)
{
    equip_t *tmp = g->inv->equip;
    int y = 90;
    float x = 424;
    for (int i = 0; i < 4; i++) {
        if (i < 3) {
            g->inv->equip->eq->pos.x = g->inv->inventaire->pos.x + 38;
            g->inv->equip->eq->pos.y = g->inv->inventaire->pos.y + y;
            sfSprite_setPosition(g->inv->equip->eq->sprite,
            g->inv->equip->eq->pos);
            g->inv->equip = g->inv->equip->next;
        }
        g->inv->equip->eq->pos.x = g->inv->inventaire->pos.x + 38 + x;
        g->inv->equip->eq->pos.y = g->inv->inventaire->pos.y + y;
        sfSprite_setPosition(g->inv->equip->eq->sprite,
        g->inv->equip->eq->pos);
        y += 71;
        g->inv->equip = g->inv->equip->next;
    }
    dad_inv_eq2(g);
    g->inv->equip = tmp;
}
