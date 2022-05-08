/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** player
*/

#include "../../include/my_rpg.h"

void player_turn(general_t *g)
{
    player_move(get_player_pos(g), g, g->player->stat_player->info->pm);
}
