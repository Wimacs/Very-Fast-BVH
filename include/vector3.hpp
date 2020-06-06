#include <cstddef>
#include <algorithm>
#include <array>
#include <cmath>
#include <type_traits>
#include <iostream>

namespace vfbvh {
	template <typename Scalar>
	struct Vector3
	{
		Scalar x, y, z;
		inline Vector3(Scalar x, Scalar y, Scalar z) { this->x = x; this->y = y; this->z = z; }
		inline Vector3 operator+(const Vector3& b) const noexcept { return Vector3(x + b.x, y + b.y, z + b.z); }
		inline Vector3 operator-(const Vector3& b) const noexcept { return Vector3(x - b.x, y - b.y, z - b.z); }
		inline Vector3 operator*(Scalar s) const noexcept { return Vector3(s * x, s * y, s * z); }
		inline Vector3 operator/(Scalar s) const noexcept { return Vector3{ x / s, y / s, z / s }; }
		inline Vector3 product(const Vector3& b) const noexcept { return Vector3{ x * b.x, y * b.y, z * b.z }; }
		inline Vector3 inverse() { return Vector3(1 / x, 1 / y, 1 / z); }
		inline Scalar& operator[](const unsigned int i) { return (&x)[i]; }
		inline void print(){ std::cout << "x = " << x << " y = " << y << " z = " << z << std::endl; }
	};

	template <typename Scalar>
	inline Scalar norm(const Vector3<Scalar>& a) noexcept { return std::sqrt(dot(a, a)); }

	template <typename Scalar>
	inline Vector3<Scalar> normalize(const Vector3<Scalar>& in) noexcept { return in * (1.0f / norm(in)); }		

	template <typename Scalar>
	inline Scalar dot(const Vector3<Scalar>& a, const Vector3<Scalar>& b) noexcept {
		return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	}		

	template <typename Scalar>
	inline Vector3<Scalar> cross(const Vector3<Scalar>& a, const Vector3<Scalar>& b) noexcept {
		return Vector3<Scalar>((a.y* b.z) - (a.z * b.y), (a.z* b.x) - (a.x * b.z), (a.x* b.y) - (a.y * b.x));
	}

	template <typename Scalar>
	inline Vector3<Scalar> min(const Vector3<Scalar>& a, const Vector3<Scalar>& b) noexcept {
		return Vector3<Scalar>{std::fmin(a.x, b.x), std::fmin(a.y, b.y), std::fmin(a.z, b.z)};
	}

	template <typename Scalar>
	inline Vector3<Scalar> max(const Vector3<Scalar>& a, const Vector3<Scalar>& b) noexcept {
		return Vector3<Scalar>{std::fmax(a.x, b.x), std::fmax(a.y, b.y), std::fmax(a.z, b.z)};
	}
}