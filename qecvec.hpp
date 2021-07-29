// Copyright (c) 2021 Thomas Kaldahl

#ifndef QECVEC_HPP
#define QECVEC_HPP

// 2D vector with float components
struct Vec2f {
	float x;
	float y;

	// Statics
	static Vec2f polar(float r, float theta);
	static Vec2f zero();
	static Vec2f up(); // (0, 1)
	static Vec2f down(); // (0, -1)
	static Vec2f left(); // (-1, 0)
	static Vec2f right(); // (1, 0)
	static Vec2f randomUniform(double min, double max);

	// Constructors
	Vec2f(); // (0, 0)
	Vec2f(float val); // (val, val)
	Vec2f(float x, float y);

	// Accessors
	char *string() const; // As a string

	// Unary operations
	Vec2f operator-() const;
	float norm() const; // Magnitude
	Vec2f normal() const; // Unit vector

	// Binary operations
	Vec2f operator*(double scalar) const;
	Vec2f operator/(double divisor) const;
	double operator^(double exponent) const; // Magnitude raised to power

	Vec2f operator+(Vec2f addend) const; // Throws error if dimensions mis-match
	Vec2f operator-(Vec2f subtrahend) const; // ''
	Vec2f operator&(Vec2f multiplier) const; // Hadamard product
	double operator*(Vec2f multiplier) const; // Dot product

	// In-place operations
	Vec2f operator*=(double scalar);
	Vec2f operator/=(double divisor);
	Vec2f operator+=(Vec2f addend);
	Vec2f operator-=(Vec2f subtrahend);
	Vec2f operator&=(Vec2f multiplier); // Hadamard product

	Vec2f normalize();

	// Technical methods
	Vec2f copy() const;
};
Vec2f operator*(double scalar, Vec2f vector);

// 3D vector with float components
struct Vec3f {
	float x;
	float y;
	float z;

	// Statics
	static Vec3f zero();
	static Vec3f up(); // (0, 1, 0)
	static Vec3f down(); // (0, -1, 0)
	static Vec3f left(); // (-1, 0, 0)
	static Vec3f right(); // (1, 0, 0)
	static Vec3f forward(); // (0, 0, 1); out of the screen
	static Vec3f backward(); // (0, 0, -1); into the screen
	static Vec3f randomUniform(double min, double max);

	// Constructors
	Vec3f(); // (0, 0, 0)
	Vec3f(float val); // (val, val, vale)
	Vec3f(float x, float y, float z);

	Vec3f(Vec2f v, float z); // (v.x, v.y, z)
	Vec3f(float x, Vec2f v); // (x, v.x, v.y)

	// Accessors
	char *string() const; // As a string

	Vec2f xy() const; // (x, y)
	Vec2f xz() const;
	Vec2f yz() const;

	// Unary operations
	Vec3f operator-() const;
	float norm() const; // Magnitude
	Vec3f normal() const; // Unit vector

	// Binary operations
	Vec3f operator*(double scalar) const;
	Vec3f operator/(double divisor) const;
	double operator^(double exponent) const; // Magnitude raised to power

	Vec3f operator+(Vec3f addend) const; // Throws error if dimensions mis-match
	Vec3f operator-(Vec3f subtrahend) const; // ''
	Vec3f operator&(Vec3f multiplier) const; // Hadamard product
	double operator*(Vec3f multiplier) const; // Dot product

	// In-place operations
	Vec3f operator*=(double scalar);
	Vec3f operator/=(double divisor);
	Vec3f operator+=(Vec3f addend);
	Vec3f operator-=(Vec3f subtrahend);
	Vec3f operator&=(Vec3f multiplier); // Hadamard product

	Vec3f normalize();

	// Technical methods
	Vec3f copy() const;
};
Vec3f operator*(double scalar, Vec3f vector);

// 4D vector with float components
struct Vec4f {
	float x;
	float y;
	float z;
	float w;

	// Statics
	static Vec4f zero();
	static Vec4f randomUniform(double min, double max);

	// Constructors
	Vec4f(); // (0, 0, 0, 0)
	Vec4f(float val); // (val, val, val, val)
	Vec4f(float x, float y, float z, float w);

