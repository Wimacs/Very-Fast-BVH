#include "vector3.hpp"

namespace vfbvh {
	template <typename Scalar>
	struct BoundingBox {
		Vector3<Scalar> min, max;

		BoundingBox() = default;
		inline BoundingBox(const Vector3<Scalar>& v) : min(v), max(v) {}
		inline BoundingBox(const Vector3<Scalar>& min, const Vector3<Scalar>& max) : min(min), max(max) {}

		inline BoundingBox& shrink(const BoundingBox& bbox) {
			min = vfbvh::max(min, bbox.min);
			max = vfbvh::min(max, bbox.max);
			return *this;
		}

		inline BoundingBox& extend(const BoundingBox& bbox) {
			min = vfbvh::min(min, bbox.min);
			max = vfbvh::max(max, bbox.max);
			return *this;
		}

		inline Vector3<Scalar> diagonal() const {
			return max - min;
		}

		inline Vector3<Scalar> center()  {
			return (max + min) * Scalar(0.5);
		}

		inline Scalar half_area() const {
			auto d = diagonal();
			return (d[0] + d[1]) * d[2] + d[0] * d[1];
		}

		inline Scalar volume() const {
			auto d = diagonal();
			return d[0] * d[1] * d[2];
		}

		inline size_t largest_axis() const {
			auto d = diagonal();
			size_t axis = 0;
			if (d[0] < d[1]) axis = 1;
			if (d[axis] < d[2]) axis = 2;
			return axis;
		}

		inline Scalar largest_extent() const {
			return diagonal()[largest_axis()];
		}

		inline static BoundingBox full() {
			return BoundingBox(
				Vector3<Scalar>(-std::numeric_limits<Scalar>::max()),
				Vector3<Scalar>(std::numeric_limits<Scalar>::max()));
		}

		inline static BoundingBox empty() {
			return BoundingBox(
				Vector3<Scalar>(std::numeric_limits<Scalar>::max()),
				Vector3<Scalar>(-std::numeric_limits<Scalar>::max()));
		}
	};
}