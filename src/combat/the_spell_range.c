/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** the_spell_range
*/

#include "../../include/my_rpg.h"

void spell_rangeb(sfVector2i *pos, general_t *g, int range, int i)
{
    for (int a = 0; a != i + 1; a++) {
        (pos->y - a >= 0 && pos->y - a <= 17 && pos->x - (range - i) >= 0
        && pos->x - (range - i) <= 31 && g->f->map[pos->y -
        a][pos->x - (range - i)] != 'M' ? g->f->map[pos->y - a][pos->x -
        (range - i)] = 'U' : 0);
        (pos->y + a >= 0 && pos->y + a <= 17 && pos->x - (range - i) >= 0
        && pos->x - (range - i) <= 31 && g->f->map[pos->y +
        a][pos->x - (range - i)] != 'M' ? g->f->map[pos->y + a][pos->x -
        (range - i)] = 'U' : 0);
    }
}

void spell_rangec(sfVector2i *pos, general_t *g, int range)
{
    for (int i = 0; i != range; i++) {
        (pos->y - (range - i) >= 0 && pos->y - (range - i) <= 17 &&
        pos->x >= 0 && pos->x <= 31 && g->f->map[pos->y - (range - i)][pos->x]
        != 'M' ? g->f->map[pos->y - (range - i)][pos->x] = 'U' : 0);
        (pos->y + (range - i) >= 0 && pos->y + (range - i) <= 17 &&
        pos->x >= 0 && pos->x <= 31 && g->f->map[pos->y + (range -
        i)][pos->x] != 'M' ?
        g->f->map[pos->y + (range - i)][pos->x] = 'U' : 0);
        spell_rangeb(pos, g, range, i);
        (pos->y >= 0 && pos->x + (range - i) >= 0 &&
        pos->x - (range - i) <= 31 && g->f->map[pos->y][pos->x +
        (range - i)] != 'M' ?
        g->f->map[pos->y][pos->x + (range - i)] = 'U' : 0);
        spell_range2(g, range, i);
    }
}

void spell_ranged(sfVector2i *pos, general_t *g, int min_range, int i)
{
    (pos->y - (min_range - i) >= 0 && pos->y - (min_range - i) <= 17 &&
    pos->x >= 0 && pos->x <= 31 && g->f->map[pos->y - (min_range - i)]
    [pos->x] != 'M' ? g->f->map[pos->y - (min_range - i)]
    [pos->x] = ' ' : 0);
    (pos->y + (min_range - i) >= 0 && pos->y + (min_range - i) <= 17 &&
    pos->x >= 0 && pos->x <= 31 && g->f->map[pos->y + (min_range - i)]
    [pos->x] != 'M' ? g->f->map[pos->y + (min_range - i)]
    [pos->x] = ' ' : 0);
    for (int a = 0; a != i + 1; a++) {
        (pos->y - a >= 0 && pos->y - a <= 17 && pos->x - (min_range - i)
        >= 0 && pos->x - (min_range - i) <= 31 && g->f->map[pos->y - a]
        [pos->x - (min_range - i)] != 'M' ? g->f->map[pos->y - a]
        [pos->x - (min_range - i)] = ' ' : 0);
        (pos->y + a >= 0 && pos->y + a <= 17 && pos->x - (min_range - i)
        >= 0 && pos->x - (min_range - i) <= 31 && g->f->map[pos->y + a]
        [pos->x - (min_range - i)] != 'M' ? g->f->map[pos->y + a]
        [pos->x - (min_range - i)] = ' ' : 0);
    }
}

void spell_range(sfVector2i *pos, general_t *g, int range, int min_range)
{
    spell_rangec(pos, g, range);
    for (int i = 0; i != min_range; i++) {
        spell_ranged(pos, g, min_range, i);
        (pos->y >= 0 && pos->x + (min_range - i) >= 0 && pos->x +
        (min_range - i) <= 31 && g->f->map[pos->y][pos->x + (min_range - i)]
        != 'M' ? g->f->map[pos->y][pos->x + (min_range - i)] = ' ' : 0);
        for (int a = 0; a != i + 1; a++) {
            (pos->y - a >= 0 && pos->y - a <= 17 && pos->x + (min_range - i)
            >= 0 && pos->x + (min_range - i) <= 31 && g->f->map[pos->y - a]
            [pos->x + (min_range - i)] != 'M' ? g->f->map[pos->y - a]
            [pos->x + (min_range - i)] = ' ' : 0);
            (pos->y + a >= 0 && pos->y + a <= 17 && pos->x + (min_range - i)
            >= 0 && pos->x + (min_range - i) <= 31 && g->f->map[pos->y + a]
            [pos->x + (min_range - i)] != 'M' ? g->f->map[pos->y + a]
            [pos->x + (min_range - i)] = ' ' : 0);
        }
    }
}
