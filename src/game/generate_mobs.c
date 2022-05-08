/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** generate_mobs
*/

#include "../../include/my_rpg.h"

int size_list(general_t *g)
{
    mobs_t *list = g->f->mobs;
    int size = 0;
    while (list) {
        size++;
        list = list->next;
    }
    return (size);
}

int pos_is_ok(char **chunk, int x, int y)
{
    if (chunk[y][x] == '0')
        return (1);
    return (0);
}

int check_map(char **chunk)
{
    for (int y = 0; chunk[y]; y++)
        for (int x = 0; chunk[y][x] != '\0'; x++)
            if (chunk[y][x] == '0')
                return (1);
    return (0);
}

sfVector2f choose_pos(general_t *g, char **chunk, int mob_nb)
{
    sfVector2f pos = {0, 0};
    int x = 0;
    int x2 = 0;
    int y = 0;
    if (mob_nb == 0) {
        g->game->tmp_pos_mobx = rand() % 30;
        g->game->tmp_pos_moby = rand() % 16;
        while (!pos_is_ok(chunk, g->game->tmp_pos_mobx, g->game->tmp_pos_moby)) {
            g->game->tmp_pos_mobx = rand() % 30;
            g->game->tmp_pos_moby = rand() % 16;
        }
    }
    if (mob_nb == 1)
        x2 += 160;
    if (mob_nb == 2)
        y += 160;
    for (int i = 1; i - 1 < g->g_mapi; i++) {
        x += 1920;
        if (i % 9 == 0) {
            y += 1080;
            x = 0;
        }
    }
    pos.x = g->game->tmp_pos_mobx * 60 + x + x2;
    pos.y = g->game->tmp_pos_moby * 60 + y;
    return (pos);
}

void add_node(general_t *g, mobs_t *mob, int mob_nb)
{
    l_mob_group_t *node = malloc(sizeof(l_mob_group_t));
    node->mob = mob;
    node->is_dead = 0;
    node->mob_skin = create_object(astrcat("asset/", node->mob->name, ".png"), choose_pos(g, g->maping[g->g_mapi]->chunk_mapped, mob_nb), (sfIntRect) {0, 0, 200, 200}, (sfVector2f) {0.7, 0.7});
    //sfSprite_setOrigin(node->mob_skin->sprite, (sfVector2f) {100, 100});
    sfSprite_setPosition(node->mob->logo->sprite, node->mob->logo->pos);
    node->next = g->game->list_all_groupe->mob_group;
    g->game->list_all_groupe->mob_group = node;
}

void add_in_group(general_t *g)
{
    mobs_t *back = g->f->mobs;
    int size = size_list(g);
    int rand_nb_mob = 0;
    int nb_mob = 0;
    int rand_mob = 0;
    int mob = 0;

    rand_nb_mob = rand() % 4;
    while (nb_mob < rand_nb_mob) {
        rand_mob = rand() % size;
        while (g->f->mobs) {
            if (mob == rand_mob)
                break;
            mob += 1;
            g->f->mobs = g->f->mobs->next;
        }
        mob = 0;
        add_node(g, g->f->mobs, nb_mob);
        g->f->mobs = back;
        nb_mob += 1;
    }
    nb_mob = 0;
}

void add_groupes(general_t *g)
{
    l_mob_all_group_t *node = malloc(sizeof(l_mob_all_group_t));
    node->mob_group = NULL;
    node->next = g->game->list_all_groupe;
    g->game->list_all_groupe = node;
    add_in_group(g);
}

void generate_mob(general_t *g)
{
    g->game->list_all_groupe = NULL;
    int nb_groupes = 0;
    int rand_nb_grp = 0;

    g->g_mapi = 0;
    while (g->maping[g->g_mapi]) {
        if ((rand_nb_grp = rand() % 4) == 0 || !check_map(g->maping[g->g_mapi]->chunk_mapped)) {
            g->g_mapi += 1;
            continue;
        }
        while (nb_groupes < rand_nb_grp) {
            add_groupes(g);
            nb_groupes += 1;
        }
        g->g_mapi += 1;
        nb_groupes = 0;
    }
    g->g_mapi = 0;
}
