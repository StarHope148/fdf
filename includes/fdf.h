/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 14:26:35 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/14 19:26:24 by jcanteau         ###   ########.fr       */
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
# include <math.h>

# define SCL 10

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

typedef struct		s_pro
{
	int				px;
	int				py;
	double			xx;
	double			yy;
	double			zz;
}					t_pro;

typedef struct		s_map
{
	double			x;
	double			y;
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
	int				cx;
	int				cy;
	double			fl;
	double			el;
	double			dist;
	double			ang;
	int				iso;
	//t_vec2i			vec0
	t_map			map;
	t_pro			**pro;
}					t_env;

int					ft_error(void);
int					ft_usage(void);
int					ft_fdf(char *av);
int					ft_check_file(char *av);
int					ft_mlx(t_env *fdf);
int					ft_create_map(t_env *fdf, char *filename);
int					ft_key_hook(int keycode, t_env *fdf);
void				bresenham(t_env *fdf, int x0, int y0, int x1, int y1);
int					ft_link_points(t_env *fdf);
int					ft_3d_2d(t_env *fdf);
//void				ft_rotate_z(t_env *fdf, double val);
int					ft_reprint(t_env *fdf);
void				ft_iso(t_env *fdf);

#endif
