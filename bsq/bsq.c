#include "bsq.h"

void	free_bsq(t_bsq *bsq)
{
	if(bsq)
	{
		if(bsq->stream && bsq->stream != stdin)
			free(bsq->stream);
		if(bsq->map)
		{
			int i = -1;
			while(bsq->map[++i])
				free(bsq->map[i]);
			free(bsq->map);
		}
		free(bsq);
	}
}

int	ft_strlen(char **str)
{
	int i = 0;
	while(str && str[i])
		i++;
	return i;
}

int	parse_header(t_bsq *bsq)
{
	int n = fscanf(bsq->stream, "%i%c%c%c\n", &bsq->rows, &bsq->empty, &bsq->obst, &bsq->full);
	if(n != 4 || bsq->rows <= 0
		|| (bsq->empty == bsq->full || bsq->empty == bsq->obst || bsq->full == bsq->obst))
		return (printf("Error: invalid map!\n"), 1);
	return 0;
}



int main(int argc, char **argv)
{
	t_bsq *bsq = calloc(1, sizeof(t_bsq));
	if(!bsq)
		return(printf("Error: allocation failed!\n");
	if(argc == 1)
	{
		bsq->stream = stdin;
	}
	else if(argc == 2)
	{
		bsq->stream = fopen(argv[1], "r");
		if(!bsq->stream)
		{
			free(bsq);
			return (printf("Error: file open failed!\n"), 1);
		}
	}
	else
	{
		free(bsq);
		return(printf("Error: too many arguments!\n"), 1);
	}
	
	
			
	
	
