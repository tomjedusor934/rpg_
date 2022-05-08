/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** quetes
*/

#include "../../include/my_rpg.h"

static char *str[] = {"Quelle belle journee, n'est-ce pas ? Le soleil brille,\
les pious gazouillent... et les jeunes\n\
ames decouvrent les terres d'Incarnam.", "Ah, la fougue de l\
a jeunesse ! Incarnam n'est pas une region tres etendue, tu n'\
auras\n\
pas besoin d'user tes semelles pour decouvrir ses sites pittor\
esques. Mais lorsque tu\n\
te rendras sur le Monde des Douze, tu devras traverser des ete\
ndues bien plus vastes\n\
I Si tu aimes voyager et decouvrir de nouvelles contrees, je t\
e conseille d'utiliser les\n\
zaaps pour te deplacer plus rapidement et economiser tes force\
s.", "Pour se deplacer en passant a travers un zaap d'incarn\
am, il faut moins de 20 kamas.\n\
Plus tu vas loin, et plus le cout est eleve. Mieux vaut donc g\
arder quelques pieces en\n\
poche lors de tes voyages !", "Tout ce que je sais, c'est qu\
'il faut deja s'etre rendu sur le site d'un portail avant de\n\
pouvoir l'utiliser. Autrement dit, tu ne peux pas te deplacer\
instantanement vers un\n\
endroit que tu n'as jamais visite auparavant... Du moins, c'es\
t comme ça que la plupart\n\
des zaaps fonctionnent.", "Si tu veux en savoir plus sur ce\
sujet, interroge Xelora. Elle s'occupe de l'entretien des\n\
zaaps de l'île celeste,", "En ce moment, je crois qu'elle tr\
availle sur le zaap des paturages, au nord-est du\n\
village.", "Si je n'etais pas la, les zaaps tomberaient tout\
 le temps en panne. Heureusement, je\n\
sais y faire : un bon coup de marteau, et hop, ça repart !",\
"Je ne peux devoiler les secrets du Maître du Temps, neanmoin\
s tu apprendras vite que\n\
les Xelors sont toujours en retard. Alors pour nous donner un\
temps d'avance, notre\n\
dieu a cree les zaaps et les zaapis. Les zaapis sont des petit\
s zaaps a quelques kamas\n\
que tu decouvriras plus tard, quand tu visiteras les cites du\
Monde des Douze.", "Tu es bien curieux ! C'est un mystere co\
nnu seulement des Xelors et autres inities.\n\
Mais comme tu m'es sympathique, je veux bien te faire quelques\
 revelations...", "Voila ce que je sais : les zaaps sont des\
  fragments de Xelor lui-meme. Il les a plant\n\
dans le sol du monde pour nous aider a le servir avec plus de\
celerite. Ces fragments\n\
se nourrissent de l'energie degagee par les kamas. Mais certai\
ns vieillissent mal... De\n\
ce fait, ils se mettent en veille le temps d'absorber le trop-\
plein d'energie. C'est pour ça\n\
qu'avec ce marteau, je leur tape dessus pour qu'ils se reveill\
ent ! Je cogne le jour, la\n\
nuit, et j'y mets tout mon cour !", "Quand tu voudras retour\
ner au village, utilise le zaap, ce sera plus rapide ! Certes,\
 tu\n\
perdras un peu d'argent au passage, mais je suis sure que tu r\
ecupereras des kamas\n\
facilement... recuperer du temps perdu, c'est nettement plus d\
ifficile, tu peux me croire", "Quelle belle journee, n'est-c\
e pas ? Le soleil brille, les pious gazouillent... et les jeun\
es\n\
ames decouvrent les terres d'Incarnam.", NULL};

static char *str2[] = {"Dire que vous etes impatient d'explorer l'ile celeste.\
", " Demander ce que sont les zaaps.", "Se renseigner su\
r le cout en kamas.", "Demander comment fonctionnent les z\
aaps.", "Demander ou se trouve Xelora.", "Prendre la di\
rection des paturages d'incarnam.", "L'interroger sur l'o\
rigine des zaaps.", "Lui demander comment elle peut repar\
er un zaap avec un marteau.", "ecouter la suite.", "Fai\
re comme si vous aviez tout compris et la remercier pour se\
s explications.", "Examiner le zaap juste a proximite.",
"Dire que vous avez parle a Xelora.", NULL};


