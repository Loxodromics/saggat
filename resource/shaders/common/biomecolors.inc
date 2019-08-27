vec4 biome(float e, float m, float seaLevel)
{

    vec4 OCEAN = vec4( 0.265625 , 0.269531 , 0.46875 , 0.8);
	vec4 BEACH = vec4( 0.816406 , 0.71875 , 0.554688 , 0.1);
	vec4 SCORCHED = vec4( 0.332031 , 0.332031 , 0.332031 , 0.1);
	vec4 BARE = vec4( 0.53125 , 0.53125 , 0.53125 , 0.1);
	vec4 TUNDRA = vec4( 0.730469 , 0.730469 , 0.667969 , 0.1);
	vec4 SNOW = vec4( 0.863281 , 0.863281 , 0.890625 , 0.5);
	vec4 TEMPERATE_DESERT = vec4( 0.785156 , 0.816406 , 0.617188 , 0.1);
	vec4 SHRUBLAND = vec4( 0.53125 , 0.59375 , 0.46875 , 0.1);
	vec4 TAIGA = vec4( 0.597656 , 0.660156 , 0.472656 , 0.1);
	vec4 GRASSLAND = vec4( 0.535156 , 0.660156 , 0.351563 , 0.1);
	vec4 TEMPERATE_DECIDUOUS_FOREST = vec4( 0.40625 , 0.574219 , 0.355469 , 0.1);
	vec4 TEMPERATE_RAIN_FOREST = vec4( 0.273438 , 0.527344 , 0.339844 , 0.1);
	vec4 SUBTROPICAL_DESERT = vec4( 0.613281 , 0.550781 , 0.46875 , 0.1);
	vec4 TROPICAL_SEASONAL_FOREST = vec4( 0.339844 , 0.59375 , 0.28125 , 0.1);
	vec4 TROPICAL_RAIN_FOREST = vec4( 0.210938 , 0.460938 , 0.335938 , 0.1);

/// + 0.02 to avoid ugly polygone outlines at the ocean
    if (e < 0.02 + seaLevel) return OCEAN;
	if (e < 0.02 + seaLevel + 0.02) return BEACH;

    if (e > 0.8 * (1.0 / seaLevel)) {
	    if (m < 0.1) return SCORCHED;
		if (m < 0.2) return BARE;
		if (m < 0.5) return TUNDRA;
		return SNOW;
	}

    if (e > 0.6 * (1.0 / seaLevel)) {
	    if (m < 0.33) return TEMPERATE_DESERT;
		if (m < 0.66) return SHRUBLAND;
		return TAIGA;
	}

    if (e > 0.3 * (1.0 / seaLevel)) {
	    if (m < 0.16) return TEMPERATE_DESERT;
		if (m < 0.50) return GRASSLAND;
		if (m < 0.83) return TEMPERATE_DECIDUOUS_FOREST;
		return TEMPERATE_RAIN_FOREST;
	}

    if (m < 0.16) return SUBTROPICAL_DESERT;
	if (m < 0.33) return GRASSLAND;
	if (m < 0.66) return TROPICAL_SEASONAL_FOREST;
	return TROPICAL_RAIN_FOREST;
}
