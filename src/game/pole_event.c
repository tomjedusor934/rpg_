/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** game_loop_fight
*/

#include "../../include/my_rpg.h"

void envent_menu(general_t *g)
{
    if (g->plan == MENU) {
        check_events(g);
        if (g->game->event.type == sfEvtKeyPressed &&
        g->game->event.key.code == sfKeyBack)
            choose_file(g, g->game->event.key.code);

        if (g->game->event.type == sfEvtKeyPressed &&
        (g->game->event.key.code >= sfKeyA &&
        g->game->event.key.code <= sfKeyZ))
            choose_file(g, g->game->event.key.code + 97);
        if (g->game->event.type == sfEvtKeyPressed &&
        g->game->event.key.code == sfKeySpace)
            choose_file(g, g->game->event.key.code);
        if ((g->game->event.type == sfEvtKeyPressed &&
        g->game->event.key.code == sfKeyReturn) ||
        is_on_button(g->menu->connect_but, g) ||
        is_on_button(g->menu->create_but, g)) {
            registration(g);
        }
    }
}

void event_fight(general_t *g)
{
    if (g->plan == FIGHT) {
        if (g->game->event.type == sfEvtClosed) {
            // save_game(g);
            sfRenderWindow_close(g->game->window);
        }
        if (g->game->event.type == sfEvtMouseButtonReleased) {
            if (g->f->is_mturn == 0) {
                left_click(g, (int) g->game->pos_mouse.y,
                (int) g->game->pos_mouse.x);
            }
        }
    }
}

void event_game(general_t *g)
{
    if (g->plan == GAME) {
        all_game_event1(g);

        cheat_cmd(g);

        op_inv(g);

        op_carac(g);

        update_stat(g);

        manage_quest(g);

        if (g->game->event.type == sfEvtMouseButtonReleased && g->inv->is_open == 0 && g->inv->caract_open == 0) {
            click_on_mob(g);
            g->player->dir_anim = 0;
            g->player->tmp_pos_x = g->pos_playe_x;
            g->player->tmp_pos_y = g->pos_player_y;
            g->player->tmp_mp_x = (int) g->game->pos_mouse.x;
            g->player->tmp_mp_y = (int) g->game->pos_mouse.y;
            g->i = set_speed((sfVector2f) {g->player->tmp_pos_x, g->player->tmp_pos_y}, (sfVector2f) {g->player->tmp_mp_x, g->player->tmp_mp_y});
            g->j = g->i;
            g->in_mouvement = 1;
        }
    }
}

void pole_event(general_t *g)
{
    while (sfRenderWindow_pollEvent(g->game->window, &g->game->event)) {
        if (g->game->event.type == sfEvtKeyPressed &&
        g->game->event.key.code == sfKeyReturn)
            g->surscene == MAIN_MENU;
        envent_menu(g);
        event_fight(g);
        event_game(g);
    }
}
