#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	if(ac != 4)
		return putchar('e'), 1;
	int width = atoi(av[1]);
	int height = atoi(av[2]);
	int iteration = atoi(av[3]);
	
	int arr[2][width + 2][height + 2];
	
	for(int i = 0; i < 2 ; i++)
	{
		for(int h = 0; h < height + 2; h++)
		{
			for(int w = 0; w < width + 2; w++)
				arr[i][w][h] = 0;
		}
	}
	
	int x = 1;
	int y = 1;
	int pen = 0;
	char cmd;
	while (read(0, &cmd, 1) > 0)
	{
		if(cmd == 'w' && y > 1			
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
