/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** event_game
*/

#include "../../include/my_rpg.h"

void close_inv(general_t *g)
{
    if (g->inv->is_open == 1) {
        if (is_on_button_clinv(g) == 1) {
            g->inv->is_open = 0;
            g->inv->inventaire->pos.x = g->pos_playe_x - 450;
            g->inv->inventaire->pos.y = g->pos_player_y - 450;
            sfSprite_setPosition(g->inv->inventaire->sprite,
            (sfVector2f) {g->inv->inventaire->pos.x,
            g->inv->inventaire->pos.y});
            dad_inv_slot(g);
            dad_inv_eq(g);
            dad_ep_item(g);
        }
        if (g->inv->dad_item >= 0)
            move_item(g);
        if (g->inv->dad_eq >= 0)
            move_eq(g);
        bouton_inv_reset(g);
    }
}
void upgrade_stat(general_t *g)
{
    (is_on_button(g->inv->bouton[6], g) == 1 ?
    g->inv->caract_open = 0 : 0);
    (is_on_button(g->inv->bouton[0], g) == 1 &&
    g->player->stat_player->point_caract > 0 ?
    g->player->stat_player->point_caract--,
    g->player->stat_player->info->max_vie++ : 0);
    (is_on_button(g->inv->bouton[1], g) == 1 &&
    g->player->stat_player->point_caract > 0 ?
    g->player->stat_player->point_caract--,
    g->player->stat_player->info->agilite++ : 0);
    (is_on_button(g->inv->bouton[2], g) == 1 &&
    g->player->stat_player->point_caract > 0 ?
    g->player->stat_player->point_caract--,
    g->player->stat_player->info->chance++ : 0);
    (is_on_button(g->inv->bouton[3], g) == 1 &&
    g->player->stat_player->point_caract > 0 ?
    g->player->stat_player->point_caract--,
    g->player->stat_player->info->force++ : 0);
}

void update_stat(general_t *g)
{
    if (g->game->event.type == sfEvtMouseButtonReleased) {
        open_trader(g);
        if (g->inv->caract_open == 1) {
            upgrade_stat(g);
            (is_on_button(g->inv->bouton[4], g) == 1 &&
            g->player->stat_player->point_caract > 0 ?
            g->player->stat_player->point_caract--,
            g->player->stat_player->info->inteligence++ : 0);
            (is_on_button(g->inv->bouton[5], g) == 1 &&
            g->player->stat_player->point_caract > 0 ?
            g->player->stat_player->point_caract--,
            g->player->stat_player->info->sagesse++ : 0);
        }
        close_inv(g);
    }
}