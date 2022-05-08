/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** init_mobs
*/

#include "../../include/my_rpg.h"

char *load_file(char *filepath)
{
    struct stat buff;
    stat(filepath, &buff);
    char *buffer = malloc(sizeof(char) * (buff.st_size + 1));
    int file = open(filepath, O_RDONLY);
    int reading_file = read(file, buffer, buff.st_size);
    buffer[reading_file] = '\0';
    return buffer;
}

void init_mobs(general_t *g)
{
    int line = 0;
    mobs_t *mobs = malloc(sizeof(mobs_t));
    g->f->mob_file = load_file("src/file/mobs.txt");
    mobs = set_mob_stats(g);
    mobs->next = g->f->mobs;
    g->f->mobs = mobs;
    g->f->mob_file += 3;
    line = count_line(g->f->mob_file);
    for (int i = 0; i != line; i++) {
        mobs = mobs->next;
        mobs = set_mob_stats(g);
        mobs->next = g->f->mobs;
        g->f->mobs = mobs;
        mobs = malloc(sizeof(mobs_t));
    }
}

mobs_t *set_mob_drops(mobs_t *mob, general_t *g)
{
    loot_list_t *loot = malloc(sizeof(loot_list_t));
    loot_list_t *backup = loot;
    int i = 0;

    loot->item = get_str_until(g->f->mob_file, ':');
    g->f->mob_file = g->f->mob_file + my_strlen(get_str_until(g->f->mob_file, ':')) + 1;
    loot->drop = my_atoi(g->f->mob_file, 0);
    g->f->mob_file = g->f->mob_file + intlen(my_atoi(g->f->mob_file, 0)) + 1;
    while (g->f->mob_file[i] != '/' && g->f->mob_file[i] != '\n') {
        loot->next = malloc(sizeof(loot_list_t));
        loot = loot->next;
        loot->item = get_str_until(g->f->mob_file, ':');
        g->f->mob_file = g->f->mob_file + my_strlen(get_str_until(g->f->mob_file, ':')) + 1;
        loot->drop = my_atoi(g->f->mob_file, 0);
        g->f->mob_file = g->f->mob_file + intlen(my_atoi(g->f->mob_file, 0));
        (g->f->mob_file[0] == ';' ? g->f->mob_file++ : 0);
    }
    mob->loot = backup;
    return mob;
}

mobs_t *set_mob_stats(general_t *g)
{
    mobs_t *mob = malloc(sizeof(mobs_t));
    if (g->f->mob_file[0] == '/')
        g->f->mob_file += 3;
    mob->name = get_str_until(g->f->mob_file, ';');
    mob->logo = create_object(astrcat("asset/", mob->name, ".png"), (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 200, 200}, (sfVector2f) {0.26, 0.26});
    g->f->mob_file = g->f->mob_file + my_strlen(get_str_until(g->f->mob_file, ';')) + 1;
    mob->level = my_atoi(g->f->mob_file, 0);
    g->f->mob_file = g->f->mob_file + intlen(my_atoi(g->f->mob_file, 0)) + 1;
    mob->pm = my_atoi(g->f->mob_file, 0);
    g->f->mob_file = g->f->mob_file + intlen(my_atoi(g->f->mob_file, 0)) + 1;
    mob->range = my_atoi(g->f->mob_file, 0);
    g->f->mob_file = g->f->mob_file + intlen(my_atoi(g->f->mob_file, 0)) + 1;
    mob->min_damage = my_atoi(g->f->mob_file, 0);
    g->f->mob_file = g->f->mob_file + intlen(my_atoi(g->f->mob_file, 0)) + 1;
    mob->max_damage = my_atoi(g->f->mob_file, 0);
    g->f->mob_file = g->f->mob_file + intlen(my_atoi(g->f->mob_file, 0)) + 1;
    mob->min_health = my_atoi(g->f->mob_file, 0);
    g->f->mob_file = g->f->mob_file + intlen(my_atoi(g->f->mob_file, 0)) + 1;
    mob->max_health = my_atoi(g->f->mob_file, 0);
    g->f->mob_file = g->f->mob_file + intlen(my_atoi(g->f->mob_file, 0)) + 1;
    mob = set_mob_drops(mob, g);
    return mob;
}
