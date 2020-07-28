/*
** EPITECH PROJECT, 2020
** annim_att
** File description:
** pokemon
*/

#include "../../../include/rpg.h"
#include "../../../include/struct.h"

void draw_anim_fight(all *all, int our, int pok)
{
    oponent(all, pok);
    our_pok_move(all, our);
    sfRenderWindow_clear(all->w, sfWhite);
    sfRenderWindow_drawSprite(all->w, all->fight->sprite_f, NULL);
    sfRenderWindow_drawSprite(all->w, \
    all->our_pok[our]->sprite_f, NULL);
    sfRenderWindow_drawSprite(all->w, \
    all->pokemon[pok]->sprite_f, NULL);
    sfRenderWindow_drawSprite(all->w, all->bar->sprite_f, NULL);
    sfRenderWindow_drawRectangleShape(all->w, all->pokemon[pok]->rect, NULL);
    sfRenderWindow_drawRectangleShape(all->w, all->our_pok[our]->rect, NULL);
    sfRenderWindow_drawSprite(all->w, \
    all->board1[all->our_pok[our]->board1]->sprite_f, NULL);
    sfRenderWindow_drawSprite(all->w, \
    all->board2[all->our_pok[our]->board2]->sprite_f, NULL);
    sfRenderWindow_drawSprite(all->w, \
    all->board3[all->our_pok[our]->board3]->sprite_f, NULL);
    sfRenderWindow_drawSprite(all->w, \
    all->board4[all->our_pok[our]->board4]->sprite_f, NULL);
    sfRenderWindow_drawSprite(all->w, all->pnj_one->text->sprite, NULL);
    sfRenderWindow_display(all->w);
}

int earthquake(all *all, int our)
{
    if (all->anim_att->pos.x == 30)
        all->anim_att->s = 0;
    if (all->anim_att->pos.x == -30)
        all->anim_att->s = 1;
    if (all->anim_att->pos.x == 0)
        all->anim_att->w += 1;
    if (all->anim_att->w == 20)
        return 1;
    if (all->anim_att->s == 0)
        all->anim_att->pos.x -= 10;
    if (all->anim_att->s == 1)
        all->anim_att->pos.x += 10;
    sfSprite_setPosition(all->fight->sprite_f, all->anim_att->pos);
    return 0;
}

int fly(all *all, int our)
{
    if (all->anim_att->s == 0)
        all->anim_att->pok_pos.y -= 10;
    if (all->anim_att->pok_pos.y == -250) {
        all->anim_att->pok_pos.x = 500;
        all->anim_att->s = 1;
    }
    if (all->anim_att->s == 1)
        all->anim_att->pok_pos.y += 10;
    if (all->anim_att->s == 1 && all->anim_att->pok_pos.y >= 50)
        return 1;
    sfSprite_setPosition(all->our_pok[our]->sprite_f, all->anim_att->pok_pos);
    return 0;
}

int dig(all *all, int our, sfVector2f pos_pok)
{
    if (all->anim_att->s == 0)
        all->anim_att->pok_pos.y += 10;
    if (all->anim_att->pok_pos.y == 1200)
        all->anim_att->s = 1;
    if (all->anim_att->s == 1)
        all->anim_att->pok_pos.y -= 10;
    if (all->anim_att->s == 1 && all->anim_att->pok_pos.y == pos_pok.y)
        return 1;
    sfSprite_setPosition(all->our_pok[our]->sprite_f, all->anim_att->pok_pos);
    return 0;
}

int ex_spd(all *all, int our, sfVector2f pos_pok)
{
    if (all->anim_att->s == 0)
        all->anim_att->size.x -= 1;
    if ((all->anim_att->s == 0 || all->anim_att->s == 1) && all->anim_att->size.x <= 1) {
        all->anim_att->s = 1;
        all->anim_att->pok_pos.y -= 20;
    }
    if (all->anim_att->pok_pos.y <= -10)
        all->anim_att->s = 2;
    if (all->anim_att->s == 2) {
        all->anim_att->pok_pos.x = 700;
        all->anim_att->pok_pos.y += 10;
    }
    if (all->anim_att->s == 2 && all->anim_att->pok_pos.y >= 50)
        return 1;
    sfSprite_setPosition(all->our_pok[our]->sprite_f, all->anim_att->pok_pos);
    sfSprite_setScale(all->our_pok[our]->sprite_f, all->anim_att->size);
    return 0;
}

int iron_head(all *all, int our, sfVector2f pos_pok)
{
    sfSprite_setColor(all->our_pok[our]->sprite_f, (sfColor) {47, 79, 79, 250});
    all->anim_att->pok_pos.x += 20;
    all->anim_att->pok_pos.y -= 10;
    if (all->anim_att->pok_pos.x >= 500) return 1;
    sfSprite_setPosition(all->our_pok[our]->sprite_f, all->anim_att->pok_pos);
    return 0;
}

int volt_takle(all *all, int our, sfVector2f pos_pok)
{
    sfSprite_setColor(all->our_pok[our]->sprite_f, (sfColor) {250, 250, 0, 250});
    all->anim_att->pok_pos.x += 20;
    all->anim_att->pok_pos.y -= 10;
    if (all->anim_att->pok_pos.x >= 500) return 1;
    sfSprite_setPosition(all->our_pok[our]->sprite_f, all->anim_att->pok_pos);
    return 0;
}

void anim_att(all *all, int our, int pok, int i)
{
    all->anim_att->color = sfSprite_getColor(all->our_pok[our]->sprite_f);
    all->anim_att->size = all->our_pok[our]->scale;
    all->anim_att->w = 0;
    all->anim_att->s = 0;
    all->anim_att->pos.x = 30;
    all->anim_att->pos.y = 0;
    all->anim_att->pok_pos = sfSprite_getPosition(all->our_pok[our]->sprite_f);
    sfVector2f pos_pok = all->anim_att->pok_pos;
    while (sfRenderWindow_isOpen(all->w)) {
        if (all->our_pok[our]->attack[i]->name == 0) {
            if (earthquake(all, our)) break; }
        else if (all->our_pok[our]->attack[i]->name == 1) {
            if (fly(all, our)) break; }
        else if (all->our_pok[our]->attack[i]->name == 2) {
            if (dig(all, our, pos_pok)) break; }
        else if (all->our_pok[our]->attack[i]->name == 3) {
            if (ex_spd(all, our, pos_pok)) break; }
        else if (all->our_pok[our]->attack[i]->name == 4) {
            if (iron_head(all, our, pos_pok)) break; }
        else if (all->our_pok[our]->attack[i]->name == 5) {
            if (volt_takle(all, our, pos_pok)) break; }
        else
            break;
        draw_anim_fight(all, our, pok);
    }
    sfSprite_setColor(all->our_pok[our]->sprite_f, all->anim_att->color);
    sfSprite_setScale(all->our_pok[our]->sprite_f, all->our_pok[our]->scale);
    sfSprite_setPosition(all->our_pok[our]->sprite_f, pos_pok);
    sfSprite_setPosition(all->fight->sprite_f, (sfVector2f) {0, 0});
}
