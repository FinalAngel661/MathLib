#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "fops.h"

void main()
{
	sfw::initContext();
	Transform trans(400, 300,30,30,23);

	//different constructor syntaxes:
	int j = int(4);
	int k(4);
	int l = { 4 };
	int n{ 4 };

	Transform tl = Transform(400, 300);
	Transform tn = { 400, 300 };
	Transform tm(400, 300);
	Transform tq{ 400,300 };

	//trans.position = vec2{ 400,300 };
	trans.facing = deg2rad(45);
	trans.scale = vec2{ 12,8 };

	vec2 basis = { 10,0 };
	float ang_vec = 0;

	while (sfw::stepContext())
	{
		ang_vec += sfw::getDeltaTime();
		vec2 incident = fromAngle(ang_vec);
		float proj = dot(basis, incident);

		//Draw the data!
		//sfw::drawLine();

		trans.facing += sfw::getDeltaTime();
		trans.debugDraw();
	}

	sfw::termContext();
}