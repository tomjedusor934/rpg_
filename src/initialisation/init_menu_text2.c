/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** init_menu_text
*/

#include "../../include/my_rpg.h"

void init_menu_text9(general_t *g)
{
    g->menu->om_more2 = create_object("asset/lam_cross.png",
    (sfVector2f) {g->menu->om_musique->pos.x + 314 * 1.5,
    g->menu->om_musique->pos.y},
    (sfIntRect) {0, 0, 27, 28}, (sfVector2f) {1.5, 1.5});
    g->menu->om_more3 = create_object("asset/lam_cross.png",
    (sfVector2f) {g->menu->om_fx->pos.x + 314 * 1.5, g->menu->om_fx->pos.y},
    (sfIntRect) {0, 0, 27, 28}, (sfVector2f) {1.5, 1.5});
    g->menu->sm_crack = create_object("asset/sm_crack.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 27, 28}, (sfVector2f) {1.5, 1.5});
    g->game->god_mode->terminal = create_object("asset/a.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 789, 452}, (sfVector2f) {1, 1});
}

void init_menu_text8(general_t *g)
{
    g->menu->om_musique = create_object("asset/lam_bar.png",
    (sfVector2f) {g->menu->option_menu->pos.x + 385 * 1.5, 475},
    (sfIntRect) {682, 0, 341, 28}, (sfVector2f) {1.5, 1.5});
    g->menu->om_fx = create_object("asset/lam_bar.png",
    (sfVector2f) {g->menu->option_menu->pos.x + 385 * 1.5, 610},
    (sfIntRect) {682, 0, 341, 28}, (sfVector2f) {1.5, 1.5});
    g->menu->om_less1 = create_object("asset/lam_cross.png",
    (sfVector2f) {g->menu->om_fps->pos.x, g->menu->om_fps->pos.y},
    (sfIntRect) {0, 0, 27, 28}, (sfVector2f) {1.5, 1.5});
    g->menu->om_less2 = create_object("asset/lam_cross.png",
    (sfVector2f) {g->menu->om_musique->pos.x, g->menu->om_musique->pos.y},
    (sfIntRect) {0, 0, 27, 28}, (sfVector2f) {1.5, 1.5});
    g->menu->om_less3 = create_object("asset/lam_cross.png",
    (sfVector2f) {g->menu->om_fx->pos.x, g->menu->om_fx->pos.y},
    (sfIntRect) {0, 0, 27, 28}, (sfVector2f) {1.5, 1.5});
    g->menu->om_more1 = create_object("asset/lam_cross.png",
    (sfVector2f) {g->menu->om_fps->pos.x + 314 * 1.5, g->menu->om_fps->pos.y},
    (sfIntRect) {0, 0, 27, 28}, (sfVector2f) {1.5, 1.5});
    init_menu_text9(g);
}

void init_menu_text7(general_t *g)
{
    g->menu->mm_resume =
    create_object("asset/mm_resume_button.png",
    (sfVector2f) {g->menu->main_menu->pos.x + 50 * 2,
    g->menu->main_menu->pos.y + 114 * 2}, (sfIntRect) {0, 0, 283, 29},
    (sfVector2f) {2, 2});
    g->menu->mm_exit = create_object("asset/mm_exit_button.png",
    (sfVector2f) {g->menu->main_menu->pos.x + 50 * 2,
    g->menu->main_menu->pos.y + 177 * 2}, (sfIntRect) {0, 0, 283, 29},
    (sfVector2f) {2, 2});
    g->menu->mom_cross = create_object("asset/cross.png",
    (sfVector2f) {g->menu->main_menu->pos.x + 354 * 2,
    g->menu->main_menu->pos.y + 8 * 2}, (sfIntRect) {0, 0, 27, 28},
    (sfVector2f) {2, 2});
    g->menu->option_menu = create_object("asset/options_page.png",
    (sfVector2f) {270, 150}, (sfIntRect) {0, 0, 906, 438},
    (sfVector2f) {1.5, 1.5});
    g->menu->om_fps = create_object("asset/lam_bar.png",
    (sfVector2f) {g->menu->option_menu->pos.x + 385 * 1.5, 345},
    (sfIntRect) {1364, 0, 341, 28}, (sfVector2f) {1.5, 1.5});
    init_menu_text8(g);
}

void init_menu_text6(general_t *g)
{
    g->menu->logo_female =
    create_object("asset/female_logo.png", (sfVector2f) {1700, 470},
    (sfIntRect) {0, 0, 50, 50}, (sfVector2f) {1.3, 1});
    g->menu->logo_male =
    create_object("asset/male_logo.png", (sfVector2f) {1710, 540},
    (sfIntRect) {0, 0, 50, 50}, (sfVector2f) {1, 1});
    g->menu->logo_unidentified =
    create_object("asset/unknown_logo.png", (sfVector2f) {1705, 610},
    (sfIntRect) {0, 0, 50, 50}, (sfVector2f) {1, 1});
    g->menu->animation = create_object("asset/animation.png",
    (sfVector2f) {0, 0}, (sfIntRect) {8800, 0, 400, 226},
    (sfVector2f) {4.8, 4.7});
    g->menu->main_menu = create_object("asset/main_menu.png",
    (sfVector2f) {565, 250}, (sfIntRect) {0, 0, 390, 236},
    (sfVector2f) {2, 2});
    g->menu->mm_option = create_object("asset/mm_option_button.png",
    (sfVector2f) {g->menu->main_menu->pos.x + 50 * 2,
    g->menu->main_menu->pos.y + 52 * 2}, (sfIntRect) {0, 0, 283, 29},
    (sfVector2f) {2, 2});
    init_menu_text7(g);
}

void init_menu_text5(general_t *g)
{
    g->menu->caractere_unidentified =
    create_object("asset/helicopter_de_combat.png", (sfVector2f) {1170, 400},
    (sfIntRect) {0, 0, 900, 460}, (sfVector2f) {0.7, 0.7});
    g->menu->username_error_message =
    create_object("asset/username_error_message.png", (sfVector2f) {47, 370},
    (sfIntRect) {0, 0, 450, 100}, (sfVector2f) {1.2, 1.2});
    g->menu->password_error_message =
    create_object("asset/password_error_message.png", (sfVector2f) {47, 570},
    (sfIntRect) {0, 0, 450, 100}, (sfVector2f) {1.2, 1.2});
    g->menu->class_error_message =
    create_object("asset/class_error_message.png", (sfVector2f) {1263, 350},
    (sfIntRect) {0, 0, 450, 100}, (sfVector2f) {1.2, 1.2});
    g->menu->vertical_bar =
    create_object("asset/vertical_bar.png", (sfVector2f) {575, 100},
    (sfIntRect) {0, 0, 6, 500}, (sfVector2f) {1, 1.5});
    g->menu->lock_but =
    create_object("asset/lock_button.png", (sfVector2f) {1300, 700},
    (sfIntRect) {0, 0, 383, 96}, (sfVector2f) {1, 1});
    init_menu_text6(g);
}
