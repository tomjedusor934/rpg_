/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** my_rpg
*/

#ifndef MY_RPG_H_
    #define MY_RPG_H_

    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <SFML/Audio.h>
    #include <unistd.h>
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <SFML/Audio.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <SFML/Network.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <math.h>
    #include <time.h>

enum scene {
    LOADING = 1,
    LOADED = 2,
    LOGIN = 3,
    LOCKED = 4,
    START_OR_EXIT = 5,
    SETTINGS = 7,
    MAIN_MENU = 8,

    ENIRIPSA = 1,
    CRA = 2,
    IOP = 3,
    SACRIEUR = 4,
    CRACK = 5,
    NOTHING = 0,

    MAN = 1,
    WOMEN = 2,
    UNKNOWN = 3,
};

typedef struct text_gen {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
}text_gen_t;

    #include "menu.h"
    #include "game.h"
    #include "player.h"
    #include "fight.h"
    #include "inventory.h"
    #include "mobs.h"

typedef struct log {
    game_object_t *logo_class;
    stat_player_t log_stat_player;
    char *name;
    char *class_name;
    int level;
    int kama;
    int log_pos_x;
    int log_pos_y;
}log_t;

enum plan {
    MENU = 1,
    GAME = 3,
    CHOOSE = 2,
    SETINGS = 4,
    END = 5,
    CUSTOM = 6,
    PAUSE = 7,
    WIN = 8,
    LOOSE = 9,
    INVENTORY = 10,
    FIGHT = 11,
};

typedef struct trader {
    game_object_t *trader;
    game_object_t *name_trader;
    game_object_t *inv_trader;
    game_object_t *clinv_trader;
    text_gen_t *textprice;
    int open_trader;
    float change_item;
    game_object_t *item1;
    char *name1;
    int price1;
    game_object_t *item2;
    char *name2;
    int price2;
    game_object_t *item3;
    char *name3;
    int price3;
    game_object_t *item4;
    char *name4;
    int price4;
}trader_t;

typedef struct maping_col {
    int chunk_nb;
    char **chunk_mapped;
}maping_col_t;

typedef struct general {
    int mouse_on;
    int selected;
    int gender;
    int scene;
    int plan;
    int surscene;
    int old_scene;
    int var_frames;
    float sec;
    float music;
    float fx;

    general_game_t *game;
    menu_t *menu;
    s_player_t *player;
    inventaire_t *inv;
    trader_t *trader;
    fight_t *f;
    pnj_t *pnj;
    struct_clock_t *s_clock;

    int pos_playe_x;
    int pos_player_y;

    int side;
    int top;

    int connexion_mode;
    int connect_ok;

    int error;

    int i;
    int j;
    int in_mouvement;
    int file_load;
    maping_col_t *maping[73];
    game_object_t *map[100];
    int g_mapi;
    int chunk_nb;
    text_gen_t *login;
    text_gen_t *paswd;
    text_gen_t *user_name;
    text_gen_t *user_paswd;
}general_t;


struct class_object *create_object(const char *path_to_spritesheet,
sfVector2f pos, sfIntRect rect, sfVector2f scale);
int charging_map();
void game_loop(general_t *g);
char *my_int_to_char(int nbr);
void game_loop_menu(general_t *g);
int my_strlen(char const *str);
int intlen(int nb);
void game_loop_fight(general_t *g);
char *my_revstr(char *str);
int my_atoi(char const *str, int pos);
void enter_id(general_t *g, char *new_str, char letter);
void choose_file(general_t *g, char letter);
void registration(general_t *g);
void is_in_spell_range2(general_t *g, int range, int i);
void spell_range2(general_t *g, int range, int i);
char **str_to_warray(char *str, char const del);
int my_str_compare(char *str , char *str2);
text_gen_t *text_gener(char *str, sfVector2f pos, int size);
void load_inventory(general_t *g, char *file);
void init_all_struct(general_t *g);
int count_line(char *str);

// inventory

void add_slot(general_t *g, int empty, int i, int y);
void add_sloteq(general_t *g, int empty, int item_type, float x, int y);

void init_inventory(general_t *general);
void set_stat(general_t *g);

void draw_inv(general_t *general);
void draw_items(general_t *g);

void drack_and_drop(general_t *g);

void dad_eq(general_t *g);
void move_eq(general_t *g);
void dad_item(general_t *g);
void move_item(general_t *g);
int is_on_button_mvinv(general_t *g);
int bouton_inv_toeq(general_t *g, slot_t *item);
int bouton_eq_toinv(general_t *g, equip_t *item);
int bouton_inv_eq(general_t *g);
int is_on_button_clinv(general_t *g);

void bouton_inv_move(general_t *g);
void bouton_inv_reset(general_t *g);

int bouton_inv_item(general_t *g);
int bouton_inv_item_move(general_t *g);
void levelup(general_t *g);

void class_message(general_t *g);
void class_eniripsa(general_t *g);
void class_cra(general_t *g);
void class_sacrieur(general_t *g);
void class_iop(general_t *g);
void mouse_on(general_t *g);
void login_menu(general_t *g);
void log_one(general_t *g);
void log_two(general_t *g);
void loading_menu(general_t *g);
int is_on_button(game_object_t *button, general_t *g);
void reset_rects(general_t *g);
void menu(general_t *g);


