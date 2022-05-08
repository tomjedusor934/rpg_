/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** registration
*/

#include "../../include/my_rpg.h"

char *concat_names(char *src)
{
    char *final_str = malloc(sizeof(char) * my_strlen(src) + 12);
    char *file = "config/log/";
    int i = 0;
    for (; file[i] != '\0'; i++)
        final_str[i] = file[i];
    for (int x = 0; src[x] != '\0'; i++, x++)
        final_str[i] = src[x];
    final_str[i] = '\0';
    return (final_str);
}

char *w_class(general_t *g)
{
    if (g->selected == IOP)
        return("iop");
    if (g->selected == CRA)
        return ("cra");
    if (g->selected == ENIRIPSA)
        return ("eniripsa");
    if (g->selected == SACRIEUR)
        return ("sacrieur");
    return (NULL);
}

char *choose_skin(general_t *g)
{
    if (g->selected == CRA && g->gender == MAN)
        return ("cra_stop");
    if (g->selected == CRA && g->gender == WOMEN)
        return ("craf_stop");
    if (g->selected == SACRIEUR && g->gender == MAN)
        return ("sac_stop");
    if (g->selected == SACRIEUR && g->gender == WOMEN)
        return ("sacf_stop");
    if (g->selected == IOP && g->gender == MAN)
        return ("iop_stop");
    if (g->selected == IOP && g->gender == WOMEN)
        return ("iopf_stop");
    if (g->selected == ENIRIPSA && g->gender == MAN)
        return ("eni_stop");
    if (g->selected == ENIRIPSA && g->gender == WOMEN)
        return ("enif_stop");
    return (NULL);
}

void creating_files(general_t *g)
{
    g->player->stat_player->info->agilite = 0;
    g->player->base_stats->agilite = 0;
    g->player->stat_player->info->force = 0;
    g->player->base_stats->force = 0;
    g->player->stat_player->info->sagesse = 0;
    g->player->stat_player->info->prospection = 0;
    g->player->stat_player->info->crit = 0;
    g->player->stat_player->info->crit_damage = 0;
    g->player->stat_player->info->damage = 0;
    g->player->stat_player->info->res->fire_res = 0;
    g->player->stat_player->info->res->water_res = 0;
    g->player->stat_player->info->res->earth_res = 0;
    g->player->stat_player->info->res->air_res = 0;
    g->player->stat_player->kama = 100;
    g->player->stat_player->god_mod = 0;
}

void create_files(general_t *g)
{
    g->player->stat_player->name = g->game->user_name;
    g->player->stat_player->info->name_class = w_class(g);
    g->pos_playe_x = 2877;
    g->pos_player_y = 4102;
    init_inventory(g);
    load_player(g, choose_skin(g));
    g->player->stat_player->level = 1;
    g->player->stat_player->point_caract = 0;
    g->player->stat_player->xp = 0;
    g->player->stat_player->info->pa = 6;
    g->player->stat_player->info->max_pa = 6;
    g->player->stat_player->info->pm = 3;
    g->player->stat_player->info->max_pm = 3;
    g->player->stat_player->info->vie = 50;
    g->player->base_stats->vie = 50;
    g->player->stat_player->info->max_vie = 50;
    g->player->stat_player->info->inteligence = 0;
    g->player->base_stats->inteligence = 0;
    g->player->stat_player->info->chance = 0;
    g->player->base_stats->chance = 0;
    creating_files(g);
}

void create_account(general_t *g)
{
    FILE *file = NULL;

    file = fopen(concat_names(g->game->user_name), "w+");
    if (file == NULL)
        return;
    create_files(g);
    g->connect_ok = 1;
}

