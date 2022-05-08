/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** the_iisr
*/

#include "../../include/my_rpg.h"

void is_in_spell_rangeb(general_t *g, int range, sfVector2i *pos)
{
    for (int i = 0; i != range; i++) {
        (pos->y - (range - i) >= 0 && pos->y - (range - i) <= 17 && pos->x >= 0
        && pos->x <= 31 ? g->f->map[pos->y - (range - i)][pos->x] = 'U' : 0);
        (pos->y + (range - i) >= 0 && pos->y + (range - i) <= 17 && pos->x >= 0
        && pos->x <= 31 ? g->f->map[pos->y + (range - i)][pos->x] = 'U' : 0);
        for (int a = 0; a != i + 1; a++) {
            (pos->y - a >= 0 && pos->y - a <= 17 && pos->x - (range - i) >= 0
            && pos->x - (range - i) <= 31 ? g->f->map[pos->y - a][pos->x -
            (range - i)] = 'U' : 0);
            (pos->y + a >= 0 && pos->y + a <= 17 && pos->x - (range - i) >= 0
            && pos->x - (range - i) <= 31 ? g->f->map[pos->y + a][pos->x -
            (range - i)] = 'U' : 0);
        }
        (pos->y >= 0 ? g->f->map[pos->y][pos->x + (range - i)] = 'U' : 0);
        is_in_spell_range2(g, range, i);
    }
}

void is_in_spell_rangec(general_t *g, int i, int min_range, sfVector2i *pos)
{
    (pos->y - (min_range - i) >= 0 && pos->y - (min_range - i) <= 17 ?
    g->f->map[pos->y - (min_range - i)][pos->x] = ' ' : 0);
    (pos->y + (min_range - i) >= 0 && pos->y + (min_range - i) <= 17 ?
    g->f->map[pos->y + (min_range - i)][pos->x] = ' ' : 0);
    for (int a = 0; a != i + 1; a++) {
        (pos->y - a >= 0 && pos->y - a <= 17 && pos->x - (min_range - i)
        >= 0 && pos->x - (min_range - i) <= 31 ? g->f->map[pos->y - a]
        [pos->x - (min_range - i)] = ' ' : 0);
        (pos->y + a >= 0 && pos->y + a <= 17 && pos->x - (min_range - i)
        >= 0 && pos->x - (min_range - i) <= 31 ? g->f->map[pos->y + a]
        [pos->x - (min_range - i)] = ' ' : 0);
    }
    (pos->y >= 0 && pos->x + (min_range - i) >= 0 && pos->x +
    (min_range - i) <= 31 ? g->f->map[pos->y]
    [pos->x + (min_range - i)] = ' ' : 0);
}

int is_in_spell_range(general_t *g, sfVector2i mob, int range, int min_range)
{
    sfVector2i *pos = get_player_pos(g);
    is_in_spell_rangeb(g, range, pos);
    for (int i = 0; i != min_range; i++) {
        is_in_spell_rangec(g, i, min_range, pos);
        for (int a = 0; a != i + 1; a++) {
            (pos->y - a >= 0 && pos->y - a <= 17 && pos->x + (min_range - i)
            >= 0 && pos->x + (min_range - i) <= 31 ? g->f->map[pos->y - a]
            [pos->x + (min_range - i)] = ' ' : 0);
            (pos->y + a >= 0 && pos->y + a <= 17 && pos->x + (min_range - i)
            >= 0 && pos->x + (min_range - i) <= 31 ? g->f->map[pos->y + a]
            [pos->x + (min_range - i)] = ' ' : 0);
        }
    }
    if (g->f->map[mob.y][mob.x] == 'U') {
        reset_the_map(g);
        return (1);
    } else {
        reset_the_map(g);
        return (0);
    }
}
