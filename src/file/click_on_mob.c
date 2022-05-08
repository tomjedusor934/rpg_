/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** click_on_mob
*/

#include "../../include/my_rpg.h"

int size_list_grp(l_mob_group_t *tmp)
{
    l_mob_group_t *list = tmp;
    int size = 0;
    while (list) {
        size++;
        list = list->next;
    }
    return (size);
}

void prepare_fight(general_t *g, l_mob_group_t *list_groupe)
{
    int size = size_list_grp(list_groupe);
    l_mob_group_t *list = list_groupe;
    char **mob_array = malloc(sizeof(char *) * (size + 1));

    for (int y = 0; y < size && list; y++) {
        mob_array[y] = NULL;
        mob_array[y] = mstrcpy(mob_array[y], list->mob->name);
        list = list->next;
    }
    mob_array[size] = 0;
    list = list_groupe;
    g->file_load = 1;
    sfView_reset(g->game->cam, (sfFloatRect) {0, 0, 1920, 1080});
    sfView_setCenter(g->game->cam, (sfVector2f) {960, 540});
    sfRenderWindow_setView(g->game->window, g->game->cam);
    start_fight(g, mob_array);
}

void click_on_mob(general_t *g)
{
    l_mob_all_group_t *backup = g->game->list_all_groupe;
    l_mob_group_t *cpy = g->game->list_all_groupe->mob_group;
    int touched = 0;
    while (g->game->list_all_groupe) {
        l_mob_group_t *tmp = g->game->list_all_groupe->mob_group;
        while (g->game->list_all_groupe->mob_group) {
            if (is_on_button(g->game->list_all_groupe->mob_group->mob_skin,
            g)) {
                touched = 1;
                cpy = tmp;
            }
            g->game->list_all_groupe->mob_group =
            g->game->list_all_groupe->mob_group->next;
        }
        g->game->list_all_groupe->mob_group = tmp;
        g->game->list_all_groupe = g->game->list_all_groupe->next;
    }
    g->game->list_all_groupe = backup;
    if (touched == 1)
        prepare_fight(g, cpy);
}