	Vec4f(Vec2f v, float z, float w); // (v.x, v.y, z, w)
	Vec4f(float x, Vec2f v, float w); // (x, v.x, v.y, w)
	Vec4f(float x, float y, Vec2f v); // (x, y, v.x, v.y)
	Vec4f(Vec3f v, float w); // (v.x, v.y, v.z, w)
	Vec4f(float x, Vec3f v); // (x, v.x, v.y, v.z)

	// Accessors
	char *string() const; // As a string

	Vec2f xy() const; // (x, y)
	Vec2f xz() const;
	Vec2f xw() const;
	Vec2f yz() const;
	Vec2f yw() const;
	Vec2f zw() const;

	Vec3f xyz() const; // (x, y, z)
	Vec3f xyw() const;
	Vec3f xzw() const;
	Vec3f yzw() const;

	// Unary operations
	Vec4f operator-() const;
	float norm() const; // Magnitude
	Vec4f normal() const; // Unit vector

	// Binary operations
	Vec4f operator*(double scalar) const;
	Vec4f operator/(double divisor) const;
	double operator^(double exponent) const; // Magnitude raised to power

	Vec4f operator+(Vec4f addend) const; // Throws error if dimensions mis-match
	Vec4f operator-(Vec4f subtrahend) const; // ''
	Vec4f operator&(Vec4f multiplier) const; // Hadamard product
	double operator*(Vec4f multiplier) const; // Dot product

	// In-place operations
	Vec4f operator*=(double scalar);
	Vec4f operator/=(double divisor);
	Vec4f operator+=(Vec4f addend);
	Vec4f operator-=(Vec4f subtrahend);
	Vec4f operator&=(Vec4f multiplier); // Hadamard product

	Vec4f normalize();

	// Technical methods
	Vec4f copy() const;
};
Vec4f operator*(double scalar, Vec4f vector);

// 2x2 matrix with float components
struct Mat2f {
	float data[4]; // Components, row by row

	// Statics
	static Mat2f zero(); // Zero matrix
	static Mat2f identity(); // Identity matrix
	static Mat2f randomUniform(int height, int width, double min, double max);
	static Mat2f fromRowVecs(Vec2f row1, Vec2f row2);
	static Mat2f fromColVecs(Vec2f col1, Vec2f col2);

	// Constructors
	Mat2f(); // Identity matrix
	Mat2f(float scalar); // Scalar multiple of identity matrix
	Mat2f(float data[4]);
	Mat2f(float r1c1, float r1c2, float r2c1, float r2c2);

	// Accessors
	float comp(int r, int c) const; // Component
	char *string() const; // As a string

	// Unary operations
	bool invertible() const;

	float det() const; // Determinant
	float trace() const;

	Mat2f operator-() const;
	Mat2f T() const; // Transpose
	Mat2f inv() const; // Inverse. Throws error if not invertible.

	// Misc operations
	Vec2f rowVec(int row) const;
	Vec2f colVec(int col) const;

	// Binary operations
	Mat2f operator*(float scalar) const;
	Mat2f operator/(float divisor) const;
	Mat2f operator^(int exponent) const; // Exponentiation

	Vec2f operator*(Vec2f multiplier); // Throws error if dimensions mis-match

	Mat2f operator*(Mat2f multiplier) const; // ''
	Mat2f operator&(Mat2f multiplier) const; // Hadamard product
	Mat2f operator+(Mat2f addend) const;
	Mat2f operator-(Mat2f subtrahend) const;

	// In-place operations
	Mat2f operator*=(float scalar);
	Mat2f operator/=(float divisor);
	Mat2f operator^=(int exponent); // Exponentiation

	Mat2f operator&=(Mat2f multiplier); // Hadamard product
	Mat2f operator+=(Mat2f addend);
	Mat2f operator-=(Mat2f subtrahend);

	// Mutators
	float setComp(int r, int c, float value);	// Sets component.
												// Returns previous value.
	// Technical methods
	Mat2f copy() const;
};
Mat2f operator*(float scalar, Mat2f matrix);

// 3x3 matrix with float components
struct Mat3f {
	float data[9]; // Components, row by row

	// Statics
	static Mat3f zero(); // Zero matrix
	static Mat3f identity(); // Identity matrix
	static Mat3f randomUniform(int height, int width, double min, double max);
	static Mat3f fromRowVecs(Vec3f row1, Vec3f row2, Vec3f row3);
	static Mat3f fromColVecs(Vec3f col1, Vec3f col2, Vec3f col3);

