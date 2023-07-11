#include "so_long.h"

t_map	map(void)
{
	static t_map	*var;

	return (&var);
}
