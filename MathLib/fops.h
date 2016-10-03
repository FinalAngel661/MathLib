#pragma once

/////////////
// 0.0000001
bool fequals(float lhs, float rhs);

float deg2rad(float deg);
float rad2deg(float rad);

///Basic Curving Stuff
float linearHalf(float x);
float growfast(float x);
float growslow(float x);
float hardAngle(float x);
float bounce(float x);
float bounceflip(float x);
float parabola(float x);
float parabflip(float x);
float parabola1(float x1, float x2, float x);



///curving functions(legit)
float lerp(float start, float end, float alpha);
float QuadBezier(float start, float mid, float end, float alpha);
float hermitSpline(float start, float s_tan, float end, float e_tan, float alpha);
float cardinalSpline(float start, float mid, float end, float tightness);
float catRomPline(float start, float mid, float end);