char *mstrcat(char *a, char const *b);
char *mstrcpy(char *a, char const *b);
int mstrlen(char const *s);
void check_events(general_t *g);
void user_name_and_login(general_t *g);
void draw_all(general_t *g);
int is_on_button(game_object_t *button, general_t *g);
int add_item_to_inv(general_t *g, char *name);
void save_game(general_t *g);
char *my_int_to_char(int nbr);
int compare_wiw(char *desired, char *str);
int add_item_to_eq(general_t *g, char *name);
int verif_equipement(char *equipement);
void load_player(general_t *g, char *name);
void dad_item(general_t *g);
void dad_eq(general_t *g);
void dad_ep_item(general_t *g);
void dad_inv_eq(general_t *g);
void dad_inv_slot(general_t *g);
void *mouse_deplacement(general_t *g, int pos_x, int pos_y);
int set_speed(sfVector2f start, sfVector2f dest);
int set_x(sfVector2f turret_pos, sfVector2f mob_pos, int i, int j);
int set_y(sfVector2f turret_pos, sfVector2f mob_pos, int i, int j);
void init_map(general_t *g);
void *arrow_deplacement(general_t *g);
void where_i_am(general_t *g);
void recenter_cam(general_t *g);
int charging_map(general_t *g);
int check_colision(general_t *g, int pos_x, int pos_y);

//trader
void trader_randitem(general_t *g);
void draw_trader(general_t *g);
void init_trader(general_t *g, sfVector2f pos);
void open_trader(general_t *g);


//fight
void draw_line(general_t *g, int y);
void draw_line2(general_t *g, int y, int x);
void draw_map(general_t *g);
char *remove_line(char *str);
char *get_str_until(char *str, char separator);
void init_mobs(general_t *g);
char *load_file(char *filepath);
mobs_t *set_mob_drops(mobs_t *mob, general_t *g);
mobs_t *set_mob_stats(general_t *g);
void load_m(char *filepath, general_t *g);
void init_fight(general_t *g);
void player_move(sfVector2i *pos, general_t *g, int range);
void start_fight(general_t *g, char **mob_list);
void display_test_fight(general_t *g);

sfVector2i *get_player_pos(general_t *g);
void reset_map(general_t *g);
void fight_move(general_t *g, int y, int x);
void left_click(general_t *g, int y, int x);
int is_on_button(game_object_t *button, general_t *g);


int mstrcmp(char const *a, char const *b);
void find_mob(general_t *g, char **array);
void mobs_turn(general_t *g);
int range_attack(general_t *g);
void get_mobs_pos(general_t *g);
void player_turn(general_t *g);
void init_spells(general_t *g);
void set_spells_sacri(general_t *g);
void set_spells_iop(general_t *g);
void set_spells_cra(general_t *g);
void set_spells_eni(general_t *g);
char *astrcat(char *str1, char *str2, char *str3);
void display_fight(general_t *g);
void is_dead(general_t *g);
void print_text_fight(general_t *g, int x, int y, int text);
void spell_range(sfVector2i *pos, general_t *g, int range, int min_range);
int is_in_spell_range(general_t *g, sfVector2i mob, int range, int min_range);
void reset_the_map(general_t *g);
void clock_animation(general_t *g, int dir);
text_gen_t *text_gener2(char *str, sfVector2f pos, int size);
void write_cmd(general_t *g, char letter, char *str);
void generate_mob(general_t *g);
void display_mobs(general_t *g);
void display_victory(general_t *g);

void ch_loaded(general_t *g);
void ch_login_and_locked(general_t *g);
void ch_main(general_t *g);
void key_open_mm(general_t *g);
void ch_settings(general_t *g);
void draw_all(general_t *g);
void class_iop(general_t *g);
void class_sacrieur(general_t *g);
void class_cra(general_t *g);
void class_eniripsa(general_t *g);
void class_message(general_t *g);
void loading_menu(general_t *g);
void option_menu(general_t *g);
void main_menu(general_t *g);
void login_menu(general_t *g);
void log_three(general_t *g);
void log_two(general_t *g);
void log_one(general_t *g);
void menu(general_t *g);
void on_loaded(general_t *g);
void on_locked_scene(general_t *g);
void on_login_and_locked(general_t *g);
void on_main(general_t *g);
void on_settings(general_t *g);
void framerates(general_t *g, char mol);
void init_variables(general_t *g);
void user_name_and_login(general_t *g);
int size_list(general_t *g);
int size_list_grp(l_mob_group_t *tmp);
void click_on_mob(general_t *g);
void check_cmd(general_t *g);
void charging_pnj(general_t *g);
void all_init(general_t *g);
void init_menu_text(general_t *g);
void init_menu_text5(general_t *g);
void musics(general_t *g);
void mu_released(general_t *g);
void mu_clicked(general_t *g);
void mu_intro(general_t *g);
void print_carac(general_t *g);
void print_text(general_t *g, int x, int y, int text);
void draw_text(general_t *g);
int add_item_to_eq(general_t *g, char *name);
int add_item_to_inv(general_t *g, char *name);
void malloc_structs(general_t *g);

void quete_action(general_t *g);
void change_dialogue(general_t *g);
void draw_dialogur(general_t *g);
void dialogue_pnj(general_t *g);
void init_dialogue(general_t *g);
int is_on_text(text_gen_t *button, general_t *g);
void create_view(general_t *g);
void create_text(general_t *g);
void all_game_event1(general_t *g);
void cheat_cmd(general_t *g);
void op_inv(general_t *g);
void op_carac(general_t *g);
void update_stat(general_t *g);
void manage_quest(general_t *g);
void pole_event(general_t *g);

#endif
