#include "precision.h"

namespace particle {
	class Vector3 {
		public:
			real x;
			real y;
			real z;

		private:
			// This is purely for performance reasons
			// Pad ensures the values are 4-word aligned. 
			// works for floats (4 bytes), doubles are 8 bytes so this is 2 words
			real pad;

		public:
			Vector3() : x(0), y(0), z(0) {}

			Vector3(const real x, const real y, const real z) : x(x), y(y), z(z) {}

			void invert() {
				x = -x;
				y = -y;
				z = -z;
			}

			// NOTE: const after a function means that the function
			// doesn't/can't change any member variables
			real magnitude() const {
				// Euclidean distance basically
				real_sqrt(x * x + y * y + z * z);
			}

			/* Gets the squared magnitude of the vector */
			real squareMagnitude() {
				return x * x + y * y + z * z;
			}

			/* Turns a non-zero vector to the unit vector */
			void normalize() {
				real l = magnitude();

				if (l > 0) {
					(*this)* = ((real)1) / l;
				}
			}
	};
}