/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** check_position
*/

#include "../../include/my_rpg.h"

void where_i_am(general_t *g)
{
    int pox = g->pos_playe_x / 1920;
    int poy = g->pos_player_y / 1080;
    int sup_chunk = 0;

    for (int i = 0; i != poy; i++)
        sup_chunk += 8;
    g->chunk_nb = pox + poy + sup_chunk;
}

void where_i_amd(general_t *g, int posx, int posy)
{
    int pox = posx / 1920;
    int poy = posy / 1080;
    int sup_chunk = 0;

    for (int i = 0; i != poy; i++)
        sup_chunk += 8;
    g->chunk_nb = pox + poy + sup_chunk;
}

int check_colision(general_t *g, int pos_x, int pos_y)
{
    int check_posx = set_x((sfVector2f) {g->player->tmp_pos_x,
    g->player->tmp_pos_y}, (sfVector2f) {pos_x, pos_y}, g->i - 1, g->j);

    int check_posy = set_y((sfVector2f) {g->player->tmp_pos_x,
    g->player->tmp_pos_y}, (sfVector2f) {pos_x, pos_y}, g->i - 1, g->j);

    //if (g->maping[g->chunk_nb] != NULL) {
        where_i_amd(g, check_posx, check_posy);
        // for (int i = 0; g->maping[g->chunk_nb]->chunk_mapped[i]; i++)
        
        if (g->maping[g->chunk_nb]->chunk_mapped[(check_posy - (1080 * (check_posy / 1080))) / 60][(check_posx - (1920 * (check_posx / 1920))) / 60] == '1')
            return (0);

    return (1);
}
