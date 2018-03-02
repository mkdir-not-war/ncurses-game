#ifndef PERLINNOISE_H_32879507
#define PERLINNOISE_H_32879507

#include <vector>

class PerlinNoise {
private:
	std::vector<int> p;

public:
	// unseeded
	PerlinNoise();
	// seeded
	PerlinNoise(unsigned int);

	// x, y, z
	double noise(double, double, double);

private:
	// t
	double fade(double);
	// t, a, b
	double lerp(double, double, double);
	// hash, x, y, z
	double grad(int, double, double, double);
};

#endif