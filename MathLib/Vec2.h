#pragma once

struct vec2
{
	float x, y;

};

vec2 operator+(const vec2 &lhs, const vec2 &rhs);
vec2 operator-(const vec2 &lhs,const vec2 &rhs);

vec2 & operator+=(vec2 &lhs, const vec2 &rhs);
vec2 operator-(const vec2 &v);

vec2 operator*(const vec2 &lhs, float rhs);
vec2 operator*(float rhs, vec2 &lhs);

bool operator==(const vec2 &lhs, const vec2 &rhs);

float magnitude(const vec2 &v);

vec2 operator/(const vec2 &lhs, float rhs);
vec2 operator/(float rhs, const vec2 &lhs);

vec2 operator-=(vec2 &lhs, const vec2 &rhs);
vec2 operator*=(vec2 &lhs, const vec2 &rhs);
vec2 operator/=(vec2 &lhs, const vec2 &rhs);

vec2 normal(const vec2 &v);


float dot(const vec2 &rhs, const vec2 &lhs);
float angleBetween(const vec2 &rhs,const vec2 &lhs);

///////////////////////////////////////////////////////
////3D Cross Product vec3 cross(const vec3 &lhs, const vec3 &rhs);



///////////////////
////2D game only

vec2 perp(const vec2 &v);
vec2 angle(const vec2 &v);

//vec2{cos(a), sin(a)};
vec2 fromAngle(float a);


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
