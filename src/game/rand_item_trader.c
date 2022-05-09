/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** trader
*/

#include "../../include/my_rpg.h"

char *items[] = {"amulette bouftou" ,"anneaux bouf","ceinture bouftou",
"bottes boufbottes", "arme bouftou", "coiffe piou rouge", "cape piou rouge",
"ceinture piou rouge", "bottes piou rouge", "amulette piou rouge",
"anneaux piou rouge", "coiffe piou vert", "cape piou vert",
"ceinture piou vert", "bottes piou vert", "amulette piou vert",
"anneaux piou vert", "coiffe piou jaune", "cape piou jaune" ,
"ceinture piou jaune", "bottes piou jaune", "amulette piou jaune",
"anneaux piou jaune", "coiffe piou vert", "cape piou vert",
"ceinture piou vert", "bottes piou vert", "coiffe aventurier",
"cape aventurier", "ceinture aventurier", "bottes aventurier",
"amulette aventurier", "anneaux aventurier", 0};

const int prices[] = {60, 60, 60, 60, 60, 30, 30 , 30, 30, 30, 30, 30, 30, 30
, 30, 30, 30, 30 ,30 ,30 ,30 , 30, 30, 30, 30 , 30, 30, 30, 30, 30, 30, 30, 30,
30, 30};

void rand_item2(general_t *g, char *str, int i,  int a)
{
    while (a == i)
        a = rand() % 33;
    str = mstrcpy(str, "asset/");
    str = mstrcat(str, items[a]);
    str = mstrcat(str, ".png");
    g->trader->item2 = create_object(str, (sfVector2f) {g->trader->trader->
    pos.x + 100, g->trader->trader->pos.y + 100}, (sfIntRect) {0, 0, 59, 59}
    , (sfVector2f) {1, 1});
    g->trader->name2 = items[a];
    g->trader->price2 = prices[a];
}

void rand_item3(general_t *g, char *str, int b)
{
    str = mstrcpy(str, "asset/");
    str = mstrcat(str, items[b]);
    str = mstrcat(str, ".png");
    g->trader->item3 = create_object(str, (sfVector2f) {g->trader->trader->
    pos.x - 80, g->trader->trader->pos.y + 200}, (sfIntRect) {0, 0, 59, 59},
    (sfVector2f) {1, 1});
    g->trader->name3 = items[b];
    g->trader->price3 = prices[b];
}

void rand_item4(general_t *g, char *str, int c)
{
    str = mstrcpy(str, "asset/");
    str = mstrcat(str, items[c]);
    str = mstrcat(str, ".png");
    g->trader->item4 = create_object(str, (sfVector2f) {g->trader->trader->
    pos.x + 100, g->trader->trader->pos.y + 200}, (sfIntRect) {0, 0, 59, 59},
    (sfVector2f) {1, 1});
    g->trader->name4 = items[c];
    g->trader->price4 = prices[c];
}

void trader_randitem(general_t *g)
{
    char *str = NULL;
    int i = rand() % 33, a = i, b = i, c = i;
    str = mstrcpy(str, "asset/");
    str = mstrcat(str, items[i]);
    str = mstrcat(str, ".png");
    g->trader->item1 = create_object(str, (sfVector2f) {g->trader->trader->
    pos.x - 80, g->trader->trader->pos.y + 100}, (sfIntRect) {0, 0, 59, 59},
    (sfVector2f) {1, 1});
    g->trader->name1 = items[i];
    g->trader->price1 = prices[i];
    rand_item2(g, str, a, i);
    while (b == i || b == a)
        b = rand() % 33;
    rand_item3(g, str, b);
    while (c == i || c == a || c == b)
        c = rand() % 33;
    rand_item4(g, str, c);
}
