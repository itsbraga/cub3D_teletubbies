/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:22:46 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/28 01:03:33 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

#ifndef BONUS
# define BONUS 1
#endif

# define VALID_MAP "01 NSEW"
# define VALID_BONUS_MAP "012 NSEW"

/**************************\
 * MATHS
\**************************/

# define PI 3.1415926535
# define PI2 (PI / 2)
# define PI3 ((3 * PI) / 2)
# define EPS 0.000001
# define TILE_SIZE 64
# define FOV 45
# define PROJ_DISTANCE ((WIN_WIDTH / 2) / tan(degree_to_radian(FOV) / 2))
#if BONUS
# define MOVE_SPEED 8
#else
# define MOVE_SPEED 3
#endif
# define ROTATION_SPEED 2
# define VISIBILITY_DIST_MAX 450

/**************************\
 * YAMA FLAGS
\**************************/

# define CREATE 0
# define CREATE_ARRAY 1
# define ADD 2
# define ADD_ARRAY 3
# define REMOVE -1
# define CLEAN_ALL -2
# define SEARCH -4
# define INVALID_FLAG "This flag does not exist"

/**************************\
 * EXIT STATUS
\**************************/

# define SUCCESS 0
# define FAILURE 1

/**************************\
 * ERROR
\**************************/

# define ERR "Error\n"
# define ERR_PREFIX "\033[1m\033[31mError: \033[0m"
# define ERR_USAGE "usage: ./cub3D <path/to/map.cub>"

// minilibX
# define ERR_MLX "Cannot initialize minilibX"
# define ERR_INIT_IMG "Cannot initialize minilibX image"
# define ERR_INIT_MMAP_IMG "\033[38;2;211;211;255m[minimap]\033[0m Cannot initialize minilibX image"
# define ERR_INIT_MMAP_CACHE "\033[38;2;211;211;255m[minimap]\033[0m Cannot initialize minilibX cache"
# define ERR_WIN "Cannot create new window"
# define ERR_IMG "Cannot create new image"
# define ERR_ADDR "Cannot find image address"
# define ERR_XPM "Cannot convert XPM file into a minilibX image"
# define ERR_MALLOC "Cannot allocate memory"

// File
# define ERR_CUB_EXT "Invalid extension (expected: .cub)"
# define ERR_XPM_EXT "Invalid extension (expected: .xpm)"
# define ERR_EMPTY "Oops! This file seems to be empty"
# define ERR_MAP_BORDERS "Invalid map (not fully closed)"
# define ERR_MAP "Invalid map grid"
# define ERR_CHAR "Invalid character in map"
# define ERR_RGB "Invalid RGB (range 0-255)"
# define ERR_CONFIG "Invalid file configuration"

// Player direction
# define ERR_PLAYER "Map has no player position"
# define ERR_NB_PLAYER "Map has more than one player"
# define ERR_PLAYER_POS "Invalid player position"

// Title screen
# define ERR_BG_IMG "Cannot load background image"
# define ERR_BUTTON_IMG "Cannot load button image"

/**************************\
 * MLX
\**************************/

# define W_NAME "TeleCubbies3D - by @k0xdama and @itsbraga"
# define WIN_WIDTH 1024 // 1280
# define WIN_HEIGHT 1024 // 720

# define DEL_IMG "[minilibX] Image and window destroyed\n"
# define MLX_EXIT "[minilibX] All elements have been destroyed\n"

/**************************\
 * PLAYER MOVEMENTS
\**************************/

# define COLLISION_WARN "/!\\ Collision detected /!\\\n"

// Array of pointers to functions
typedef void	(*move_array)(t_game *game);

// Move_array *f() indexes
# define _W 0
# define _S 1
# define _A 2
# define _D 3
# define _LEFT 4
# define _RIGHT 5

// Keyboard
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

// Mouse
# define MOUSE_SENSITIVITY_X 0.1f
# define MOUSE_SENSITIVITY_Y 0.05f
# define MAX_PITCH 45 // designe le max d'inclinaison verticale de la camera

/**************************\
 * WEAPON
\**************************/

# define IDLE 0
# define SHOOT 1
# define FBS 4 // frame number by sprite

/**************************\
 * PLAYER'S DIRECTION
\**************************/

# define PLAYER_DIR "NSEW"
# define N 270
# define S 90
# define E 0
# define W 180

/**************************\
 * TEXTURE'S ORIENTATION
\**************************/

# define NO	0
# define SO 1
# define WE 2
# define EA 3
# define F 4
# define C 5
# define D 6

/**************************\
 * PIXEL COLORS
\**************************/

# define RED_PIX 0x00FF0000
# define YELLOW_PIX 0x00FFFF00
# define WHITE_PIX 0x00FFFFFF
# define BLACK_PIX 0xFF000000
# define MANDARINE_PIX 0x00FEA347
# define LAVENDER_PIX 0x009683EC
# define LPINK_PIX 0x00FFB6C1
# define ROY_PURPLE_PIX 0x005A006C
# define RUSS_PURPLE_PIX 0x0019001E
# define LGRAY_PIX 0x00D3D3D3
# define GRAY_PIX 0x00303030

#endif