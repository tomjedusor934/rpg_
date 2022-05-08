/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** menu
*/

#ifndef MENU_H_
    #define MENU_H_
    #include "my_rpg.h"

typedef struct class_object {
    sfTexture *tex;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f scale;
    sfVector2f pos;

}game_object_t;

typedef struct menu {
    game_object_t *loading_bg;
    game_object_t *login_bg;

    game_object_t *loading_bar;
    game_object_t *vertical_bar;

    game_object_t *play_but;
    game_object_t *exit_but;
    game_object_t *option_but;
    game_object_t *connect_but;
    game_object_t *create_but;
    game_object_t *lock_but;

    game_object_t *login_message;
    game_object_t *create_message;
    game_object_t *class_message;
    game_object_t *username_error_message;
    game_object_t *password_error_message;
    game_object_t *class_error_message;

    game_object_t *login_username;
    game_object_t *create_username;

    game_object_t *login_password;
    game_object_t *create_password;

    game_object_t *class_cra;
    game_object_t *class_eniripsa;
    game_object_t *class_iop;
    game_object_t *class_sacrieur;

    game_object_t *carac_cra;
    game_object_t *carac_eniripsa;
    game_object_t *carac_iop;
    game_object_t *carac_sacrieur;

    game_object_t *select;
    game_object_t *caractere_male_cra;
    game_object_t *caractere_female_cra;
    game_object_t *caractere_male_eniripsa;
    game_object_t *caractere_female_eniripsa;
    game_object_t *caractere_male_iop;
    game_object_t *caractere_female_iop;
    game_object_t *caractere_male_sacrieur;
    game_object_t *caractere_female_sacrieur;
    game_object_t *caractere_unidentified;
    game_object_t *caractere_plateform;

    game_object_t *logo_female;
    game_object_t *logo_male;
    game_object_t *logo_unidentified;

    game_object_t *animation;

    game_object_t *main_menu;
    game_object_t *mm_option;
    game_object_t *mm_resume;
    game_object_t *mm_exit;

    game_object_t *mom_cross;

    game_object_t *option_menu;
    game_object_t *om_musique;
    game_object_t *om_less1;
    game_object_t *om_more1;

    game_object_t *om_fx;
    game_object_t *om_less2;
    game_object_t *om_more2;

    game_object_t *om_fps;
    game_object_t *om_less3;
    game_object_t *om_more3;

    game_object_t *sm_crack;

    sfSound *s_intro;
    sfSoundBuffer *b_intro;

    sfSound *s_clicked;
    sfSoundBuffer *b_clicked;

    sfSound *s_released;
    sfSoundBuffer *b_released;

}menu_t;

#endif