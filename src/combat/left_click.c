/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** left_click
*/

#include "../../include/my_rpg.h"

void left_click2(general_t *g)
{
    spells_list_t *backup = g->player->stat_player->sort;
    int a = 0;

    while (g->player->stat_player->sort->next != NULL) {
        if (is_on_button(g->player->stat_player->sort->s->logo, g)
        && g->player->stat_player->info->pa >=
        g->player->stat_player->sort->s->pa) {
            g->f->selected = g->player->stat_player->sort->s;
            a = 1;
        }
        g->player->stat_player->sort = g->player->stat_player->sort->next;
    }
    g->player->stat_player->sort = backup;
    if (a == 0)
        g->f->selected = NULL;
}

void left_click3(general_t *g)
{
    while (g->f->mobs_fight) {
        if (g->f->mobs_fight->posx == (int) g->game->pos_mouse.x / 60 &&
        g->f->mobs_fight->posy == (int) g->game->pos_mouse.y / 60 &&
        is_in_spell_range(g, (sfVector2i) {g->f->mobs_fight->posx,
        g->f->mobs_fight->posy}, g->f->selected->max_range,
        g->f->selected->min_range)) {
            g->f->mobs_fight->health = g->f->mobs_fight->health -
            g->f->selected->damage;
            g->player->stat_player->info->pa =
            g->player->stat_player->info->pa - g->f->selected->pa;
        }
        g->f->mobs_fight = g->f->mobs_fight->next;
    }   
}

void left_click4(general_t *g)
{
    while (g->f->mobs_fight) {
        if (g->f->mobs_fight->posx == (int) g->game->pos_mouse.x / 60 &&
        g->f->mobs_fight->posy == (int) g->game->pos_mouse.y / 60) {
            g->f->life_text->x = g->f->mobs_fight->posx * 60 + 10;
            g->f->life_text->y = g->f->mobs_fight->posy * 60 - 50;
            g->f->life_text->value = g->f->mobs_fight->health;
            g->f->mob_life = 1;
        }
        g->f->mobs_fight = g->f->mobs_fight->next;
    }
}

void left_click(general_t *g, int y, int x)
{
    mobs_fight_t *backup3 = g->f->mobs_fight;
    if (g->f->mob_life == 1)
        g->f->mob_life = 0;
    if (g->player->stat_player->info->pm > 0)
        fight_move(g, y / 60, x / 60);
    if (is_on_button(g->f->go[2], g)) {
        g->f->is_mturn = 1;
        g->player->stat_player->info->pm =
        g->player->stat_player->info->max_pm;
        g->player->stat_player->info->pa =
        g->player->stat_player->info->max_pa;
    }
    if (g->f->selected != NULL)
        left_click3(g);
    else
        left_click4(g);
    left_click2(g);
    reset_the_map(g);
    g->f->mobs_fight = backup3;
    is_dead(g);
}
