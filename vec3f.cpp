// Copyright (c) 2021 Thomas Kaldahl

#include "qecvec.hpp"

// Constructors
Vec3f::Vec3f(
	float x,
	float y,
	float z
) {
	this->x = x;
	this->y = y;
	this->z = z;
}
Vec3f::Vec3f(float val) : Vec3f(val, val, val) {}
Vec3f::Vec3f() : Vec3f(0) {}


Vec3f::Vec3f(Vec2f v, float z) : Vec3f(v.x, v.y, z) {}
Vec3f::Vec3f(float x, Vec2f v) : Vec3f(x, v.x, v.y) {}

// Statics
Vec3f Vec3f::zero() {return Vec3f();}

Vec3f Vec3f::up()			{return Vec3f(	0,	1,	0	);}
Vec3f Vec3f::down()		{return Vec3f(	0,	-1,	0	);}
Vec3f Vec3f::left()		{return Vec3f(	-1,	0,	0	);}
Vec3f Vec3f::right()		{return Vec3f(	1,	0,	0	);}
Vec3f Vec3f::forward()		{return Vec3f(	0,	0,	1	);}
Vec3f Vec3f::backward()	{return Vec3f(	0,	0,	-1	);}

//vec2f.cpp: Vec2f Vec2f::up()		{return Vec2f(	0,	1	);}
//vec2f.cpp: Vec2f Vec2f::down()	{return Vec2f(	0,	-1	);}
//vec2f.cpp: Vec2f Vec2f::left()	{return Vec2f(	-1,	0	);}
//vec2f.cpp: Vec2f Vec2f::right()	{return Vec2f(	1,	0	);}

//vec2f.cpp: Vec2f Vec2f::polar(float r, float theta) {
//vec2f.cpp: 	return Vec2f(r * cos(theta), r * sin(theta));
//vec2f.cpp: }

Vec3f Vec3f::randomUniform(float min, float max) {
	float x = (max - min) * rand() / (float)RAND_MAX + min;
	float y = (max - min) * rand() / (float)RAND_MAX + min;
	float z = (max - min) * rand() / (float)RAND_MAX + min;
	return Vec3f(x, y, z);
}

// Accessors
char *Vec3f::string() const {
	char *res = (char*)malloc(64);
	snprintf(res, 64, "< %0.3f, %0.3f, %0.3f >", x, y, z);
	return res;
}

Vec2f Vec3f::xy() const {return Vec2f(x, y);}
Vec2f Vec3f::xz() const {return Vec2f(x, z);}
Vec2f Vec3f::yz() const {return Vec2f(y, z);}


// Technical methods
Vec3f Vec3f::copy() const {
	return Vec3f(x, y, z);
}

// In-place operations
Vec3f Vec3f::operator*=(float scalar) {
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return *this;
}
Vec3f Vec3f::operator/=(float divisor) {
	x /= divisor;
	y /= divisor;
	z /= divisor;
	return *this;
}
Vec3f Vec3f::operator+=(Vec3f addend) {
	x += addend.x;
	y += addend.y;
	z += addend.z;
	return *this;
}
Vec3f Vec3f::operator-=(Vec3f subtrahend) {
	x -= subtrahend.x;
	y -= subtrahend.y;
	z -= subtrahend.z;
	return *this;
}
Vec3f Vec3f::operator&=(Vec3f multiplier) {
	x *= multiplier.x;
	y *= multiplier.y;
	z *= multiplier.z;
	return *this;
}

Vec3f Vec3f::normalize() {
	x /= norm();
	y /= norm();
	z /= norm();
	return *this;
}

// Binary operations
Vec3f Vec3f::operator*(float scalar) const		{return copy() *= scalar;}
Vec3f Vec3f::operator/(float divisor) const		{return copy() /= divisor;}
float Vec3f::operator^(float exponent) const	{return pow(norm(), exponent);}

Vec3f operator*(float scalar, Vec3f vector) {return vector * scalar;}

Vec3f Vec3f::operator+(Vec3f addend) const		{return copy() += addend;}
Vec3f Vec3f::operator-(Vec3f subtrahend) const	{return copy() -= subtrahend;}
Vec3f Vec3f::operator&(Vec3f multiplier) const	{return copy() &= multiplier;}

float Vec3f::operator*(Vec3f multiplier) const {
	return x * multiplier.x
		+ y * multiplier.y
		+ z * multiplier.z;
}

// Unary operations
Vec3f Vec3f::operator-() const	{return -1 * *this;}
float Vec3f::norm() const		{return sqrt(x*x + y*y + z*z);}
Vec3f Vec3f::normal() const		{return *this / norm();}