	// Constructors
	Mat3f(); // Identity matrix
	Mat3f(float scalar); // Scalar multiple of identity matrix
	Mat3f(float data[9]);
	Mat3f(
		float r1c1, float r1c2, float r1c3,
		float r2c1, float r2c2, float r2c3,
		float r3c1, float r3c2, float r3c3
	);

	// Accessors
	float comp(int r, int c) const; // Component
	char *string() const; // As a string

	// Unary operations
	bool invertible() const;

	float det() const; // Determinant
	float trace() const;

	Mat3f operator-() const;
	Mat3f T() const; // Transpose
	Mat3f inv() const; // Inverse. Throws error if not invertible.

	// Misc operations
	Vec3f rowVec(int row) const;
	Vec3f colVec(int col) const;

	// Binary operations
	Mat3f operator*(float scalar) const;
	Mat3f operator/(float divisor) const;
	Mat3f operator^(int exponent) const; // Exponentiation

	Vec3f operator*(Vec3f multiplier); // Throws error if dimensions mis-match

	Mat3f operator*(Mat3f multiplier) const; // ''
	Mat3f operator&(Mat3f multiplier) const; // Hadamard product
	Mat3f operator+(Mat3f addend) const;
	Mat3f operator-(Mat3f subtrahend) const;

	// In-place operations
	Mat3f operator*=(float scalar);
	Mat3f operator/=(float divisor);
	Mat3f operator^=(int exponent); // Exponentiation

	Mat3f operator&=(Mat3f multiplier); // Hadamard product
	Mat3f operator+=(Mat3f addend);
	Mat3f operator-=(Mat3f subtrahend);

	// Mutators
	float setComp(int r, int c, float value);	// Sets component.
												// Returns previous value.
	// Technical methods
	Mat3f copy() const;
};
Mat3f operator*(float scalar, Mat3f matrix);

// 4x4 matrix with float components
struct Mat4f {
	float data[16]; // Components, row by row

	// Statics
	static Mat4f zero(); // Zero matrix
	static Mat4f identity(); // Identity matrix
	static Mat4f randomUniform(int height, int width, double min, double max);
	static Mat4f fromRowVecs(Vec4f row1, Vec4f row2, Vec4f row3, Vec4f row4);
	static Mat4f fromColVecs(Vec4f col1, Vec4f col2, Vec4f col3, Vec4f col4);

	// Constructors
	Mat4f(); // Identity matrix
	Mat4f(float scalar); // Scalar multiple of identity matrix
	Mat4f(float data[16]);
	Mat4f(
		float r1c1, float r1c2, float r1c3, float r1c4,
		float r2c1, float r2c2, float r2c3, float r2c4,
		float r3c1, float r3c2, float r3c3, float r3c4,
		float r4c1, float r4c2, float r4c3, float r4c4
	);

	// Accessors
	float comp(int r, int c) const; // Component
	char *string() const; // As a string

	// Unary operations
	bool invertible() const;

	float det() const; // Determinant
	float trace() const;

	Mat4f operator-() const;
	Mat4f T() const; // Transpose
	Mat4f inv() const; // Inverse. Throws error if not invertible.

	// Misc operations
	Vec4f rowVec(int row) const;
	Vec4f colVec(int col) const;

	// Binary operations
	Mat4f operator*(float scalar) const;
	Mat4f operator/(float divisor) const;
	Mat4f operator^(int exponent) const; // Exponentiation

	Vec4f operator*(Vec4f multiplier); // Throws error if dimensions mis-match

	Mat4f operator*(Mat4f multiplier) const; // ''
	Mat4f operator&(Mat4f multiplier) const; // Hadamard product
	Mat4f operator+(Mat4f addend) const;
	Mat4f operator-(Mat4f subtrahend) const;

	// In-place operations
	Mat4f operator*=(float scalar);
	Mat4f operator/=(float divisor);
	Mat4f operator^=(int exponent); // Exponentiation

	Mat4f operator&=(Mat4f multiplier); // Hadamard product
	Mat4f operator+=(Mat4f addend);
	Mat4f operator-=(Mat4f subtrahend);

	// Mutators
	float setComp(int r, int c, float value);	// Sets component.
												// Returns previous value.
	// Technical methods
	Mat4f copy() const;
};
Mat4f operator*(float scalar, Mat4f matrix);

#endif
