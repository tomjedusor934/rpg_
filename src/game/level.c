/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** level
*/

#include "../../include/my_rpg.h"

void levelup(general_t *g)
{
    int xp_to_lvup = 30;
    for (int i = g->player->stat_player->level; i > 0; i--)
        xp_to_lvup *= 1.5;
    if (xp_to_lvup <= g->player->stat_player->xp) {
        g->player->stat_player->level++;
        g->player->stat_player->point_caract += 5;
    }
}
