/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** is_dead
*/

#include "../../include/my_rpg.h"

void end_fight(general_t *g)
{
    mobs_fight_t *backup = g->f->mobs_fight;
    int xp = 0;
    int kamas = 0;

    g->player->stat_player->info->vie =  g->player->stat_player->info->max_vie;
    g->player->stat_player->info->pm = g->player->stat_player->info->max_pm;
    g->player->stat_player->info->pa = g->player->stat_player->info->max_pa;
    while (g->f->mobs_fight) {
        kamas += g->f->mobs_fight->level;
        g->f->map[g->f->mobs_fight->posy][g->f->mobs_fight->posx] = ' ';
        xp += (g->f->mobs_fight->level * g->f->mobs_fight->level);
        g->f->mobs_fight = g->f->mobs_fight->next;
    }
    g->f->mobs_fight = backup;
    g->f->reward_kama = kamas;
    g->f->reward_xp = xp;
    g->player->stat_player->kama += kamas;
    g->player->stat_player->xp += xp;
    g->f->victory_screen = 1;
    g->f->is_fg = 0;
    g->plan = GAME;
}

void is_dead2(general_t *g, int is_one_alive, mobs_fight_t *backup)
{
    if (is_one_alive == 0 || g->player->stat_player->info->vie <= 0) {
        end_fight(g);
        g->f->mobs_fight = NULL;
    }
}
void is_dead(general_t *g)
{
    mobs_fight_t *backup = g->f->mobs_fight;
    int is_one_alive = 0;
    while (g->f->mobs_fight != NULL) {
        if (g->f->mobs_fight->health < 1) {
            g->f->mobs_fight->is_dead = 1;
            g->f->map[g->f->mobs_fight->posy][g->f->mobs_fight->posx] = ' ';
        }
        g->f->mobs_fight = g->f->mobs_fight->next;
    }
    g->f->mobs_fight = backup;
    while (g->f->mobs_fight != NULL) {
        if (g->f->mobs_fight->is_dead == 0) {
            is_one_alive = 1;
        }
        g->f->mobs_fight = g->f->mobs_fight->next;
    }
    g->f->mobs_fight = backup;
    is_dead2(g, is_one_alive, backup);
}
