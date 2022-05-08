/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** event_quest
*/

#include "../../include/my_rpg.h"

void manage_quest(general_t *g)
{
    if (g->game->event.type == sfEvtMouseButtonPressed) {
        if (g->inv->is_open == 1) {
            bouton_inv_move(g);
            bouton_inv_eq(g);
            if (g->inv->dad_item == -1)
                bouton_inv_item(g);
        }
        if (g->player->stat_player->quete1 == 1 || g->player->
        stat_player->quete1 == 3 || g->player->stat_player->quete1 == 5)
        change_dialogue(g);
        quete_action(g);
    }
}
