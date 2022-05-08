/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur->prevot
** File description:
** fight_range
*/

#include "../../include/my_rpg.h"

void player_move4(sfVector2i *pos, general_t *g, int range, int i)
{
    for (int a = 0; a != i + 1; a++) {
        (pos->y - a >= 0 && pos->y - a <= 17 && pos->x - (range - i) >= 0
        && pos->x - (range - i) <= 31 && g->f->map[pos->y -
        a][pos->x - (range - i)] != 'M' ? g->f->map[pos->y - a][pos->x -
        (range - i)] = 'V' : 0);
        (pos->y + a >= 0 && pos->y + a <= 17 && pos->x - (range - i) >= 0
        && pos->x - (range - i) <= 31 && g->f->map[pos->y +
        a][pos->x - (range - i)] != 'M' ? g->f->map[pos->y + a][pos->x -
        (range - i)] = 'V' : 0);
    }
}

void player_move2(sfVector2i *pos, general_t *g, int range, int i)
{
    for (int a = 0; a != i + 1; a++) {
        (pos->y - a >= 0 && pos->y - a <= 17 && pos->x + (range - i) >= 0
        && pos->x + (range - i) <= 31 && g->f->map[pos->y - a]
        [pos->x + (range - i)] != 'M' ? g->f->map[pos->y - a][pos->x +
        (range - i)] = 'V' : 0);
        (pos->y + a >= 0 && pos->y + a <= 17 && pos->x +
        (range - i) >= 0 && pos->x + (range - i) <= 31 && g->f->map[pos->y + a]
        [pos->x + (range - i)] != 'M' ? g->f->map[pos->y + a][pos->x +
        (range - i)] = 'V' : 0);
    }
}

void player_move(sfVector2i *pos, general_t *g, int range)
{
    for (int i = 0; i != range; i++) {
        (pos->y - (range - i) >= 0 && pos->y - (range - i) <= 17 &&
        pos->x >= 0 && pos->x <= 31 && g->f->map[pos->y - (range -
        i)][pos->x] != 'M' ? g->f->map[pos->y - (range - i)][pos->x] = 'V': 0);
        (pos->y + (range - i) >= 0 && pos->y + (range - i)
        <= 17 && pos->x >= 0 && pos->x <= 31 && g->f->map[pos->y + (range -
        i)][pos->x] != 'M' ? g->f->map[pos->y + (range - i)][pos->x] = 'V': 0);
        player_move4(pos, g, range, i);
        (pos->y >= 0 && pos->y <= 17 && pos->x + (range - i) >= 0 &&  pos->x +
        (range - i) <= 31 && g->f->map[pos->y][pos->x +
        (range - i)] != 'M' ? g->f->map[pos->y][pos->x + (range - i)] = 'V' : 0);
        player_move2(pos, g, range, i);
    }
}

int range_attack2(general_t *g, int i)
{
    int is_inrange = 0;
    for (int a = 0; a != i + 1; a++) {
        (g->f->mobs_fight->posy - a >= 0 && g->f->mobs_fight->posx - (g->f->
        mobs_fight->range - i) >= 0 ? (g->f->map[g->f->mobs_fight->posy - a]
        [g->f->mobs_fight->posx - (g->f->mobs_fight->range - i)] == 'P' ?
        is_inrange = 1 : 0) : 0);
        (g->f->mobs_fight->posy + a >= 0 && g->f->mobs_fight->posx - (g->f->
        mobs_fight->range - i) >= 0 ? (g->f->map[g->f->mobs_fight->posy + a]
        [g->f->mobs_fight->posx - (g->f->mobs_fight->range - i)] == 'P' ?
        is_inrange = 1 : 0) : 0);
    }
    return (is_inrange);
}

int range_attack3(general_t *g, int i)
{
    int is_inrange = 0;
    (g->f->mobs_fight->posy >= 0 && g->f->mobs_fight->posx +
    (g->f->mobs_fight->range - i) >= 0 ? (g->f->map[g->f->mobs_fight->posy]
    [g->f->mobs_fight->posx
    + (g->f->mobs_fight->range - i)] == 'P' ? is_inrange = 1 : 0) : 0);
    for (int a = 0; a != i + 1; a++) {
        (g->f->mobs_fight->posy - a >= 0 && g->f->mobs_fight->posx + (g->f->
        mobs_fight->range - i) >= 0 ? (g->f->map[g->f->mobs_fight->posy - a]
        [g->f->mobs_fight->posx + (g->f->mobs_fight->range - i)] == 'P' ?
        is_inrange = 1 : 0) : 0);
        (g->f->mobs_fight->posy + a >= 0 && g->f->mobs_fight->posx + (g->f->
        mobs_fight->range - i) >= 0 ? (g->f->map[g->f->mobs_fight->posy + a]
        [g->f->mobs_fight->posx + (g->f->mobs_fight->range - i)] == 'P' ?
        is_inrange = 1 : 0) : 0);
    }
    return (is_inrange);
}

int range_attack(general_t *g)
{
    int is_inrange = 0;
    
    for (int i = 0; i != g->f->mobs_fight->range; i++) {
        (g->f->mobs_fight->posy - (g->f->mobs_fight->range - i) >= 0
        && g->f->mobs_fight
        ->posx >= 0 ? (g->f->map[g->f->mobs_fight->posy -
        (g->f->mobs_fight->range - i)]
        [g->f->mobs_fight->posx] == 'P' ? is_inrange = 1 : 0) : 0);
        (g->f->mobs_fight->posy + (g->f->mobs_fight->range - i) >= 0
        && g->f->mobs_fight
        ->posx >= 0 ? (g->f->map[g->f->mobs_fight->posy +
        (g->f->mobs_fight->range - i)]
        [g->f->mobs_fight->posx] == 'P' ? is_inrange = 1 : 0) : 0);
        is_inrange += range_attack2(g, i);
        is_inrange += range_attack3(g, i);
    }
    if (is_inrange == 1)
        g->player->stat_player->info->vie = g->player->stat_player->info->vie
        - g->f->mobs_fight->max_damage;
    return (0);
}
