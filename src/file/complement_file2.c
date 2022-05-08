/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** complement_file
*/

#include "../../include/my_rpg.h"

int add_item_to_inv(general_t *g, char *name)
{
    slot_t *tmp = g->inv->slot;
    char *str = NULL;
    while (g->inv->slot && g->inv->slot->is_empty != 0) {
        g->inv->slot = g->inv->slot->next;
    }
    if (g->inv->slot != NULL) {
        str = mstrcpy(str, "asset/");
        str = mstrcat(str, name);
        str = mstrcat(str, ".png");
        g->inv->slot->name = mstrcpy(g->inv->slot->name, name);
        g->inv->slot->item = create_object(str, (sfVector2f)
        {g->inv->slot->slots->pos.x, g->inv->slot->slots->pos.y},
        (sfIntRect) {0, 0, 59, 59}, (sfVector2f) {1, 1});
        g->inv->slot->is_empty = 1;
        g->inv->slot->item_type = verif_equipement(name);
    }
    g->inv->slot = tmp;
    return (0);
}
