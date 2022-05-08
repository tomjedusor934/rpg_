/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** init_menu_text
*/

#include "../../include/my_rpg.h"

void init_menu_text4(general_t *g)
{
    g->menu->caractere_female_cra = create_object("asset/cra_pos1.png",
    (sfVector2f) {1420, 430}, (sfIntRect) {0, 0, 95, 235},
    (sfVector2f) {1.5, 1.5});
    g->menu->caractere_male_cra = create_object("asset/cra_pos1_male.png",
    (sfVector2f) {1410, 410}, (sfIntRect) {0, 0, 110, 250},
    (sfVector2f) {1.5, 1.5});
    g->menu->caractere_female_sacrieur =
    create_object("asset/sacrieur_pos1.png",
    (sfVector2f) {1420, 410}, (sfIntRect) {0, 0, 95, 240},
    (sfVector2f) {1.5, 1.5});
    g->menu->caractere_male_sacrieur =
    create_object("asset/sacrieur_pos1_male.png", (sfVector2f) {1410, 420},
    (sfIntRect) {0, 0, 95, 240}, (sfVector2f) {1.5, 1.5});
    g->menu->caractere_female_eniripsa =
    create_object("asset/eniripsa_pos1.png", (sfVector2f) {1380, 380},
    (sfIntRect) {0, 0, 121, 221}, (sfVector2f) {1.8, 1.8});
    g->menu->caractere_male_eniripsa =
    create_object("asset/eniripsa_pos1_male.png", (sfVector2f) {1350, 360},
    (sfIntRect) {0, 0, 140, 240}, (sfVector2f) {1.8, 1.8});
    init_menu_text5(g);
}

void init_menu_text3(general_t *g)
{
    g->menu->carac_iop = create_object("asset/iop_carac.png",
    (sfVector2f) {1250, 380}, (sfIntRect) {0, 0, 485, 470},
    (sfVector2f) {1, 1});
    g->menu->carac_cra = create_object("asset/cra_carac.png",
    (sfVector2f) {1250, 380}, (sfIntRect) {0, 0, 485, 470},
    (sfVector2f) {1, 1});
    g->menu->carac_sacrieur = create_object("asset/sacrieur_carac.png",
    (sfVector2f) {1250, 380}, (sfIntRect) {0, 0, 485, 485},
    (sfVector2f) {1, 1});
    g->menu->carac_eniripsa = create_object("asset/eniripsa_carac.png",
    (sfVector2f) {1250, 380}, (sfIntRect) {0, 0, 485, 470},
    (sfVector2f) {1, 1});
    g->menu->caractere_female_iop = create_object("asset/iop_pos1.png",
    (sfVector2f) {1400, 440}, (sfIntRect) {0, 0, 100, 235},
    (sfVector2f) {1.5, 1.5});
    g->menu->caractere_male_iop = create_object("asset/iop_pos1_male.png",
    (sfVector2f) {1400, 380}, (sfIntRect) {0, 0, 125, 275},
    (sfVector2f) {1.5, 1.5});
    init_menu_text4(g);
}

void init_menu_text2(general_t *g)
{
    g->menu->caractere_plateform = create_object("asset/login_plateform.png",
    (sfVector2f) {1310, 650}, (sfIntRect) {0, 0, 450, 100},
    (sfVector2f) {2.2, 2.2});
    g->menu->class_iop = create_object("asset/iop_head.png",
    (sfVector2f) {1300, 300}, (sfIntRect) {0, 0, 56, 56},
    (sfVector2f) {1.5, 1.5});
    g->menu->class_cra = create_object("asset/cra_head.png",
    (sfVector2f) {1400, 300}, (sfIntRect) {0, 0, 56, 56},
    (sfVector2f) {1.5, 1.5});
    g->menu->class_sacrieur = create_object("asset/sacrieur_head.png",
    (sfVector2f) {1500, 300}, (sfIntRect) {0, 0, 56, 56},
    (sfVector2f) {1.5, 1.5});
    g->menu->class_eniripsa = create_object("asset/eniripsa_head.png",
    (sfVector2f) {1600, 300}, (sfIntRect) {0, 0, 56, 56},
    (sfVector2f) {1.5, 1.5});
    g->menu->select = create_object("asset/select_cell.png",
    (sfVector2f) {1298, 298}, (sfIntRect) {0, 0, 60, 60},
    (sfVector2f) {1.5, 1.5});
    init_menu_text3(g);
}

void init_menu_text1(general_t *g)
{
    g->menu->login_message = create_object("asset/login_message.png",
    (sfVector2f) {85, 150}, (sfIntRect) {0, 0, 450, 100}, (sfVector2f) {1, 1});
    g->menu->login_username = create_object("asset/enter_username.png",
    (sfVector2f) {50, 300}, (sfIntRect) {0, 0, 450, 100}, (sfVector2f) {1, 1});
    g->menu->login_password = create_object("asset/enter_password.png",
    (sfVector2f) {50, 500}, (sfIntRect) {0, 0, 450, 100}, (sfVector2f) {1, 1});
    g->menu->create_message = create_object("asset/create_message.png",
    (sfVector2f) {685, 150}, (sfIntRect) {0, 0, 450, 100},
    (sfVector2f) {1, 1});
    g->menu->create_username = create_object("asset/enter_username.png",
    (sfVector2f) {650, 300}, (sfIntRect) {0, 0, 450, 100},
    (sfVector2f) {1, 1});
    g->menu->create_password = create_object("asset/enter_password.png",
    (sfVector2f) {650, 500}, (sfIntRect) {0, 0, 450, 100},
    (sfVector2f) {1, 1});
    g->menu->class_message = create_object("asset/class_message.png",
    (sfVector2f) {1310, 150}, (sfIntRect) {0, 0, 450, 100},
    (sfVector2f) {1, 1});
    init_menu_text2(g);
}

void init_menu_text(general_t *g)
{
    g->menu->loading_bg = create_object("asset/loading_bg.png",
    (sfVector2f) {-2, 0}, (sfIntRect) {0, 0, 1920, 1080},
    (sfVector2f) {1.005, 1});
    g->menu->loading_bar = create_object("asset/loading_bar.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 100, 1080}, (sfVector2f) {1, 1});
    g->menu->play_but = create_object("asset/play_button.png",
    (sfVector2f) {769, 492}, (sfIntRect) {0, 0, 383, 96}, (sfVector2f) {1, 1});
    g->menu->exit_but = create_object("asset/exit_button.png",
    (sfVector2f) {1269, 492}, (sfIntRect) {0, 0, 383, 96},
    (sfVector2f) {1, 1});
    g->menu->option_but = create_object("asset/option_button.png",
    (sfVector2f) {269, 492}, (sfIntRect) {0, 0, 383, 96}, (sfVector2f) {1, 1});
    g->menu->connect_but = create_object("asset/connect_button.png",
    (sfVector2f) {80, 700}, (sfIntRect) {0, 0, 383, 96}, (sfVector2f) {1, 1});
    g->menu->create_but = create_object("asset/create_button.png",
    (sfVector2f) {685, 700}, (sfIntRect) {0, 0, 383, 96}, (sfVector2f) {1, 1});
    g->menu->login_bg = create_object("asset/bg_log.jpg",
    (sfVector2f) {-2, 0}, (sfIntRect) {0, 0, 1920, 1024},
    (sfVector2f) {1.005, 1.05});
    init_menu_text1(g);
}
