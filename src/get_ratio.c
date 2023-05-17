/*
 * E89 Pedagogical & Technical Lab
 * project:     2022_surface_git/
 * created on:  Wed May 17 20:07:48 2023
 * 1st author:  user
 * description: get_ratio.c
*/

float get_ratio(int a, int b, int x)
{
    float ratio;
    float i;
    if (a == b){
            return 1;
        }
    i = (b - a);
    ratio = (x - a) / i;
    return ratio;
}
