/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 14:26:35 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/08 16:27:27 by jcanteau         ###   ########.fr       */
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

# define WIN_W 800
# define WIN_H 600

typedef struct		s_map
{
	int				x;
	int				y;
	size_t			nbl;
	size_t			nbcol;
	int				**map;
}					t_map;

typedef struct		s_vertex
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_vertex;

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	void			*data;
	int				bpp;
	int				size_l;
	int				endian;
	t_map			map;
}					t_env;

int		ft_error(void);
int		ft_usage(void);
int		ft_fdf(char *av);
int		ft_check_file(char *av);
int		ft_mlx(t_env *fdf);
int		ft_create_map(t_env *fdf, char *filename);
int		ft_key_hook(int keycode, t_env *fdf);

#endif