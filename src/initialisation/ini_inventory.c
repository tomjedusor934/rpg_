/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** ini_inventory
*/

#include "../../include/my_rpg.h"

void slot(general_t *g)
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

void init_slot(general_t *g)
{
    int x = 0;
    int y = 0;
    for (int i = 0; i < 50; i++) {
        add_slot(g, 0, x, y);
        if (x == 4) {
            y++;
            x = -1;
        }
        x++;
    }
    slot(g);
}

void init_eq(general_t *g)
{
    float x = 0;
    int y = 393;
    add_sloteq(g, 0, 9, x + 70.5, y), add_sloteq(g, 0, 8, x, y);
    y += 91;
    for (int i = 0; i < 6; i++) {
        add_sloteq(g, 0, 10, x, y);
        x += 70.5;
    }
    y = 303;
    for (int i = 0, item_type = 7; i < 4; i++, item_type--) {
        x = 424;
        add_sloteq(g, 0, item_type, x, y);
        x = 0;
        if (y != 303) {
            item_type--;
            if (item_type == 5) add_sloteq(g, 0, 3, x, y);
            else
                add_sloteq(g, 0, item_type ,x, y);
        }
        y -= 71;
    }
}

void init_caract(general_t *g)
{
    g->inv->invcarac = create_object("asset/caract.png", (sfVector2f)
    {g->player->cam_posx + 800, g->pos_player_y - 450}, (sfIntRect)
    {0, 0, 327, 510}, (sfVector2f) {1, 1});
    for (int i = 0; i <  6; i++)
        g->inv->bouton[i] = create_object("asset/bouton_caract.png",
        (sfVector2f) {g->inv->invcarac->pos.x + 350,
        g->inv->invcarac->pos.y + 195}, (sfIntRect)
        {0, 0, 24, 24}, (sfVector2f) {1, 1});
    g->inv->bouton[6] = create_object("asset/close_bouton.png",
    (sfVector2f) {g->inv->invcarac->pos.x + 310, g->inv->invcarac->pos.y + 50},
    (sfIntRect) {0, 0, 24, 24}, (sfVector2f) {1, 1});
    g->inv->bouton[7] = NULL;
}


void init_inventory(general_t *g)
{
    g->inv = malloc(sizeof(inventaire_t));
    g->inv->inventaire = create_object("asset/inventory.png",
    (sfVector2f) {g->pos_playe_x - 450, g->pos_player_y - 450},
    (sfIntRect) {0, 0, 750, 698}, (sfVector2f) {1.2, 1.2});
    g->inv->text_caract = sfText_create();
    g->inv->font_caract = sfFont_createFromFile("text/police.ttf");
    g->inv->dad_inv = 0;
    g->inv->dady = 0;
    g->inv->dadx = 0;
    g->inv->is_open = 0;
    g->inv->caract_open = 0;
    g->inv->dad_itemx = 0;
    g->inv->dad_itemy = 0;
    g->inv->dad_item = -1;
    g->inv->dad_eq = -1;
    g->inv->slot = NULL;
    g->inv->equip = NULL;
    init_slot(g);
    init_eq(g);
    init_caract(g);
}