void write_stats(general_t *g, FILE *file)
{
    fwrite(",", 1, 1, file);
    fwrite(my_int_to_char(g->player->stat_player->info->damage),
    my_strlen(my_int_to_char(g->player->stat_player->info->damage)),
    1, file);
    fwrite(",", 1, 1, file);
    fwrite(my_int_to_char(g->player->stat_player->info->res->fire_res),
    my_strlen(my_int_to_char(g->player->stat_player->info->res->fire_res)),
    1, file);
    fwrite(",", 1, 1, file);
    fwrite(my_int_to_char(g->player->stat_player->info->res->water_res),
    my_strlen(my_int_to_char(g->player->stat_player->info->res->water_res)),
    1, file);
    fwrite(",", 1, 1, file);
    fwrite(my_int_to_char(g->player->stat_player->info->res->earth_res),
    my_strlen(my_int_to_char(g->player->stat_player->info->res->earth_res)),
    1, file);
    fwrite(",", 1, 1, file);
    fwrite(my_int_to_char(g->player->stat_player->info->res->air_res),
    my_strlen(my_int_to_char(g->player->stat_player->info->res->air_res)),
    1, file);
}

void write_next_stats(general_t *g, FILE *file)
{
    fwrite(my_int_to_char(g->player->base_stats->force),
    my_strlen(my_int_to_char(g->player->base_stats->force)),
    1, file);
    fwrite(",", 1, 1, file);
    fwrite(my_int_to_char(g->player->stat_player->info->sagesse),
    my_strlen(my_int_to_char(g->player->stat_player->info->sagesse)),
    1, file);
    fwrite(",", 1, 1, file);
    fwrite(my_int_to_char(g->player->stat_player->info->prospection),
    my_strlen(my_int_to_char(g->player->stat_player->info->prospection)),
    1, file);
    fwrite(",", 1, 1, file);
    fwrite(my_int_to_char(g->player->stat_player->info->crit),
    my_strlen(my_int_to_char(g->player->stat_player->info->crit)),
    1, file);
    fwrite(",", 1, 1, file);
    fwrite(my_int_to_char(g->player->stat_player->info->crit_damage),
    my_strlen(my_int_to_char(g->player->stat_player->info->crit_damage)),
    1, file);
}

void save_stats(general_t *g, FILE *file)
{
    fwrite(my_int_to_char(g->player->base_stats->vie),
    my_strlen(my_int_to_char(g->player->base_stats->vie)),
    1, file);
    fwrite(",", 1, 1, file);
    fwrite(my_int_to_char(g->player->base_stats->inteligence),
    my_strlen(my_int_to_char(g->player->base_stats->inteligence)),
    1, file);
    fwrite(",", 1, 1, file);
    fwrite(my_int_to_char(g->player->base_stats->chance),
    my_strlen(my_int_to_char(g->player->base_stats->chance)),
    1, file);
    fwrite(",", 1, 1, file);
    fwrite(my_int_to_char(g->player->base_stats->agilite),
    my_strlen(my_int_to_char(g->player->base_stats->agilite)),
    1, file);
    fwrite(",", 1, 1, file);
}

void print_stat(general_t *g, FILE *file)
{
    fwrite("\nstats: ", 8, 1, file);
    fwrite(my_int_to_char(g->player->stat_player->info->pa),
    my_strlen(my_int_to_char(g->player->stat_player->info->pa)),
    1, file);
    fwrite(",", 1, 1, file);
    fwrite(my_int_to_char(g->player->stat_player->info->pm),
    my_strlen(my_int_to_char(g->player->stat_player->info->pm)),
    1, file);
    fwrite(",", 1, 1, file);
    save_stats(g, file);
    write_next_stats(g, file);
    write_stats(g, file);
}

void save_middle_stats(general_t *g, FILE *file)
{
    fwrite("\nclass: ", 8, 1, file);
    fwrite(g->player->stat_player->info->name_class,
    my_strlen(g->player->stat_player->info->name_class), 1, file);
    fwrite("\nskin: ", 7, 1, file);
    fwrite(g->player->stat_player->skin_name,
    my_strlen(g->player->stat_player->skin_name), 1, file);
    fwrite("\nlevel: ", 8, 1, file);
    fwrite(my_int_to_char(g->player->stat_player->level),
    my_strlen(my_int_to_char(g->player->stat_player->level)), 1, file);
    fwrite("\nxp: ", 5, 1, file);
    fwrite(my_int_to_char(g->player->stat_player->xp),
    my_strlen(my_int_to_char(g->player->stat_player->xp)), 1, file);
    fwrite("\nequipement: ", 13, 1, file);
}

