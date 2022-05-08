/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** create_view
*/

#include "../../include/my_rpg.h"

void create_view(general_t *g)
{
    g->game->cam = sfView_createFromRect((sfFloatRect) {0, 0, g->side, g->top});
    sfView_setViewport(g->game->cam, (sfFloatRect) {0, 0, 1, 1});
    sfView_setCenter(g->game->cam, (sfVector2f) {g->side / 2, g->top / 2});
    sfRenderWindow_setView(g->game->window, g->game->cam);
    g->game->mini_map = sfView_createFromRect((sfFloatRect) {0, 0, 1920 * 9, 1080 * 9});
    sfView_setViewport(g->game->mini_map, (sfFloatRect) {0.7, 0.766, 0.3, 0.3});
    sfView_setCenter(g->game->mini_map, (sfVector2f) {1920 * 9 / 2, 1080 * 9 / 2});
}

void create_text(general_t *g)
{
    g->g_mapi = 0;
    g->login = text_gener(g->game->login, (sfVector2f) {60, 320}, 50);
    g->paswd = text_gener(g->game->pasword_login, (sfVector2f) {60, 520}, 50);
    g->user_name = text_gener(g->game->user_name, (sfVector2f) {660, 320}, 50);
    g->user_paswd = text_gener(g->game->new_pasword, (sfVector2f) {660, 520}, 50);
    g->game->god_mode->text_cmd = text_gener2(g->game->god_mode->cmd, (sfVector2f) {0, 0}, 20);
}
