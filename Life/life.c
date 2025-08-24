#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if(ac != 4)
		return putchar('e'), 1;
	
	int width = atoi(av[1]);
	int height = atoi(av[2]);
	int iteration = atoi(av[3]);
	
	int arr[2][width + 2][height + 2];
	
	for(int i = 0; i < 2; i++)
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
	while(read(0, &cmd, 1) > 0)
	{
		if(cmd == 'w' && y > 1)
			y--;
		else if(cmd == 'a' && x > 1)
			x--;
		else if(cmd == 's' && y < height)
			y++;
		else if(cmd == 'd' && x < width)
			x++;
		else if(cmd == 'x')
			pen = !pen;
		if(pen)
			arr[0][x][y] = 1;
	}
	
	for(int iter = 0; iter < iteration; iter++)
	{
		for(int h = 1; h < height + 1; h++)
		{
			for(int w = 1; w < width; w++)
			{
				int nb = 0;
				for(int y = -1; y <= 1; y++)
				{
					for(int x = -1; x <= 1; x++)
					{
						if(!(x == 0 && y == 0))
							nb += arr[iter % 2][w + x][h + y];
					}
				}
				if(arr[iter % 2][w][h] == 1)
				{
					if(nb == 2 || nb == 3)
						arr[(iter + 1) % 2][w][h] = 1;
					else
						arr[(iter + 1) % 2][w][h] = 0;
				}
				else
				{
					if(nb == 3)
						arr[(iter + 1) % 2][w][h] = 1;
					else
						arr[(iter + 1) % 2][w][h] = 0;
				}
			}
		}
	}
	
	for(int h = 1; h < height + 1; h++)
	{
		for(int w = 1; w < width + 1; w++)
			putchar(arr[iteration % 2][w][h] ? '0' : ' ');
		putchar('\n');
	}
	return (0);
}

					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
								
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
