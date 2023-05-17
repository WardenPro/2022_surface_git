/*
 * E89 Pedagogical & Technical Lab
 * project:     2022_surface_git/
 * created on:  Wed May 17 20:07:48 2023
 * 1st author:  user
 * description: get_value.c
*/

int get_value(int a, int b, float ratio)
{
    float tmp;
    int value;
    tmp = (ratio * (b - a) + a);
    value = tmp;
    return value;
}
