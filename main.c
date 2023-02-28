
#include "./fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "MLX42/include/MLX42/MLX42.h"
#define WIDTH 512
#define HEIGHT 512

void hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int	ft_open(char *file){
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1){
		ft_printf(ERR_MAP);
		exit(1);
	}
	return (fd);
}

int	get_height(int fd)
{
	int	height;
	char	*line;

	height = 0;
	while ((line = get_next_line(fd)))
		height++;
	return (height);
}

int **read_map(char *file)
{
	t_fdf fdf;
	int **map = NULL;

	fdf.fd = ft_open(file);
	fdf.height = get_height(fdf.fd);
	ft_printf("Hauteur %d\n", fdf.height);
	return (map);
}

int	main(int argc, char **argv)
{
	int **matrix;
	(void) matrix;
	(void) argc;

	matrix = read_map(argv[1]);
	// mlx_t* mlx;

	// if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	// 	return(EXIT_FAILURE);

	// mlx_loop_hook(mlx, &hook, mlx);
	// mlx_loop(mlx);

	// mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
