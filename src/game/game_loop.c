/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** game_loop
*/

#include "../../include/my_rpg.h"

void de_all_menus(general_t *g)
{

}

void game_loop(general_t *g)
{
    all_init(g);
    int inventory_open = 1;

    init_menu_text(g);

    create_view(g);

    create_text(g);


    while (sfRenderWindow_isOpen(g->game->window)) {

        g->game->mouse = sfMouse_getPositionRenderWindow(g->game->window);
        g->game->pos_mouse = sfRenderWindow_mapPixelToCoords(g->game->window, g->game->mouse, g->game->cam);

        pole_event(g);
        if (g->plan == GAME) {
            sfRenderWindow_setView(g->game->window, g->game->cam);
            if (g->file_load == 1) {
                sfView_reset(g->game->cam, (sfFloatRect) {0, 0, 2000, 1160});
                sfRenderWindow_setView(g->game->window, g->game->cam);
                g->file_load = 2;
            }

            //print_4_text(g);
            sfRenderWindow_clear(g->game->window, sfBlack);
            while (g->map[g->g_mapi]) {
                sfRenderWindow_drawSprite(g->game->window, g->map[g->g_mapi]->sprite, NULL);
                g->g_mapi++;
            }
            g->g_mapi = 0;

            sfRenderWindow_drawSprite(g->game->window, g->pnj->pnj1->sprite, NULL);
            sfRenderWindow_drawSprite(g->game->window, g->pnj->pnj2->sprite, NULL);
            if (g->inv->caract_open) {
                set_stat(g);
            }
            levelup(g);
            display_mobs(g);
            draw_trader(g);
            if (g->f->victory_screen == 1) {
                display_victory(g);
            }
            where_i_am(g);
            if (g->player->stat_player->god_mod == 1 && g->in_mouvement != 1) {
                arrow_deplacement(g);
            }
            if (g->in_mouvement == 1) {
                mouse_deplacement(g, g->player->tmp_mp_x, g->player->tmp_mp_y);
                if (g->player->side == 1)
                    sfRenderWindow_drawSprite(g->game->window, g->player->player_ap->go_right->sprite, NULL);
                if (g->player->side == 2)
                    sfRenderWindow_drawSprite(g->game->window, g->player->player_ap->go_left->sprite, NULL);
                if (g->player->side == 3)
                    sfRenderWindow_drawSprite(g->game->window, g->player->player_ap->go_down->sprite, NULL);
                if (g->player->side == 4)
                    sfRenderWindow_drawSprite(g->game->window, g->player->player_ap->go_up->sprite, NULL);
            } else
                sfRenderWindow_drawSprite(g->game->window, g->player->player_ap->player->sprite, NULL);

            sfSprite_setPosition(g->player->player_ap->player->sprite, g->player->player_ap->player->pos);
            recenter_cam(g);

            if (g->inv->is_open == 1) {
                if (g->inv->dad_eq >= 0)
                    dad_eq(g);
                if (g->inv->dad_item >= 0)
                    dad_item(g);
                if (inventory_open == 1){
                    draw_inv(g);
                    draw_items(g);
                }
                sfRenderWindow_drawSprite(g->game->window, g->player->player_ap->play_inv->sprite, NULL);
            }
            if (g->inv->caract_open == 1) {
                g->inv->invcarac->pos.x = g->player->cam_posx ;
                g->inv->invcarac->pos.y = g->player->cam_posy ;
                sfSprite_setPosition(g->inv->invcarac->sprite, g->inv->invcarac->pos);
                for (int i = 0, y = 0; i < 6; i++, y += 35) {
                    g->inv->bouton[i]->pos.x = g->inv->invcarac->pos.x + 269;
                    g->inv->bouton[i]->pos.y = g->inv->invcarac->pos.y + 193 + y;
                    sfSprite_setPosition(g->inv->bouton[i]->sprite, g->inv->bouton[i]->pos);
                    sfRenderWindow_drawSprite(g->game->window, g->inv->bouton[i]->sprite, NULL);
                }
                g->inv->bouton[6]->pos.x = g->inv->invcarac->pos.x + 293;
                g->inv->bouton[6]->pos.y = g->inv->invcarac->pos.y + 18;
                sfSprite_setPosition(g->inv->bouton[6]->sprite, g->inv->bouton[6]->pos);
                sfRenderWindow_drawSprite(g->game->window, g->inv->bouton[6]->sprite, NULL);
                sfRenderWindow_drawSprite(g->game->window, g->inv->invcarac->sprite, NULL);
                print_carac(g);
            }
            display_mobs(g);
            if (g->game->god_mode->is_visible == 1) {
                sfRenderWindow_drawSprite(g->game->window, g->game->god_mode->terminal->sprite, NULL);
                sfRenderWindow_drawText(g->game->window, g->game->god_mode->text_cmd->text, NULL);
            }
            //mini map display
            if (g->game->map_visible == 1) {
                sfRenderWindow_setView(g->game->window, g->game->mini_map);
                while (g->map[g->g_mapi]) {
                    sfRenderWindow_drawSprite(g->game->window, g->map[g->g_mapi]->sprite, NULL);
                    g->g_mapi++;
                }
                g->g_mapi = 0;
                sfSprite_setPosition(g->player->player_ap->player->sprite, g->player->player_ap->player->pos);
                sfSprite_setScale(g->player->player_ap->player->sprite, (sfVector2f) {4, 4});
                sfRenderWindow_drawSprite(g->game->window, g->player->player_ap->player->sprite, NULL);
                sfSprite_setScale(g->player->player_ap->player->sprite, (sfVector2f) {0.65, 0.65});
            }
            dialogue_pnj(g);
            draw_dialogur(g);
        }
        game_loop_menu(g);
        game_loop_fight(g);
        (g->surscene == SETTINGS ? option_menu(g) :
        g->surscene == MAIN_MENU ? main_menu(g) : 0);
        sfRenderWindow_display(g->game->window);
    }
}
