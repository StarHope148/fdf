/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 14:26:35 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/15 17:09:56 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "../libft/libft.h"
# include "keys.h"
# include "colors.h"

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

typedef struct		s_pix
{
	int				xcur;
	int				ycur;
	int				xnext;
	int				ynext;
}					t_pix;

typedef struct		s_vertex
{
	int				x;
	int				y;
	int				z;
	int				color;
	int				defcolor;
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
	short			iso;
	short			colormod;
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
	int				e2;
	//t_vec2i			vec0
	t_map			map;
	t_pro			**pro;
	t_pix			pix;
}					t_env;

int					ft_error(void);
int					ft_usage(void);
int					ft_fdf_init(char *av);
int					ft_check_file(char *av);
int					ft_mlx(t_env *fdf);
int					ft_create_map(t_env *fdf, char *filename);
int					ft_key_hook(int keycode, t_env *fdf);
void				bresenham(t_env *fdf, int color);
int					ft_link_points(t_env *fdf);
void				ft_ortho(t_env *fdf);
//void				ft_rotate_z(t_env *fdf, double val);
int					ft_reprint(t_env *fdf);
void				ft_iso(t_env *fdf);
void				ft_color_fill(t_env *fdf, char *split, int x, int y);
void				ft_color_choice(t_env *fdf);
int					ft_ahextoi(char *str);
t_pro				**ft_malloc_t_pro(t_env *fdf);

#endif
