/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** game_loop_fight
*/

#include "../../include/my_rpg.h"

void game_loop_fight(general_t *g)
{
    if (g->plan == FIGHT) {
        sfRenderWindow_clear(g->game->window, sfBlack);
        if (g->f->is_fg == 0) {
            find_mob(g, g->f->str);
            g->f->is_fg = 1;
        }
        if (g->f->selected != NULL)
            spell_range(get_player_pos(g), g,
            g->f->selected->max_range, g->f->selected->min_range);
        if (g->f->is_mturn == 0)
            player_turn(g);
        if (g->f->is_mturn == 1) {
            mobs_turn(g);
            g->f->is_mturn = 0;
        }
        reset_the_map(g);
        draw_map(g);
        reset_map(g);
        display_fight(g);
        display_test_fight(g);
    }
}
