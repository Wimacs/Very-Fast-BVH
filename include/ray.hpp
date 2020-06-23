#include "vector3.hpp"

namespace vfbvh {
	template <typename Scalar>
	struct Ray {
		vfbvh::Vector3<Scalar> origin;
		vfbvh::Vector3<Scalar> direction;
		Scalar tmin;
		Scalar tmax;

		Ray() = default;
		Ray(const Vector3<Scalar>& orgin,
			const Vector3<Scalar>& direction,
			Scalar tmin = Scalar(0),
			Scalar tmax = std::numeric_limits<Scalar>::max())
			: origin(origin), direction(direction), tmin(tmin), tmax(tmax)
		{}
	};
}