/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** init_game
*/

#include "../../include/my_rpg.h"

void init_items(general_t *g)
{
    g->f->item_file = load_file("objet/items.txt");
    g->f->items = str_to_warray(g->f->item_file, '\n');
}

void malloc_structs(general_t *g)
{
    g->game = malloc(sizeof(general_game_t));
    g->menu = malloc(sizeof(menu_t));
    g->f = malloc(sizeof(fight_t));
    g->f->s = malloc(sizeof(spells_t));
    g->s_clock = malloc(sizeof(struct_clock_t));
    g->game->god_mode = malloc(sizeof(god_mode_t));
    g->pnj = malloc(sizeof(pnj_t));
}

void init_all_struct(general_t *g)
{
    g->player = malloc(sizeof(s_player_t));
    g->player->stat_player = malloc(sizeof(stat_player_t));
    g->player->stat_player->info = malloc(sizeof(info_player_t));
    g->player->stat_player->info->res = malloc(sizeof(resistance_t));
    g->player->player_ap = malloc(sizeof(player_apparence_t));
    g->player->stat_player->god_mod = 0;
    g->player->stat_player->kama = 0;
    g->player->stat_player->level = 0;
    g->player->stat_player->name = NULL;
    g->player->stat_player->sort = NULL;
    g->player->stat_player->xp = 0;
    init_items(g);
}
