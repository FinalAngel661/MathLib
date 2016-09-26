#pragma once

struct vec2
{
	float x, y;

};

vec2 operator+(const vec2 &lhs, const vec2 &rhs);

vec2 & operator+=(vec2 &lhs, const vec2 &rhs);
vec2 operator-(const vec2 &v);

vec2 operator*(const vec2 &lhs, float rhs);
vec2 operator*(float rhs, vec2 &lhs);

bool operator==(const vec2 &lhs, const vec2 &rhs);

float magnitude(const vec2 &v);

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
