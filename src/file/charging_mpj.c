/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** charging_mpj
*/

#include "../../include/my_rpg.h"

void loading_pnj(general_t *g, int pnj)
{
    if (pnj == 1) {
        init_trader(g, (sfVector2f) {8531,3956});
        trader_randitem(g);
    }
    if (pnj == 2) {
        g->pnj->pnj2 = create_object("asset/pnj2.png", (sfVector2f)
        {10963,1866}, (sfIntRect) {0, 0, 280, 410}, (sfVector2f) {0.8, 0.8});
        sfSprite_setOrigin(g->pnj->pnj2->sprite, (sfVector2f) {140, 410});
    }
    if (pnj == 3) {
        g->pnj->pnj1 = create_object("asset/pnj1.png", (sfVector2f)
        {5029,3852}, (sfIntRect) {0, 0, 223, 391}, (sfVector2f) {0.8, 0.8});
        sfSprite_setOrigin(g->pnj->pnj1->sprite, (sfVector2f) {110, 195});
    }
}

void charging_pnj(general_t *g)
{
    g->g_mapi = 0;
    while (g->maping[g->g_mapi]) {
        if (g->g_mapi == 31) {
            loading_pnj(g, 1);
        }
        if (g->g_mapi == 29) {
            loading_pnj(g, 2);
        }
        if (g->g_mapi == 14) {
            loading_pnj(g, 3);
        }
        g->g_mapi += 1;
    }
    g->g_mapi = 0;
    init_dialogue(g);
}
