/*
** EPITECH PROJECT, 2022
** B-CPE-200-NCY-2-1-lemin-romain.bolze
** File description:
** put_in_list
*/

#include "../../include/my_rpg.h"

void add_slot(general_t *g, int empty, int x, int y)
{
    slot_t *element = malloc(sizeof(slot_t));
    element->is_empty = empty;
    element->slots = create_object("asset/slot_inventory.png", (sfVector2f)
    {1070 + 60 * x, 255 + 60 * y}, (sfIntRect) {0, 0, 59, 59}, (sfVector2f)
    {1, 1});
    element->item = malloc(sizeof(game_object_t));
    element->item_type = 0;
    element->name = NULL;
    element->next = g->inv->slot;
    g->inv->slot = element;
}

void add_sloteq(general_t *g, int empty, int item_type, float x, int y)
{
    equip_t *element = malloc(sizeof(equip_t));
    element->is_eq = empty;
    element->item_type = item_type;
    element->eq = create_object("asset/slot_eq.png", (sfVector2f)
    {g->inv->inventaire->pos.x + x + 38, g->inv->inventaire->pos.y + y},
    (sfIntRect) {0, 0, 52, 52}, (sfVector2f) {1.2, 1.2});
    element->item = malloc(sizeof(game_object_t));
    element->next = g->inv->equip;
    g->inv->equip = element;
}
