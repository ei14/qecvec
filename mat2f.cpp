// Copyright (c) 2021 Thomas Kaldahl

/*
#include "qecvec.hpp"

// Constructors
Mat2f::Mat2f(
	float a, float b,
	float c, float d
) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}
Mat2f::Mat2f(float scalar) : Mat2f(scalar, scalar, scalar, scalar) {}
Mat2f::Mat2f() : Mat2f(1, 0, 0, 1) {}

// Statics
Mat2f Mat2f::zero() {return Mat2f(0.0f);}
Mat2f Mat2f::identity() {return Mat2f();}

Mat2f Mat2f::randomUniform(int height, int width, float min, float max) {
	return Mat2f(
		(max - min) * rand() / (float)RAND_MAX + min,
		(max - min) * rand() / (float)RAND_MAX + min,
		(max - min) * rand() / (float)RAND_MAX + min,
		(max - min) * rand() / (float)RAND_MAX + min
	);
}

Mat2f Mat2f::fromRowVecs(Vec2f row1, Vec2f row2) {
	return Mat2f(
		row1.x, row1.y,
		row2.x, row2.y
	);
}
Mat2f Mat2f::fromColVecs(Vec2f col1, Vec2f col2) {
	return Mat2f(
		col1.x, col1.y,
		col2.x, col2.y
	);
}

// Accessors
char *Mat2f::string() const {
	char *res = (char*)malloc(256 * sizeof(char));
	snprintf(
		res,
		256,
		"(\n"
		"\t%0.3f\t%0.3f\n"
		"\t%0.3f\t%0.3f\n"
		")",
		a, b,
		c, d
	);
	return res;
}

// Misc operations
Vec2f Mat2f::leftCol() const {return Vec2f(a, c);}
Vec2f Mat2f::rightCol() const {return Vec2f(b, d);}
Vec2f Mat2f::topRow() const {return Vec2f(a, b);}
Vec2f Mat2f::bottomRow() const {return Vec2f(c, d);}

// In-place operations
Mat2f Mat2f::operator*=(float scalar) {
	a *= scalar;
	b *= scalar;
	c *= scalar;
	d *= scalar;
	return *this;
}
Mat2f Mat2f::operator/=(float divisor) {
	a /= divisor;
	b /= divisor;
	c /= divisor;
	d /= divisor;
	return *this;
}

Mat2f Mat2f::operator+=(Mat2f addend) {
	a += addend.a;
	b += addend.b;
	c += addend.c;
	d += addend.d;
	return *this;
}
Mat2f Mat2f::operator-=(Mat2f subtrahend) {
	for(int i = 0; i < 4; i++) data[i] -= subtrahend.data[i];
	return *this;
}
Mat2f Mat2f::operator&=(Mat2f multiplier) {
	for(int i = 0; i < 4; i++) data[i] *= multiplier.data[i];
	return *this;
}

// Binary operations
Mat2f Mat2f::operator*(float scalar) const	{return copy() *= scalar;}
Mat2f Mat2f::operator/(float divisor) const	{return copy() /= divisor;}

Mat2f Mat2f::operator^(int exponent) const {
	Mat2f base = Mat2f();
	for(int i = 0; i < exponent; i++) {
		base = base * *this;
	}
	return base;
}

Vec2f Mat2f::operator*(Vec2f multiplier) const {
	Vec2f product = Vec2f();
	for(int c = 0; c < 2; c++) product.x += comp(0, c) * multiplier.x;
}

Mat2f Mat2f::operator*(Mat2f multiplier) const {
}
Mat2f Mat2f::operator&(Mat2f multiplier) const {
}
Mat2f Mat2f::operator+(Mat2f addend) const {
}
Mat2f Mat2f::operator-(Mat2f subtrahend) const {
}

// Unary operations
bool Mat2f::invertible() const {
}

float Mat2f::det() const {
}
float Mat2f::trace() const {
}

Mat2f Mat2f::operator-() const {
}
Mat2f Mat2f::T() const {
}
Mat2f Mat2f::inv() const {
}

// Mutators
float Mat2f::setComp(int r, int c, float value) {
}

// Technical methods
Mat2f Mat2f::copy() const {
}*/
