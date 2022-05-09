/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** set_stat
*/

#include "../../include/my_rpg.h"

void set_stat4(general_t *g, char *item, int a, int i)
{
    g->player->stat_player->info->inteligence = g->player->
    stat_player->info->inteligence + my_atoi(g->f->items[i], a);
    a += intlen(my_atoi(g->f->items[i], a)) + 1;
    g->player->stat_player->info->force = g->player->stat_player->
    info->force + my_atoi(g->f->items[i], a);
    a += intlen(my_atoi(g->f->items[i], a)) + 1;
    g->player->stat_player->info->chance = g->player->stat_player->
    info->chance + my_atoi(g->f->items[i], a);
    a += intlen(my_atoi(g->f->items[i], a)) + 1;
    g->player->stat_player->info->agilite = g->player->stat_player->
    info->agilite + my_atoi(g->f->items[i], a);
    a += intlen(my_atoi(g->f->items[i], a)) + 1;
    g->player->stat_player->info->damage = g->player->stat_player->
    info->damage + my_atoi(g->f->items[i], a);
    a += intlen(my_atoi(g->f->items[i], a)) + 1;
    g->player->stat_player->info->max_vie = g->player->stat_player->
    info->max_vie + my_atoi(g->f->items[i], a);
    a += intlen(my_atoi(g->f->items[i], a)) + 1;
    g->player->stat_player->info->vie = g->player->stat_player->info->max_vie;
}

void set_stat3(general_t *g, char *item)
{
    int a = my_strlen(item);

    for (int i = 0; g->f->items[i]; i++) {
        if (compare_wiw(item, g->f->items[i])) {
            set_stat4(g, item, a, i);
        }
    }
}

void set_stat2(general_t *g)
{
    equip_t *backup = g->inv->equip;

    while (g->inv->equip) {
        if (g->inv->equip->is_eq == 1)
            set_stat3(g, g->inv->equip->name);
        g->inv->equip = g->inv->equip->next;
    }
    g->inv->equip = backup;
}

void set_stat(general_t *g)
{
    g->player->stat_player->info->agilite = g->player->base_stats->agilite;
    g->player->stat_player->info->force = g->player->base_stats->force;
    g->player->stat_player->info->chance = g->player->base_stats->chance;
    g->player->stat_player->info->inteligence =
    g->player->base_stats->inteligence;
    g->player->stat_player->info->max_vie = g->player->base_stats->vie;
    g->player->stat_player->info->damage = 0;
    if (g->player->stat_player->level > 9 )
        g->player->stat_player->info->max_pa = 7;
    else
        g->player->stat_player->info->max_pa = 6;
    if (g->player->stat_player->level > 9 )
        g->player->stat_player->info->max_pm = 4;
    else
        g->player->stat_player->info->max_pm = 3;
    set_stat2(g);
}
