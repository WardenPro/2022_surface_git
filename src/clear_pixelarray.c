/*
 * E89 Pedagogical & Technical Lab
 * project:     2022_surface_git/
 * created on:  Wed May 17 20:07:48 2023
 * 1st author:  user
 * description: clear_pixelarray.c
*/

#include <lapin.h> // For all bunny_ things
#include <unistd.h> // For usleep
#include <stdlib.h> // For EXIT_SUCCESS

void clear_pixelarray(t_bunny_pixelarray *pxa,
                      unsigned int color)
{
    int width = pxa->clipable.clip_width;
    int height = pxa->clipable.clip_height;
    int px = width * height;
    int i = 0;
    unsigned int *tmp =  (unsigned int *) pxa -> pixels;
    while(i <= px)
        {
            tmp[i] = color;
            i = i + 1;
        }

}
