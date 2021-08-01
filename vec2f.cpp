// Copyright (c) 2021 Thomas Kaldahl

#include "qecvec.hpp"

// Constructors
Vec2f::Vec2f(
	float x,
	float y
) {
	this->x = x;
	this->y = y;
}
Vec2f::Vec2f(float val) : Vec2f(val, val) {}
Vec2f::Vec2f() : Vec2f(0) {}



// Statics
Vec2f Vec2f::zero() {return Vec2f();}


Vec2f Vec2f::up()		{return Vec2f(	0,	1	);}
Vec2f Vec2f::down()	{return Vec2f(	0,	-1	);}
Vec2f Vec2f::left()	{return Vec2f(	-1,	0	);}
Vec2f Vec2f::right()	{return Vec2f(	1,	0	);}

Vec2f Vec2f::polar(float r, float theta) {
	return Vec2f(r * cos(theta), r * sin(theta));
}

Vec2f Vec2f::randomUniform(float min, float max) {
	float x = (max - min) * rand() / (float)RAND_MAX + min;
	float y = (max - min) * rand() / (float)RAND_MAX + min;
	return Vec2f(x, y);
}

// Accessors
char *Vec2f::string() const {
	char *res = (char*)malloc(64);
	snprintf(res, 64, "< %0.3f, %0.3f >", x, y);
	return res;
}

// Technical methods
Vec2f Vec2f::copy() const {
	return Vec2f(x, y);
}

// In-place operations
Vec2f Vec2f::operator*=(float scalar) {
	x *= scalar;
	y *= scalar;
	return *this;
}
Vec2f Vec2f::operator/=(float divisor) {
	x /= divisor;
	y /= divisor;
	return *this;
}
Vec2f Vec2f::operator+=(Vec2f addend) {
	x += addend.x;
	y += addend.y;
	return *this;
}
Vec2f Vec2f::operator-=(Vec2f subtrahend) {
	x -= subtrahend.x;
	y -= subtrahend.y;
	return *this;
}
Vec2f Vec2f::operator&=(Vec2f multiplier) {
	x *= multiplier.x;
	y *= multiplier.y;
	return *this;
}

Vec2f Vec2f::normalize() {
	x /= norm();
	y /= norm();
	return *this;
}

// Binary operations
Vec2f Vec2f::operator*(float scalar) const		{return copy() *= scalar;}
Vec2f Vec2f::operator/(float divisor) const		{return copy() /= divisor;}
float Vec2f::operator^(float exponent) const	{return pow(norm(), exponent);}

Vec2f operator*(float scalar, Vec2f vector) {return vector * scalar;}

Vec2f Vec2f::operator+(Vec2f addend) const		{return copy() += addend;}
Vec2f Vec2f::operator-(Vec2f subtrahend) const	{return copy() -= subtrahend;}
Vec2f Vec2f::operator&(Vec2f multiplier) const	{return copy() &= multiplier;}

float Vec2f::operator*(Vec2f multiplier) const {
	return x * multiplier.x
		+ y * multiplier.y;
}

// Unary operations
Vec2f Vec2f::operator-() const	{return -1 * *this;}
float Vec2f::norm() const		{return sqrt(x*x + y*y);}
Vec2f Vec2f::normal() const		{return *this / norm();}
