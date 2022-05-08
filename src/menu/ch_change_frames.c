/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** ch_change_frames
*/

#include "../../include/my_rpg.h"

void framerates(general_t *g, char mol)
{
    int frames[] = {30, 60, 90, 120, 144, 244};
    if (mol == '+')
        g->var_frames += 1;
    else
        g->var_frames -= 1;
    sfRenderWindow_setFramerateLimit(g->game->window, frames[g->var_frames]);
}
