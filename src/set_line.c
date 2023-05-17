/*
 * E89 Pedagogical & Technical Lab
 * project:     2022_surface_git/
 * created on:  Wed May 17 20:07:48 2023
 * 1st author:  user
 * description: set_line.c
*/

#include <lapin.h>
#include <unistd.h>
#include <stdlib.h>
#include "stu_surface.h"

void stu_draw_line(t_bunny_pixelarray *px,
                   t_bunny_position *pos_a,
                   t_bunny_position *pos_b,
                   unsigned int color)
{
    int wdiff;
    int hdiff;
    t_bunny_position pos;
    t_bunny_position posb;
    t_bunny_position posa;

    posa.x = pos_a->x;
    posa.y = pos_a->y;
    posb.x = pos_b->x;
    posb.y = pos_b->y;
    if (pos_b->x >= pos_a->x) {
        wdiff = pos_b->x - pos_a->x;
    } else if (pos_b->x < pos_a->x) {
        wdiff = pos_a->x - pos_b->x;
        posa.x = pos_b->x;
        posb.x = pos_a->x;
    }
    if (pos_b -> y >= pos_a ->y){
        hdiff = pos_b -> y  - pos_a -> y;
    } else if (pos_b ->y < pos_a -> y){
        hdiff = pos_a -> y - pos_b ->y;
        posa.y = pos_b -> y;
        posb.y = pos_a ->y;
    }
    if (wdiff < hdiff) {
        pos.y = posa.y;
        while (pos.y <= posb.y) {
            pos.x = get_value(pos_a -> x, pos_b -> x,
                              get_ratio(pos_a -> y,
                                        pos_b ->y, pos.y));
            put_pixel(px,&pos,color);
            pos.y += 1;
        }
    } if (wdiff >= hdiff) {
        pos.x = posa.x;
        while(pos.x <= posb.x){
            pos.y = get_value(pos_a -> y, pos_b -> y,
                              get_ratio(pos_a ->x , pos_b -> x, pos.x));
            put_pixel(px,&pos,color);
            pos.x += 1;
        }
    }
}
