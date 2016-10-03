#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "fops.h"

void main()
{
	sfw::initContext(1200,1200);
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

		while (sfw::stepContext())
		{
			float steps = 100;
			for (int i = 0; i < steps; ++i)
			{
				float x1 = i / steps;
				float x2 = (i + 1) / steps;
				float y1 = parabola(x1);
				float y2 = parabflip(x2);
				

				
					x1 *= 1200;
					x2 *= 1200;
					y1 *= 1200;
					y2 *= 1200;
				
				/*
					int point;

					sfw::drawCircle();
				
				
				*/

					
				sfw::drawLine(x1, y1, x2, y2);
			}

		}



		trans.facing += sfw::getDeltaTime();
		trans.debugDraw();
	}

	sfw::termContext();
}