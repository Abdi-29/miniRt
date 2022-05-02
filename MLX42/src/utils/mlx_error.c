/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_error.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: W2Wizard <w2.wizzard@gmail.com>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/28 02:51:54 by W2Wizard      #+#    #+#                 */
/*   Updated: 2022/04/28 14:57:00 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42_Int.h"

//= Private =//

// English description of the error codes.
static const char* mlx_errors[] = {
	"No Errors",
	"File has invalid extension",
	"Failed to open the file",
	"PNG file is invalid or corrupted",
	"XPM42 file is invalid or corrupted",
	"The specified X or Y positions are out of bounds",
	"The specified Width or Height dimensions are out of bounds",
	"Failed to compile shader",
	"Failed to allocate memory",
	"Failed to initialize GLAD",
	"Failed to initialize GLFW",
	"Failed to create window",
	"String is to big to be drawn",
};


/**
 * Functions to set the error number, simply for convenience.
 * 
 * @param val The error value.
 * @return Always false 
 */
bool mlx_error(mlx_errno_t val)
{
	mlx_errno = val;
	return (false);
}

//= Public =//

const char* mlx_strerror(mlx_errno_t val)
{
	MLX_ASSERT(val < 0);
	MLX_ASSERT(val >= MLX_ERRMAX);

	return (mlx_errors[val]);
}
