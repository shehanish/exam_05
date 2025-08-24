#ifndef BSQ_H
#define BSQ_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_bsq
{
	int rows;
	int cols;
	
	int empty;
	int full;
	int obst;
	
	char **map;
	FILE *stream;
} 	t_bsq;

#endif

