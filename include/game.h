/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_
    #include <stdlib.h>
    #include <stdint.h>
    #include <stdarg.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <stddef.h>
    #include <dirent.h>
    #include <getopt.h>
    #include <time.h>
    #include "player.h"
    #include "my_rpg.h"
    #include "fight.h"

typedef struct list_map {
    char **chunk;
    char *name;
    int dificulty;

}list_map_t;

typedef struct god_mode {
    text_gen_t *text_cmd;
    char *cmd;
    game_object_t *terminal;
    int is_visible;
}god_mode_t;

typedef struct l_mob_group {
    mobs_t *mob;
    game_object_t *mob_skin;
    int is_dead;
    struct l_mob_group *next;
}l_mob_group_t;

typedef struct l_mob_all_group {
    l_mob_group_t *mob_group;
    struct l_mob_all_group *next;
}l_mob_all_group_t;

typedef struct pnj {
    game_object_t *pnj1;
    game_object_t *pnj2;
    game_object_t *zaap1;
    game_object_t *s_dialogue;
    game_object_t *pnjdialogue;
    game_object_t *pnjdialogue2;
    text_gen_t *dialogue;
    text_gen_t *nextdialogue;
    int chat;
}pnj_t;

typedef struct general_game {
    sfRenderWindow *window;
    sfView *cam;
    sfView *mini_map;
    sfVideoMode mode;
    sfEvent event;

    sfVector2i mouse;
    sfVector2f pos_mouse;
    l_mob_all_group_t *list_all_groupe;
    int tmp_pos_mobx;
    int tmp_pos_moby;
    int map_visible;
    int file;
    char *login;
    char *pasword_login;
    char *user_name;
    char *new_pasword;
    char *hidden_pasword;
    char *hidd_new_paswd;
    god_mode_t *god_mode;
}general_game_t;

typedef struct struct_clock {
    sfClock *animation;
    sfTime time_anim;
    float second;
}struct_clock_t;
#endif
