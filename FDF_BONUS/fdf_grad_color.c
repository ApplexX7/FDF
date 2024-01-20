/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradiant_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:52:50 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/19 18:54:20 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int color(int c1, int c2, double per)
{
    return (c1 + (c2 - c1) * per);
}

static unsigned int get_color(int c1, int c2, double per)
{
    int red;
    int blue;
    int green;

    red = color(c1 >> 16 &0xFF, c2 >> 16 &0xFF, per);
    green = color(c1 >> 8 &0xFF, c2 >> 8 &0xFF, per);
    blue = color(c1 &0xFF, c2 &0xFF, per);
    return ((red << 16) | (green << 8) | blue);
}

unsigned int  *gradiant_color(unsigned int color1, unsigned int color2, int nbr)
{
    unsigned int *colr;
    int i;
    int j;
    double per;
    
    colr = malloc(sizeof(unsigned int) * nbr);
    if (!colr)
        return (0);
    i = 1;
    j = 0;
    while(i <= nbr)
    {
        per = (double)i / (double)nbr;
        colr[j] = get_color(color1, color2, per);
        j++;
        i++;
    }
    return (colr);
}
