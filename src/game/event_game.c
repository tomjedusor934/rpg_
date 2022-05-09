/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** game_loop_fight
*/

#include "../../include/my_rpg.h"

void all_game_event2(general_t *g)
{
    if (g->game->event.type == sfEvtKeyReleased &&
    g->game->event.key.code == sfKeyTab &&
    g->player->stat_player->god_mod == 1) {
        if (g->game->god_mode->is_visible == 0) {
            g->game->god_mode->terminal->pos =
            (sfVector2f) {g->player->cam_posx + 10,
            g->player->cam_posy + 10};
            sfSprite_setPosition(g->game->god_mode->terminal->sprite,
            g->game->god_mode->terminal->pos);
            g->game->god_mode->text_cmd->pos =
            (sfVector2f) {g->player->cam_posx + 15, g->player->cam_posy + 15};
            sfText_setPosition(g->game->god_mode->text_cmd->text,
            g->game->god_mode->text_cmd->pos);
            g->game->god_mode->is_visible = 1;
        } else
            g->game->god_mode->is_visible = 0;
    }
}

void all_game_event1(general_t *g)
{
    if (g->game->event.type == sfEvtClosed) {
        save_game(g);
        sfRenderWindow_close(g->game->window);
    }
    if (g->game->event.type == sfEvtKeyReleased &&
    g->game->event.key.code == sfKeyM && g->game->god_mode->is_visible == 0) {
        if (g->game->map_visible == 0)
            g->game->map_visible = 1;
        else
            g->game->map_visible = 0;
    }
    all_game_event2(g);
}

void cheat_cmd(general_t *g)
{
    if (g->game->event.type == sfEvtKeyPressed &&
    g->game->event.key.code == sfKeySlash &&
    g->player->stat_player->god_mod == 1 && g->game->god_mode->is_visible == 1)
        write_cmd(g, g->game->event.key.code + 6, g->game->god_mode->cmd);
    if (g->game->event.type == sfEvtKeyPressed &&
    g->game->event.key.code == sfKeyBack &&
    g->player->stat_player->god_mod == 1 && g->game->god_mode->is_visible == 1)
        write_cmd(g, g->game->event.key.code, g->game->god_mode->cmd);
    if (g->game->event.type == sfEvtKeyPressed &&
    (g->game->event.key.code >= sfKeyA && g->game->event.key.code <= sfKeyZ) &&
    g->player->stat_player->god_mod == 1 && g->game->god_mode->is_visible == 1)
        write_cmd(g, g->game->event.key.code + 97, g->game->god_mode->cmd);
    if (g->game->event.type == sfEvtKeyPressed &&
    g->game->event.key.code == sfKeySpace &&
    g->player->stat_player->god_mod == 1 && g->game->god_mode->is_visible == 1)
        write_cmd(g, g->game->event.key.code, g->game->god_mode->cmd);
    if (g->game->event.type == sfEvtKeyPressed &&
    g->game->event.key.code == sfKeyEnter &&
    g->player->stat_player->god_mod == 1 && g->game->god_mode->is_visible == 1)
        check_cmd(g);
}

void op_inv(general_t *g)
{
    if (g->game->event.key.code == sfKeyI && g->game->event.type ==
    sfEvtKeyReleased && g->inv->dad_item == -1 &&
    g->game->god_mode->is_visible == 0) {
        if (g->inv->is_open == 0) {
            g->inv->is_open = 1;
            g->inv->inventaire->pos.x = g->player->cam_posx + 530;
            g->inv->inventaire->pos.y = g->player->cam_posy + 200;
            g->player->player_ap->play_inv->pos =
            (sfVector2f) {g->player->cam_posx + 710,g->player->cam_posy + 300};
            sfSprite_setPosition(g->player->player_ap->play_inv->sprite,
            g->player->player_ap->play_inv->pos);
            sfSprite_setPosition(g->inv->inventaire->sprite,
            (sfVector2f) {g->inv->inventaire->pos.x,
            g->inv->inventaire->pos.y});
            dad_inv_slot(g);
            dad_inv_eq(g);
            dad_ep_item(g);
        } else
            g->inv->is_open = 0;
    }
}

void op_carac(general_t *g)
{
    if (g->game->event.key.code == sfKeyC &&
    g->game->event.type == sfEvtKeyReleased &&
    g->game->god_mode->is_visible == 0) {
        if (g->inv->caract_open == 0)
            g->inv->caract_open = 1;
        else
            g->inv->caract_open = 0;
    }
}
