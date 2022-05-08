/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** all_init
*/

#include "../../include/my_rpg.h"

void all_init3(general_t *g)
{
    charging_map(g);
    generate_mob(g);
    charging_pnj(g);
    g->player->dir_anim = 0;
    g->player->side = 0;
    g->game->map_visible = 0;
    g->game->god_mode->is_visible = 0;
    g->game->god_mode->cmd = malloc(sizeof(char) * 51);
    g->game->god_mode->cmd[0] = '\0';
    musics(g);
}

void all_init2(general_t *g)
{
    g->connexion_mode = 0;
    g->player->tmp_pos_x = 0;
    g->player->tmp_pos_y = 0;
    g->player->tmp_mp_x = 0;
    g->player->tmp_mp_y = 0;
    g->i = 0;
    g->j = 0;
    g->in_mouvement = 0;
    g->chunk_nb = 0;
    g->player->cam_posx = 0;
    g->player->cam_posy = 0;
    g->error = 0;
    g->file_load = 0;
    all_init3(g);
}

void all_init(general_t *g)
{
    char *name = "My_RPG";
    g->game->mode = (sfVideoMode) {1920, 1080, 32};
    g->game->window = sfRenderWindow_create(g->game->mode, name, sfResize | sfClose, NULL);
    g->side = 1920;
    g->top = 1080;
    g->pos_playe_x = 500;
    g->pos_player_y = 500;
    g->game->login = NULL;
    g->game->pasword_login = NULL;
    g->game->user_name = NULL;
    g->game->new_pasword = NULL;
    g->game->tmp_pos_mobx = 0;
    g->game->tmp_pos_moby = 0;
    g->game->hidden_pasword = malloc(sizeof(char) * 21);
    g->game->hidd_new_paswd = malloc(sizeof(char) * 21);
    g->game->hidden_pasword[0] = '\0';
    g->game->hidd_new_paswd[0] = '\0';
    g->game->file = 0;
    g->connect_ok = 0;
    all_init2(g);
}
