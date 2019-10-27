/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 14:26:35 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/27 21:14:06 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <limits.h>
# include "../libft/libft.h"
# include "keys.h"
# include "colors.h"

# define CX_O 250
# define CY_O 150
# define MOVE_SPEED 10
# define MENU_WIDTH 340
# define MENU_HEIGHT 180

typedef enum		e_colormod
{
	DEFAULT_MAP_COLOR,
	CARTOGARPHY,
	CONTRAST
}					t_colormod;

typedef enum		e_projection
{
	PARA,
	ISO
}					t_projection;

typedef struct		s_menu
{
	void			*backmenu_ptr;
	int				*menu_data;
	int				width;
	int				height;
	int				pos_x;
	int				pos_y;
	int				color;
}					t_menu;

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
}					t_pro;

typedef struct		s_map
{
	t_vertex		**tab;
	int				r;
	int				c;
	int				nbl;
	int				nbcol;
	int				min;
	int				max;
}					t_map;

typedef struct		s_env
{
	t_menu			menu;
	t_map			map;
	t_pix			pix;
	t_pro			**pro;
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
	short			projection_mod;
	short			colormod;
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
	int				e2;
}					t_env;

int					ft_usage(void);
int					ft_fdf_init(char *av);
int					ft_check_file(char *av);
int					ft_mlx(t_env *fdf);
int					ft_create_map(t_env *fdf, char *filename);
int					ft_key_hook(int keycode, t_env *fdf);
void				bresenham(t_env *fdf, int color);
int					ft_link_points(t_env *fdf);
void				ft_para(t_env *fdf);
int					ft_print(t_env *fdf);
void				ft_iso(t_env *fdf);
int					ft_color_fill(t_env *fdf, char *split, int x, int y);
void				ft_color_choice(t_env *fdf);
int					ft_ahextoi(char *str);
t_pro				**ft_malloc_t_pro(t_env *fdf);
int					ft_print_menu(t_env *fdf);
void				ft_init_menu(t_env *fdf);
void				ft_init_map(t_env *fdf);
void				ft_init_display(t_env *fdf);
void				ft_init_bresenham(t_env *fdf);
void				ft_init_segment_drawing_coordinate(t_env *fdf);
void				ft_print_color_setup(t_env *fdf);
void				ft_move(int keycode, t_env *fdf);
void				ft_zoom(int keycode, t_env *fdf);
void				ft_elevation(int keycode, t_env *fdf);
void				ft_rotate(int keycode, t_env *fdf);

#endif
