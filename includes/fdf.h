/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 14:26:35 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/11 15:13:39 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "keys_define.h"

# define SCL 20

/* typedef struct 		s_vec2i
{
	int	x;
	int y;
}					t_vec2i;

t_vec2i		vec2i(int x, int y)
{
	return ((t_vec2i){x, y})
} */

typedef struct		s_vertex
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_vertex;

typedef struct		s_map
{
	long double				x;
	long double				y;
	int				nbl;
	int				nbcol;
	t_vertex		**tab;
}					t_map;

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				*data;
	int				width;
	int				height;
	int				bpp;
	int				size_l;
	int				endian;
	//t_vec2i			vec0
	t_map			map;
}					t_env;

int		ft_error(void);
int		ft_usage(void);
int		ft_fdf(char *av);
int		ft_check_file(char *av);
int		ft_mlx(t_env *fdf);
int		ft_create_map(t_env *fdf, char *filename);
int		ft_key_hook(int keycode, t_env *fdf);
void	bresenham(t_env *fdf,int x0, int y0, int x1, int y1);
void	ft_link_points(t_env *fdf);
void	ft_3d_2d(t_env *fdf, int x, int y, int z);

#endif