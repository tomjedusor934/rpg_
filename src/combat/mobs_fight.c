/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** mobs_fight
*/

#include "../../include/my_rpg.h"

int move_mobs2(general_t *g, sfVector2i *pos)
{
    if (pos->y > g->f->mobs_fight->posy &&
    g->f->map[g->f->mobs_fight->posy + 1]
    [g->f->mobs_fight->posx] != 'P' && g->f->map[g->f->mobs_fight->posy + 1]
    [g->f->mobs_fight->posx] != 'M') {
        g->f->map[g->f->mobs_fight->posy][g->f->mobs_fight->posx] = ' ';
        g->f->map[++g->f->mobs_fight->posy][g->f->mobs_fight->posx] = 'M';
        g->f->mobs_fight->pm--;
        return (1);
    } else if (pos->y < g->f->mobs_fight->posy &&
    g->f->map[g->f->mobs_fight->posy - 1]
    [g->f->mobs_fight->posx] != 'P' && g->f->map[g->f->mobs_fight->posy - 1]
    [g->f->mobs_fight->posx] != 'M') {
        g->f->map[g->f->mobs_fight->posy][g->f->mobs_fight->posx] = ' ';
        g->f->map[--g->f->mobs_fight->posy][g->f->mobs_fight->posx] = 'M';
        g->f->mobs_fight->pm--;
        return (1);
    }
    return (0);
}

void move_mobs(general_t *g)
{
    sfVector2i *pos = get_player_pos(g);
    if (pos->x > g->f->mobs_fight->posx && g->f->map[g->f->mobs_fight->posy]
    [g->f->mobs_fight->posx + 1] != 'P' && g->f->map[g->f->mobs_fight->posy]
    [g->f->mobs_fight->posx + 1] != 'M') {
        g->f->map[g->f->mobs_fight->posy][g->f->mobs_fight->posx] = ' ';
        g->f->map[g->f->mobs_fight->posy][++g->f->mobs_fight->posx] = 'M';
        g->f->mobs_fight->pm--;
        return;
    } else if (pos->x < g->f->mobs_fight->posx &&
    g->f->map[g->f->mobs_fight->posy]
    [g->f->mobs_fight->posx - 1] != 'P' && g->f->map[g->f->mobs_fight->posy]
    [g->f->mobs_fight->posx - 1] != 'M') {
        g->f->map[g->f->mobs_fight->posy][g->f->mobs_fight->posx] = ' ';
        g->f->map[g->f->mobs_fight->posy][--g->f->mobs_fight->posx] = 'M';
        g->f->mobs_fight->pm--;
        return;
    }
    if (move_mobs2(g, pos) == 1)
        return;
    g->f->mobs_fight->pm--;
}

void mobs_turn2(general_t *g)
{
    if (g->f->mobs_fight->is_dead == 0) {
        move_mobs(g);
        if (g->f->mobs_fight->pm == 0) {
        range_attack(g);
        g->f->mobs_fight = g->f->mobs_fight->next;
        }
    } else {
        g->f->mobs_fight = g->f->mobs_fight->next;
    }
}

void mobs_turn(general_t *g)
{
    mobs_fight_t *tmp = g->f->mobs_fight;
    while (g->f->mobs_fight) {
        mobs_turn2(g);
    }
    g->f->mobs_fight = tmp;
    while (g->f->mobs_fight) {
        g->f->mobs_fight->pm = g->f->mobs_fight->maxpm;
        g->f->mobs_fight = g->f->mobs_fight->next;
    }
    g->f->mobs_fight = tmp;
}
