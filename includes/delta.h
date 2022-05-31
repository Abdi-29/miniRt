#ifndef DELTA_H
# define DELTA_H

typedef union u_delta
{
	struct s_delta
	{
		double	a;
		double	b;
		double	c;
	}				t_s_rgb;
	double	delta[3];
}					t_delta;

#endif