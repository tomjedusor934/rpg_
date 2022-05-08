/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** display_mob
*/

#include "../../include/my_rpg.h"

void display_mobs(general_t *g)
{
    l_mob_all_group_t *backup = g->game->list_all_groupe;
    
    while (g->game->list_all_groupe) {
        l_mob_group_t *tmp = g->game->list_all_groupe->mob_group;
        while (g->game->list_all_groupe->mob_group) {
            sfRenderWindow_drawSprite(g->game->window, g->game->list_all_groupe->mob_group->mob_skin->sprite, NULL);
            g->game->list_all_groupe->mob_group = g->game->list_all_groupe->mob_group->next;
        }
        g->game->list_all_groupe->mob_group = tmp;
        g->game->list_all_groupe = g->game->list_all_groupe->next;
    }
    g->game->list_all_groupe = backup;
}
