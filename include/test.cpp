#include "boundingbox.hpp"
#include <iostream>
int main()
{
	vfbvh::Vector3<float> fuck(1.0f, 2.0f, 3.0f);
	vfbvh::BoundingBox<float>(vfbvh::Vector3<float>(1.0f, 2.0f, 3.0f), vfbvh::Vector3<float>(1.0f, 2.0f, 3.0f));
	return 0;
}