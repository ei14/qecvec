#include "qecvec.hpp"

int main() {
	printf("\n\n\nVec2f\n\n");

	Vec2f a;

	a = Vec2f::polar(1, 3.14159265);
	printf("Magnitude 1, phase pi \t %s\n", a.string());

	a = Vec2f::zero();
	printf("Zero \t %s\n", a.string());

	a = Vec2f::up();
	printf("Up \t %s\n", a.string());

	a = Vec2f::down();
	printf("Down \t %s\n", a.string());

	a = Vec2f::left();
	printf("Left \t %s\n", a.string());

	a = Vec2f::right();
	printf("Right \t %s\n", a.string());

	a = Vec2f::randomUniform(-1, 2);
	printf("Random from -1 to 2 \t %s\n", a.string());

	a = Vec2f(1.5);
	printf("1.5 * (1, 1) \t %s\n", a.string());

	Vec2f b;

	b = Vec2f(3, 4);
	printf("(3, 4) \t %s\n", b.string());

	b = -b;
	printf("Negated \t %s\n", b.string());

	printf("Normal \t %f\n", b.norm());

	b = b.normal();
	printf("Normalizeed \t %s\n", b.string());

	b = b * 3;
	printf("Tripled \t %s\n", b.string());

	b = b / 2;
	printf("Halved \t %s\n", b.string());

	b = b + a;
	printf("With (1.5, 1.5) added \t %s\n", b.string());

	b = b - 2*a;
	printf("With 2(1.5, 1.5) subtracted \t %s\n", b.string());

	b = b & a;
	printf("Hadamard times (1.5, 1.5) \t %s\n", b.string());

	printf("Dotted with (1.5, 1.5) \t %f\n", b * a);

	b *= 3;
	printf("Tripled \t %s\n", b.string());

	b /= 2;
	printf("Halved \t %s\n", b.string());

	b += a;
	printf("With (1.5, 1.5) added \t %s\n", b.string());

	b -= 2*a;
	printf("With 2(1.5, 1.5) subtracted \t %s\n", b.string());

	b &= a;
	printf("Hadamard times (1.5, 1.5) \t %s\n", b.string());

	b.normalize();
	printf("Normalized \t %s\n", b.string());

	Vec2f c = b.copy();

	c *= 2;
	printf("Same \t %s\n", b.string());
	printf("Doubled \t %s\n", c.string());


	printf("\n\n\nVec3f\n\n");

	Vec3f d;

	d = Vec3f::zero();
	printf("Zero \t %s\n", d.string());

	d = Vec3f::up();
	printf("Up \t %s\n", d.string());

	d = Vec3f::down();
	printf("Down \t %s\n", d.string());

	d = Vec3f::left();
	printf("Left \t %s\n", d.string());

	d = Vec3f::right();
	printf("Right \t %s\n", d.string());

	d = Vec3f::forward();
	printf("Forward \t %s\n", d.string());

	d = Vec3f::backward();
	printf("Backward \t %s\n", d.string());

	d = Vec3f::randomUniform(-1, 1);
	printf("Random from -1 to 2 \t %s\n", d.string());

	d = Vec3f(1.5);
	printf("1.5 * (1, 1, 1) \t %s\n", d.string());

	d = Vec3f(1, 2, 3);
	printf("(1, 2, 3) \t %s\n", d.string());

	d = Vec3f(a, 2);
	printf("(1.5, 1.5) followed by a 2 \t %s\n", d.string());

	d = Vec3f(2, a);
	printf("(1.5, 1.5) led by a 2 \t %s\n", d.string());

	Vec2f e = d.xy();
	printf("First 2 components of (2, 1.5, 1.5) \t %s\n", e.string());
}