void save_last_stats(general_t *g, FILE *file)
{
    while (g->inv->equip) {
        if (g->inv->equip->is_eq == 1 && g->inv->equip->name != NULL) {
            fwrite(g->inv->equip->name,
            my_strlen(g->inv->equip->name), 1, file);
            fwrite(",", 1, 1, file);
        }
        g->inv->equip = g->inv->equip->next;
    }
    fwrite("\ninventaire: ", 13, 1, file);
    while(g->inv->slot) {
        if (g->inv->slot->is_empty == 1 && g->inv->slot->name != NULL) {
            fwrite(g->inv->slot->name, my_strlen(g->inv->slot->name), 1, file);
            fwrite(",", 1, 1, file);
        }
        g->inv->slot = g->inv->slot->next;
    }
}

void save_end(general_t *g, FILE *file)
{
    fwrite("\nposition: ", 11, 1, file);
    fwrite(my_int_to_char(g->pos_playe_x),
    my_strlen(my_int_to_char(g->pos_playe_x)), 1, file);
    fwrite(",", 1, 1, file);
    fwrite(my_int_to_char(g->pos_player_y),
    my_strlen(my_int_to_char(g->pos_player_y)), 1, file);
    print_stat(g, file);
    fwrite("\nkama: ", 7, 1, file);
    fwrite(my_int_to_char(g->player->stat_player->kama),
    my_strlen(my_int_to_char(g->player->stat_player->kama)), 1, file);
    fwrite("\ngm: ", 5, 1, file);
    fwrite(my_int_to_char(g->player->stat_player->god_mod), 1, 1, file);

}

void save_game(general_t *g)
{
    FILE *file = NULL;
    if (g->connexion_mode == 2) {
        file = fopen(concat_names(g->game->login), "w+");
        fwrite(g->game->pasword_login,
        my_strlen(g->game->pasword_login), 1, file);
    }
    if (g->connexion_mode == 1) {
        file = fopen(concat_names(g->game->user_name), "w+");
        fwrite(g->game->new_pasword, my_strlen(g->game->new_pasword), 1, file);

    }
    save_middle_stats(g, file);
    save_last_stats(g, file);
    save_end(g, file);

}

char *enregistrement(general_t *g)
{
    FILE *save = NULL;
    char *buffer = NULL;
    size_t len = 0;
    int return_stat = 0;
    struct stat info;

    save = fopen(concat_names(g->game->login), "r+");
    if (save == NULL)
        return (NULL);
    return_stat = stat(concat_names(g->game->login), &info);
    if (return_stat == -1)
        return (NULL);
    buffer = malloc(sizeof(char) * (info.st_size + 1));
    if (buffer == NULL)
        return (NULL);
    len = fread(buffer, 1, info.st_size, save);
    if (len == 0)
        return (NULL);
    buffer[info.st_size] = '\0';
    return (buffer);
}

int check_paswd(general_t *g, char *save)
{
    char **array = str_to_warray(save, '\n');
    if (my_str_compare(g->game->pasword_login, array[0])) {
        return (1);
    } else {
        g->error = 2;
        return (0);
    }
}

void registration(general_t *g)
{
    char *reg = NULL;
    if ((g->game->file == 3 || g->game->file == 4) &&
    (g->game->user_name != NULL && g->game->new_pasword != NULL)) {
        if ((my_strlen(g->game->user_name) != 0 &&
        my_strlen(g->game->new_pasword) != 0) && g->selected != NOTHING) {
            g->connexion_mode = 1;
            create_account(g);
        }
    }
    if ((g->game->file == 1 || g->game->file == 2) &&
    (g->game->login != NULL && g->game->pasword_login != NULL)) {
        reg = enregistrement(g);
        if (reg == NULL) {
            g->error = 1;
        }
        else {
            if (check_paswd(g, reg)) {
                load_inventory(g, reg);
                g->connexion_mode = 2;
                g->connect_ok = 1;
            }
        }
    }
    sfSound_stop(g->menu->s_intro);
}
