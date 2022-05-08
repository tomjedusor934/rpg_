/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** load_inventory
*/

#include "../../include/my_rpg.h"

int len_line(char const *str)
{
    int len = 0;
    for (; str[len] != ' ' && str[len] != '\0'; len++);
    return (len + 1);
}

int verif_equipement(char *equipement)
{
    if (compare_wiw("amulette", equipement))
        return (1);
    if (compare_wiw("coiffe", equipement))
        return (2);
    if (compare_wiw("anneaux", equipement))
        return (3);
    if (compare_wiw("cape", equipement))
        return (4);
    if (compare_wiw("ceinture", equipement))
        return (6);
    if (compare_wiw("bottes", equipement))
        return (7);
    if (compare_wiw("bouclier", equipement))
        return (8);
    if (compare_wiw("arme", equipement))
        return (9);
    if (compare_wiw("dofus", equipement))
        return (10);
    return (0);
}

void load_e_i(general_t *g, char *equipement, char *inventory)
{
    equipement += len_line(equipement);
    inventory += len_line(inventory);
    char **equi = str_to_warray(equipement, ',');
    char **inve = str_to_warray(inventory, ',');
    for (int i = 0; equi[i]; i++)
        add_item_to_eq(g, equi[i]);
    for (int y = 0; inve[y]; y++)
        add_item_to_inv(g, inve[y]);

}

void load_pos(general_t *g, char *pos)
{
    char *position = pos;
    int i = 0;
    position += len_line(position);
    g->pos_playe_x = my_atoi(position, 0);
    for (; position[i] != ','; i++);
    g->pos_player_y = my_atoi(position, i);
}

void load_stat(general_t *g, char *stats)
{
    char **array = str_to_warray(stats, ',');
    g->player->stat_player->info->pa = my_atoi(array[0], 0);
    g->player->stat_player->info->max_pa = my_atoi(array[0], 0);
    g->player->stat_player->info->pm = my_atoi(array[1], 0);
    g->player->stat_player->info->max_pm = my_atoi(array[1], 0);
    g->player->stat_player->info->vie = my_atoi(array[2], 0);
    g->player->stat_player->info->max_vie = my_atoi(array[2], 0);
    g->player->stat_player->info->inteligence = my_atoi(array[3], 0);
    g->player->stat_player->info->chance = my_atoi(array[4], 0);
    g->player->stat_player->info->agilite = my_atoi(array[5], 0);
    g->player->stat_player->info->force = my_atoi(array[6], 0);
    g->player->stat_player->info->sagesse = my_atoi(array[7], 0);
    g->player->stat_player->info->prospection = my_atoi(array[8], 0);
    g->player->stat_player->info->crit = my_atoi(array[9], 0);
    g->player->stat_player->info->crit_damage = my_atoi(array[10], 0);
    g->player->stat_player->info->damage = my_atoi(array[11], 0);
    g->player->stat_player->info->res->fire_res = my_atoi(array[12], 0);
    g->player->stat_player->info->res->water_res = my_atoi(array[13], 0);
    g->player->stat_player->info->res->earth_res = my_atoi(array[14], 0);
    g->player->stat_player->info->res->air_res = my_atoi(array[15], 0);
    g->player->stat_player->point_caract = 0;
}

int size_alloc(char *name)
{
    if (name[3] != 'f')
        return (3);
    else
        return (4);
    return(0);
}

char *choose_side(int side)
{
    if (side == 1)
        return ("_backward");
    if (side == 2)
        return ("_forward");
    if (side == 3)
        return ("_left");
    if (side == 4)
        return ("_right");
    return (NULL);
}

char *choose_animation(char *name, int side, int size)
{
    char *str = malloc(sizeof(char) * size + 1);
    char *string = NULL;

    for (int i = 0; i < size; i++)
        str[i] = name[i];
    str[size] = '\0';
    string = mstrcpy(string, "asset/");
    string = mstrcat(string, str);
    string = mstrcat(string, choose_side(side));
    string = mstrcat(string, ".png");
    return (string);
}

