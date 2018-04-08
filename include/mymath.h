#ifndef MYMATH_H_89d7680d6s
#define MYMATH_H_89d7680d6s

struct Vector2i {
	int x;
	int y;
};

class MyMath {
	static int manhattan(Vector2i pos1, Vector2i pos2) {
		int dx = pos1.x - pos2.x;
		if (dx < 0)
			dx *= -1;
		int dy = pos1.y - pos2.y;
		if (dy < 0)
			dy *= -1;
		return dx + dy;
	}

	static Vector2i neg(Vector2i v) {
		Vector2i r;
		r.x = -1 * v.x;
		r.y = -1 * v.y;
		return r;
	}

	static Vector2i add(Vector2i v1, Vector2i v2) {
		Vector2i r;
		r.x = v1.x + v2.x;
		r.y = v1.y + v2.y;
		return r;
	}

	static Vector2i rot90(Vector2i v) {
		Vector2i r;
		r.x = -1 * v.y;
		r.y = v.x;
		return r;
	}
};

#endif