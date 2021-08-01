// Copyright (c) 2021 Thomas Kaldahl

#include "qecvec.hpp"

// Constructors
Vec4f::Vec4f(
	float x,
	float y,
	float z,
	float w
) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}
Vec4f::Vec4f(float val) : Vec4f(val, val, val, val) {}
Vec4f::Vec4f() : Vec4f(0) {}

Vec4f::Vec4f(Vec2f v, float z, float w) : Vec4f(v.x, v.y, z, w) {}
Vec4f::Vec4f(float x, Vec2f v, float w) : Vec4f(x, v.x, v.y, w) {}
Vec4f::Vec4f(float x, float y, Vec2f v) : Vec4f(x, y, v.x, v.y) {}
Vec4f::Vec4f(Vec3f v, float w) : Vec4f(v.x, v.y, v.z, w) {}
Vec4f::Vec4f(float x, Vec3f v) : Vec4f(x, v.x, v.y, v.z) {}

//vec3f.cpp: Vec3f::Vec3f(Vec2f v, float z) : Vec3f(v.x, v.y, z) {}
//vec3f.cpp: Vec3f::Vec3f(float x, Vec2f v) : Vec3f(x, v.x, v.y) {}

// Statics
Vec4f Vec4f::zero() {return Vec4f();}

//vec3f.cpp: Vec3f Vec3f::up()			{return Vec3f(	0,	1,	0	);}
//vec3f.cpp: Vec3f Vec3f::down()		{return Vec3f(	0,	-1,	0	);}
//vec3f.cpp: Vec3f Vec3f::left()		{return Vec3f(	-1,	0,	0	);}
//vec3f.cpp: Vec3f Vec3f::right()		{return Vec3f(	1,	0,	0	);}
//vec3f.cpp: Vec3f Vec3f::forward()		{return Vec3f(	0,	0,	1	);}
//vec3f.cpp: Vec3f Vec3f::backward()	{return Vec3f(	0,	0,	-1	);}

//vec2f.cpp: Vec2f Vec2f::up()		{return Vec2f(	0,	1	);}
//vec2f.cpp: Vec2f Vec2f::down()	{return Vec2f(	0,	-1	);}
//vec2f.cpp: Vec2f Vec2f::left()	{return Vec2f(	-1,	0	);}
//vec2f.cpp: Vec2f Vec2f::right()	{return Vec2f(	1,	0	);}

//vec2f.cpp: Vec2f Vec2f::polar(float r, float theta) {
//vec2f.cpp: 	return Vec2f(r * cos(theta), r * sin(theta));
//vec2f.cpp: }

Vec4f Vec4f::randomUniform(float min, float max) {
	float x = (max - min) * rand() / (float)RAND_MAX + min;
	float y = (max - min) * rand() / (float)RAND_MAX + min;
	float z = (max - min) * rand() / (float)RAND_MAX + min;
	float w = (max - min) * rand() / (float)RAND_MAX + min;
	return Vec4f(x, y, z, w);
}

// Accessors
char *Vec4f::string() const {
	char *res = (char*)malloc(64);
	snprintf(res, 64, "< %0.3f, %0.3f, %0.3f, %0.3f >", x, y, z, w);
	return res;
}

// Technical methods
Vec4f Vec4f::copy() const {
	return Vec4f(x, y, z, w);
}

// In-place operations
Vec4f Vec4f::operator*=(float scalar) {
	x *= scalar;
	y *= scalar;
	z *= scalar;
	w *= scalar;
	return *this;
}
Vec4f Vec4f::operator/=(float divisor) {
	x /= divisor;
	y /= divisor;
	z /= divisor;
	w /= divisor;
	return *this;
}
Vec4f Vec4f::operator+=(Vec4f addend) {
	x += addend.x;
	y += addend.y;
	z += addend.z;
	w += addend.w;
	return *this;
}
Vec4f Vec4f::operator-=(Vec4f subtrahend) {
	x -= subtrahend.x;
	y -= subtrahend.y;
	z -= subtrahend.z;
	w -= subtrahend.w;
	return *this;
}
Vec4f Vec4f::operator&=(Vec4f multiplier) {
	x *= multiplier.x;
	y *= multiplier.y;
	z *= multiplier.z;
	w *= multiplier.w;
	return *this;
}

Vec4f Vec4f::normalize() {
	x /= norm();
	y /= norm();
	z /= norm();
	w /= norm();
	return *this;
}

// Binary operations
Vec4f Vec4f::operator*(float scalar) const		{return copy() *= scalar;}
Vec4f Vec4f::operator/(float divisor) const		{return copy() /= divisor;}
float Vec4f::operator^(float exponent) const	{return pow(norm(), exponent);}

Vec4f operator*(float scalar, Vec4f vector) {return vector * scalar;}

Vec4f Vec4f::operator+(Vec4f addend) const		{return copy() += addend;}
Vec4f Vec4f::operator-(Vec4f subtrahend) const	{return copy() -= subtrahend;}
Vec4f Vec4f::operator&(Vec4f multiplier) const	{return copy() &= multiplier;}

float Vec4f::operator*(Vec4f multiplier) const {
	return x * multiplier.x
		+ y * multiplier.y
		+ z * multiplier.z
		+ w * multiplier.w;
}

// Unary operations
Vec4f Vec4f::operator-() const	{return -1 * *this;}
float Vec4f::norm() const		{return sqrt(x*x + y*y + z*z + w*w);}
Vec4f Vec4f::normal() const		{return *this / norm();}
