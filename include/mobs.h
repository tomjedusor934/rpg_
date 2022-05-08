
/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** mobs
*/

#ifndef MOBS_H_
#define MOBS_H_

#include "game.h"
#include "my_rpg.h"
#include "player.h"
#include "fight.h"

typedef struct item {
    char *name;
    int type;
    //int value;
}item_t;

typedef struct loot_list {
    char *item;
    int drop;
    struct loot_list *next;
}loot_list_t;

typedef struct mobs {
    char *name;
    int level;
    int range;
    int max_damage;
    int min_damage;
    int max_health;
    int min_health;
    int pm;
    int health;
    game_object_t *logo;
    loot_list_t *loot;
    struct mobs *next;
}mobs_t;

typedef struct mobs_fight {
    char *name;
    int health;
    int max_health;
    int range;
    int level;
    int max_damage;
    int min_damage;
    int pm;
    int maxpm;
    int posx;
    int posy;
    int base_posx;
    int base_posy;
    int is_dead;
    game_object_t *mobs;
    struct mobs_fight *next;
}mobs_fight_t;

typedef struct spell {
    char *name;
    int element;
    int pa;
    int min_range;
    int max_range;
    int damage;
    int lifesteal;
    int zone;
    game_object_t *logo;
}spell_t;

typedef struct spells_list {
    spell_t *s;
    struct spells_list *next;
}spells_list_t;

typedef struct spells {
    spells_list_t *eni;
    spells_list_t *iop;
    spells_list_t *sacri;
    spells_list_t *cra;
    spells_list_t *player;
}spells_t;

typedef struct text_f {
    int x;
    int y;
    int value;
}text_f_t;

typedef struct fight {
    mobs_t *mobs;
    mobs_fight_t *mobs_fight;
    int mob_life;
    char *mob_file;
    char *spells_file;
    char **map;
    int max_pm;
    int max_pa;
    int pm;
    int pa;
    int reward_xp;
    int reward_kama;
    int victory_screen;
    char *item_file;
    char **items;
    int is_fg;
    int is_mturn;
    char *str[4];

    game_object_t *go[3];
    game_object_t *logo;
    game_object_t *victory;
    sfFont *font_fight;
    sfText *text_fight;
    spells_t *s;
    spell_t *selected;
    text_f_t *life_text;
}fight_t;

#endif /* !MOBS_H_ */