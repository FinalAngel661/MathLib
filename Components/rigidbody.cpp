#include "rigidbody.h"

void Rigidbody::intergrate(Transform & trans, float deltaTime)
{
	//perform euler intergration
	trans.position = trans.position + velocity * deltaTime;

}
