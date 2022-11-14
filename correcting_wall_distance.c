//hitside: sideDistX < sideDistY 비교해서 WALL_HORIZON, WALL_VERTICAL

double correcting_wall_distance(t_game game, t_map map, t_vector ray, int hitted_side) {
	t_vector pos;

	pos = game.player.pos;

	if (hitted_side == WALL_VERTICAL)
	{
		if (ray.x > 0)
			return ((map.x - pos.x) / ray.x);
		else
			return (((map.x + 1) - pos.x) / ray.x);
	}
	else /* (hitted_side == WALL_HORIZON) */
	{
		if (ray.y > 0)
			return ((map.y - pos.y) / ray.y);
		else
			return (((map.y + 1) - pos.y) / ray.y);
	}
}