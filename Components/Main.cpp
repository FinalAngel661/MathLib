#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "fops.h"
#include "rigidbody.h"
#include "SpaceshipLocomotion.h"

void main()
{
	int H = 1200, W = 1200;
	sfw::initContext(H,W);
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

	vec2 start = { 200,300 }, end = { 900,800 }, mid = { 0,1100 };

	//playerRigidbody.velocity = vec2{ 0,0 };

	//Transform playerTransform(200,200);
	//Rigidbody playerRigidbody;

	SpaceshipLocomation playerLoco;

	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();

		/*playerTransform.debugDraw();*/

		sfw::drawCircle(start.x, start.y, 12);
		sfw::drawCircle(mid.x, mid.y, 12);
		sfw::drawCircle(end.x, end.y, 12);

		if (sfw::getKey('S'))
			mid.y -= sfw::getDeltaTime() * 10;

		float steps = 100;
		for (int i = 0; i < steps; ++i)
		{
			float x1 = i / steps;
			float x2 = (i + 1) / steps;
			float y1 = hermitSpline(.25f, -.1f, .75f, 1, x1);
			float y2 = hermitSpline(.25f, -.1f, .75f, 1, x2);

			float t1 = i / steps;
			float t2 = (i + 1) / steps;
			
			vec2 v1 = QuadBezier(start, mid, end, t1);
			vec2 v2 = QuadBezier(start, mid, end, t2);

			x1 *= W;
			x2 *= H;
			y1 *= W;
			y2 *= H;

			/*
			int point;

			sfw::drawCircle();


			*/

			sfw::drawLine(v1.x,v1.y,v2.x,v2.y);
			sfw::drawLine(x1, y1, x2, y2);
		}

	}



	trans.facing += sfw::getDeltaTime();
	trans.debugDraw();

	sfw::termContext();
}