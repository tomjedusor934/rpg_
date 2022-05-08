/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** main
*/

#include "../include/my_rpg.h"

void draw_all(general_t *g)
{
    sfRenderWindow_clear(g->game->window, sfBlack);
    if (g->scene < 6)
        menu(g);
}

int main(void)
{
    general_t *g = malloc(sizeof(general_t));
    malloc_structs(g);
    init_all_struct(g);
    g->player->base_stats = malloc(sizeof(base_stats_t));
    init_variables(g);
    init_mobs(g);
    init_fight(g);
    init_spells(g);
    g->s_clock->animation = sfClock_create();
    g->f->max_pm = 3;
    g->f->max_pa = 7;
    g->f->pm = g->f->max_pm;
    g->f->pa = g->f->max_pa;
    game_loop(g);

    return (0);
}
