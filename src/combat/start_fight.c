/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** start_fight
*/

#include "../../include/my_rpg.h"

void start_fight(general_t *g, char **mob_list)
{
    g->f->logo = create_object(astrcat("asset/logo_",
    g->player->stat_player->info->name_class, ".png"),
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 60, 60}, (sfVector2f) {1, 1});
    int i = 0;
    g->player->stat_player->sort = malloc(sizeof(spells_list_t));
    for (; mob_list[i]; i++) {
        g->f->str[i] = mob_list[i];
    }
    g->f->str[i] = "0";
    if (my_str_compare(g->player->stat_player->info->name_class, "sacri"))
        g->player->stat_player->sort = g->f->s->sacri;
    if (my_str_compare(g->player->stat_player->info->name_class, "cra"))
        g->player->stat_player->sort = g->f->s->cra;
    if (my_str_compare(g->player->stat_player->info->name_class, "eni"))
        g->player->stat_player->sort = g->f->s->eni;
    if (my_str_compare(g->player->stat_player->info->name_class, "iop"))
        g->player->stat_player->sort = g->f->s->iop;
    g->plan = FIGHT;
}
