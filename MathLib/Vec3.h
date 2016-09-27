#pragma once

struct vec3
{
	float x, y;

};

vec3 operator+(const vec3 &lhs, const vec3 &rhs);
vec3 operator-(const vec3 &lhs, const vec3 &rhs);

vec3 & operator+=(vec3 &lhs, const vec3 &rhs);
vec3 operator-(const vec3 &v);

vec3 operator*(const vec3 &lhs, float rhs);
vec3 operator*(float rhs,vec3 &lhs);

bool operator==(const vec3 &lhs, const vec3 &rhs);

float magnitude(const vec3 &v);

vec3 operator/(const vec3 &lhs, float rhs);
vec3 operator/(float rhs, const vec3 &lhs);

vec3 operator-=(vec3 &lhs, const vec3 &rhs);
vec3 operator*=(vec3 &lhs, const vec3 &rhs);
vec3 operator/=(vec3 &lhs, const vec3 &rhs);

vec3 normal(const vec3 &v);

//component-wise
//addition
//subtraction

//expression-assignment operators
// += -=



//scaler-wise
//multiplication
//division

//evaluate the magnitude


//relational operators
//equivalence