void init_dialogue(general_t *g)
{
    g->pnj->chat = 0;
    g->player->stat_player->quete1 = 0;
    g->pnj->dialogue = text_gener(str[0], (sfVector2f) {0, 0}, 15);
    sfText_setColor(g->pnj->dialogue->text, sfWhite);
    g->pnj->nextdialogue = text_gener(str2[0], (sfVector2f) {0, 0}, 15);
    sfText_setColor(g->pnj->nextdialogue->text, sfGreen);
    g->pnj->s_dialogue = create_object("asset/dalogue.png", (sfVector2f) 
    {0, 0}, (sfIntRect) {0, 0, 722, 154}, (sfVector2f) {1.5, 1.5});
}


void change_dialogue(general_t *g)
{
    int i = g->player->stat_player->quete1;
    if ((i == 1 || i == 3 || i == 5) &&
    is_on_text(g->pnj->nextdialogue, g) == 1) {
        g->pnj->chat++;
        sfText_setString(g->pnj->dialogue->text, str[g->pnj->chat]);
        sfText_setString(g->pnj->nextdialogue->text, str2[g->pnj->chat]);
        if (g->pnj->chat == 6 || g->pnj->chat == 11 || g->pnj->chat == 12)
            g->player->stat_player->quete1++;
    }
}

void draw_dialogur(general_t *g)
{
    int i = g->player->stat_player->quete1;
    if (i == 1 || i == 3 || i == 5) {
        sfRenderWindow_drawText(g->game->window, g->pnj->dialogue->text,
        NULL);
        sfRenderWindow_drawText(g->game->window, g->pnj->nextdialogue->text,
        NULL);
    }
}

void dialogue_pnj(general_t *g)
{
    sfRenderWindow_drawSprite(g->game->window ,g->pnj->pnj1->sprite, NULL);
    sfRenderWindow_drawSprite(g->game->window ,g->pnj->pnj2->sprite, NULL);
    (g->player->stat_player->quete1 == 1 ? sfRenderWindow_drawSprite(g->game->
    window ,g->pnj->s_dialogue->sprite, NULL) : 0);
    (g->player->stat_player->quete1 == 3 ? sfRenderWindow_drawSprite(g->game->
    window ,g->pnj->s_dialogue->sprite, NULL) : 0);
    (g->player->stat_player->quete1 == 5 ? sfRenderWindow_drawSprite(g->game->
    window ,g->pnj->s_dialogue->sprite, NULL) : 0);
}

void quete_action2(general_t *g)
{
    (is_on_button(g->pnj->pnj1, g) == 1 && g->player->stat_player->quete1 == 4 ?
    g->player->stat_player->quete1 = 5, g->pnj->s_dialogue->pos = (sfVector2f)
    {g->player->cam_posx + 430, g->player->cam_posy + 830},
    g->pnj->dialogue->pos = (sfVector2f) {g->pnj->s_dialogue->pos.x + 20 ,
    g->pnj->s_dialogue->pos.y + 25},
    g->pnj->nextdialogue->pos = (sfVector2f) {g->pnj->s_dialogue->pos.x + 120,
    g->pnj->s_dialogue->pos.y + 165},
    change_dialogue(g) : 0);
    sfSprite_setPosition(g->pnj->s_dialogue->sprite, g->pnj->s_dialogue->pos);
    sfText_setPosition(g->pnj->dialogue->text, g->pnj->dialogue->pos);
    sfText_setPosition(g->pnj->nextdialogue->text, g->pnj->nextdialogue->pos);
}

void quete_action(general_t *g)
{
    (is_on_button(g->pnj->pnj1, g) == 1 && g->player->stat_player->quete1 == 0
    ? g->player->stat_player->quete1 = 1, g->pnj->s_dialogue->pos =
    (sfVector2f) {g->player->cam_posx + 430, g->player->cam_posy + 830},
    g->pnj->dialogue->pos = (sfVector2f) {g->pnj->s_dialogue->pos.x + 20 , g->
    pnj->s_dialogue->pos.y + 25},
    g->pnj->nextdialogue->pos = (sfVector2f) {g->pnj->s_dialogue->pos.x + 120
    , g->pnj->s_dialogue->pos.y + 165},
    change_dialogue(g) : 0);
    (is_on_button(g->pnj->pnj2, g) == 1 && g->player->stat_player->quete1 == 2 ?
    g->player->stat_player->quete1 = 3, g->pnj->s_dialogue->pos = (sfVector2f)
    {g->player->cam_posx + 430, g->player->cam_posy + 830},
    g->pnj->dialogue->pos = (sfVector2f) {g->pnj->s_dialogue->pos.x + 20 ,
    g->pnj->s_dialogue->pos.y + 25},
    g->pnj->nextdialogue->pos = (sfVector2f) {g->pnj->s_dialogue->pos.x + 120 ,
    g->pnj->s_dialogue->pos.y + 165},
    change_dialogue(g) : 0);
    quete_action2(g);
}
