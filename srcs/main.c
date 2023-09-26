#include <mlx.h>

typedef struct	s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_data *data, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

int	main(void)
{
	t_data data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "So_long");
	data.img_ptr = mlx_new_image(data.mlx_ptr, 800, 600);
	data.addr = mlx_get_data_addr(data.img_ptr, &data.bits_per_pixel, &data.line_length, &data.endian);

	int square_size = 50;
	int x = 350;
	int y = 250;
	int square_color = 0xFFFFFF;

	draw_square(&data, x, y, square_size, square_color);

	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	mlx_loop(data.mlx_ptr);

	return (0);
}