void load_player(general_t *g, char *name)
{
    char *str = NULL;
    str = mstrcpy(str, "asset/");
    str = mstrcat(str, name);
    str = mstrcat(str, ".png");
    g->player->stat_player->skin_name = name;
    g->player->player_ap->player = create_object(str, (sfVector2f) {g->pos_playe_x, g->pos_player_y}, (sfIntRect) {0, 0, 200, 300}, (sfVector2f) {0.65, 0.65});
    sfSprite_setOrigin(g->player->player_ap->player->sprite, (sfVector2f) {100, 300});
    sfSprite_setPosition(g->player->player_ap->player->sprite, g->player->player_ap->player->pos);
    g->player->player_ap->play_inv = create_object(str, (sfVector2f) {g->inv->inventaire->pos.x, g->inv->inventaire->pos.y}, (sfIntRect) {0, 0, 200, 300}, (sfVector2f) {1, 1});
    g->player->player_ap->go_up = create_object(choose_animation(name, 1, size_alloc(name)), (sfVector2f) {g->pos_playe_x, g->pos_player_y}, (sfIntRect) {0, 0, 200, 300}, (sfVector2f) {0.65, 0.65});
    sfSprite_setOrigin(g->player->player_ap->go_up->sprite, (sfVector2f) {100, 300});
    sfSprite_setPosition(g->player->player_ap->go_up->sprite, g->player->player_ap->go_up->pos);

    g->player->player_ap->go_down = create_object(choose_animation(name, 2, size_alloc(name)), (sfVector2f) {g->pos_playe_x, g->pos_player_y}, (sfIntRect) {0, 0, 200, 300}, (sfVector2f) {0.65, 0.65});
    sfSprite_setOrigin(g->player->player_ap->go_down->sprite, (sfVector2f) {100, 300});
    sfSprite_setPosition(g->player->player_ap->go_down->sprite, g->player->player_ap->go_down->pos);

    g->player->player_ap->go_left = create_object(choose_animation(name, 3, size_alloc(name)), (sfVector2f) {g->pos_playe_x, g->pos_player_y}, (sfIntRect) {0, 0, 200, 300}, (sfVector2f) {0.65, 0.65});
    sfSprite_setOrigin(g->player->player_ap->go_left->sprite, (sfVector2f) {100, 300});
    sfSprite_setPosition(g->player->player_ap->go_left->sprite, g->player->player_ap->go_left->pos);

    g->player->player_ap->go_right = create_object(choose_animation(name, 4, size_alloc(name)), (sfVector2f) {g->pos_playe_x, g->pos_player_y}, (sfIntRect) {0, 0, 200, 300}, (sfVector2f) {0.65, 0.65});
    sfSprite_setOrigin(g->player->player_ap->go_right->sprite, (sfVector2f) {100, 300});
    sfSprite_setPosition(g->player->player_ap->go_right->sprite, g->player->player_ap->go_right->pos);


    g->player->cam_posx = g->pos_playe_x;
    g->player->cam_posy = g->pos_player_y;
    sfView_setCenter(g->game->cam, (sfVector2f) {g->pos_playe_x, g->pos_player_y});
    sfRenderWindow_setView(g->game->window, g->game->cam);

}

void fill_stat(general_t *g, char **array)
{
    g->player->stat_player->name = g->game->login;
    array[1] += len_line(array[1]);
    g->player->stat_player->info->name_class = array[1];
    load_pos(g, array[7]);
    init_inventory(g);
    array[2] += len_line(array[2]);
    load_e_i(g, array[5], array[6]);
    load_player(g, array[2]);
    g->player->stat_player->level = my_atoi(array[3], 0);
    array[3] += len_line(array[3]);
    g->player->stat_player->xp = my_atoi(array[4], 0);
    array[8] += len_line(array[8]);
    load_stat(g, array[8]);
    g->player->stat_player->kama = my_atoi(array[9], 0);
    g->player->stat_player->god_mod = my_atoi(array[10], 0);
}

void load_inventory(general_t *g, char *file)
{
    char **array = str_to_warray(file, '\n');
    fill_stat(g, array);
    g->player->base_stats->agilite = g->player->stat_player->info->agilite;
    g->player->base_stats->force = g->player->stat_player->info->force;
    g->player->base_stats->inteligence = g->player->stat_player->info->inteligence;
    g->player->base_stats->chance = g->player->stat_player->info->chance;
    g->player->base_stats->vie = g->player->stat_player->info->vie;
}
