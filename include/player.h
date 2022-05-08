/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_
    #include "my_rpg.h"
    #include "mobs.h"

typedef struct resistance {
    int fire_res;
    int water_res;
    int earth_res;
    int air_res;
}resistance_t;

typedef struct info_player {
    char *name_class;
    int pa;
    int max_pa;
    int pm;
    int max_pm;
    int vie;
    int max_vie;
    int inteligence;
    int chance;
    int agilite;
    int force;
    int sagesse;
    int prospection;
    int crit;
    int crit_damage;
    int damage;
    resistance_t *res;
}info_player_t;

typedef struct base_stats {
    int pa;
    int pm;
    int vie;
    int inteligence;
    int chance;
    int agilite;
    int force;
    int damage;
}base_stats_t;

typedef struct list_sort {

}list_sort_t;

typedef struct stat_player {
    char *name;
    char *skin_name;
    int level;
    int xp;
    int kama;
    int point_caract;
    info_player_t *info;
    spells_list_t *sort;
    int god_mod;
    int quete1;
    int quete2;
    int quete3;
}stat_player_t;

typedef struct player_apparence {
    game_object_t *play_inv;
    game_object_t *player;
    game_object_t *go_left;
    game_object_t *go_right;
    game_object_t *go_up;
    game_object_t *go_down;
    game_object_t *coiffe;
    game_object_t *cape;
}player_apparence_t;

typedef struct s_player {
    stat_player_t *stat_player;
    player_apparence_t *player_ap;
    base_stats_t *base_stats;
    int tmp_pos_x;
    int tmp_pos_y;
    int tmp_mp_x;
    int tmp_mp_y;
    int cam_posx;
    int cam_posy;
    int dir_anim;
    int side;

}s_player_t;

#endif
