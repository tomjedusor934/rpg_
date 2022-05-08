/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** spells_range
*/

#include "../../include/my_rpg.h"

void spell_range2(general_t *g, int range, int i)
{
    sfVector2i *pos = get_player_pos(g);
    for (int a = 0; a != i + 1; a++) {
        (pos->y - a >= 0 && pos->y - a <= 17 && pos->x + (range - i) >= 0
        && pos->x + (range - i) <= 31 && g->f->map[pos->y - a]
        [pos->x + (range - i)] != 'M' ? g->f->map[pos->y - a][pos->x +
        (range - i)] = 'U' : 0);
        (pos->y + a >= 0 && pos->y + a <= 17 && pos->x + (range - i) >= 0
        && pos->x + (range - i) <= 31 && g->f->map[pos->y + a]
        [pos->x + (range - i)] != 'M' ? g->f->map[pos->y + a][pos->x +
        (range - i)] = 'U' : 0);
    }
}

void is_in_spell_range2(general_t *g, int range, int i)
{
    sfVector2i *pos = get_player_pos(g);
    for (int a = 0; a != i + 1; a++) {
        (pos->y - a >= 0 && pos->y - a <= 17 && pos->x + (range - i) >= 0 &&
        pos->x + (range - i) <= 31 ? g->f->map[pos->y - a][pos->x +
        (range - i)] = 'U' : 0);
        (pos->y + a >= 0 && pos->y + a <= 17 && pos->x + (range - i) >= 0 &&
        pos->x + (range - i) <= 31 ? g->f->map[pos->y + a][pos->x +
        (range - i)] = 'U' : 0);
    }
}
