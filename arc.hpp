#include <iostream>
#include <tuple>
#include <math.h>
#include <cmath>
#include <thread>
#include <chrono>
#include <array>

#define tlog(x) std::cout << x << std::endl;
#define errlog(x) std::cerr << x << std::endl;

namespace arc
{
	// data structures
	struct fvec3 // For vectors in 3D space
	{
	private:
		std::tuple<float, float, float> vec_t;

	public:
		float x, y, z;

		fvec3(float x, float y, float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;

			vec_t = std::make_tuple(this->x, this->y, this->z);
		}

		void logv() { std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl; }
		float mag() { return x + y + z; }
		std::tuple<float, float, float> get() { return vec_t; }
	};
	struct fvec2 // For vectors in 2D space
	{
	private:
		std::tuple<float, float> vec_t;

	public:
		float x, y;

		fvec2(float x, float y)
		{
			this->x = x;
			this->y = y;

			vec_t = std::make_tuple(this->x, this->y);
		}

		void logv() { std::cout << "(" << x << ", " << y << ")" << std::endl; }
		float mag() { return x + y; }
		std::tuple<float, float> get() { return vec_t; }
	};

	struct mat3
	{
		int const rows = 3;
		int const columns = 3;

		public:
			float mat[3][3];


			mat3(float diag)
			{
				int i = 0;
				int row = 0;


				while (row < 3)
				{
					i++;
					if (i > 2)
					{
						i = 0;
						row++;
					}

					mat[row][i] = 1;

				}
			}
	};

	void logm(float matrix[3][3]) // for logging or printing the matrix into the terminal
	{
		int i = 0;
		int row = 0;

		std::cout << "[mat3]" << std::endl;
		while (row < 3)
		{
			if (i > 2)
			{
				std::cout << std::endl;
				i = 0;
				row++;

				if (row > 2)
					break;
			}

			i++;
			std::cout << matrix[row][i] << " ";
		}
	}

	// operators
	namespace operators
	{
		// vectors in 3D space
		fvec3 Add(fvec3 v1, fvec3 v2)
		{
			fvec3 _out = fvec3
			(
				v1.x + v2.x,
				v1.y + v2.y,
				v1.z + v2.z
			);

			return _out;
		}

		fvec3 normalize(fvec3 v)
		{
			fvec3 _out = fvec3(
				v.x /= abs(v.x),
				v.y /= abs(v.y),
				v.z /= abs(v.z)
			);

			if (isnan(_out.x)) _out.x = 0;
			if (isnan(_out.y)) _out.y = 0;
			if (isnan(_out.z)) _out.z = 0;

			return _out;
		}

		fvec3 negate(fvec3 v)
		{
			v.x *= -1;
			v.y *= -1;
			v.z *= -1;

			return v;
		}


		float dot_product(fvec3 v1, fvec3 v2)
		{
			return v1.mag() * v2.mag() * cos(atan2(v1.mag(), v2.mag()));
		}

		fvec3 cross_product(fvec3 v1, fvec3 v2)
		{
			fvec3 _out = fvec3(0.0f, 0.0f, 0.0f);
			_out.x = v1.x * v2.x * sin(atan2(v1.mag(), v2.mag()));
			_out.y = v1.y * v2.y * sin(atan2(v1.mag(), v2.mag()));
			_out.z = v1.z * v2.z * sin(atan2(v1.mag(), v2.mag()));

			return _out;
		}

		// vectors in 2D space
		fvec2 Add(fvec2 v1, fvec2 v2)
		{
			fvec2 _out = fvec2
			(
				v1.x + v2.x,
				v1.y + v2.y
			);

			return _out;
		}

		fvec2 normalize(fvec2 v)
		{
			fvec2 _out = fvec2(
				v.x /= abs(v.x),
				v.y /= abs(v.y)
			);

			if (isnan(_out.x)) _out.x = 0;
			if (isnan(_out.y)) _out.y = 0;

			return _out;
		}

		fvec2 negate(fvec2 v)
		{
			v.x *= -1;
			v.y *= -1;

			return v;
		}

		float dot_product(fvec2 v1, fvec2 v2)
		{
			return v1.mag() * v2.mag() * cos(atan2(v1.mag(), v2.mag()));
		}

		fvec2 cross_product(fvec2 v1, fvec2 v2)
		{
			fvec2 _out = fvec2(0.0f, 0.0f);
			_out.x = v1.x * v2.x * sin(atan2(v1.mag(), v2.mag()));
			_out.y = v1.y * v2.y * sin(atan2(v1.mag(), v2.mag()));

			return _out;
		}
	}
	
	// time
	namespace time
	{
		std::chrono::system_clock::time_point elapsed_init() { return std::chrono::system_clock::now();	} // initial time value
		std::chrono::system_clock::time_point elapsed_final() {	return std::chrono::system_clock::now(); } // final time value

		void delay()
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100)); // delay by 100ms
		}

		std::chrono::system_clock::duration elapsed_time(std::chrono::system_clock::time_point _init, std::chrono::system_clock::time_point _final) // calculate elapsed time
		{
			return std::chrono::duration_cast<std::chrono::milliseconds> (_final - _init);
		}
	}

	// vortex - utilities
	
	namespace v_opt // TO DO: ADD MORE
	{
		struct swap
		{
			public:
			int x, y;
				swap(int x, int y) : x(x), y(y) {}

				swap operator&&(const swap & ott)
				{
					return swap(x = ott.y, y = ott.x);
				}

				void log()
				{
					std::cout << "(" << x << ", " << y << ")";
				}
		};

		struct shift
		{
			public:
				int x, y, z;
				shift(int x, int y, int z) : x(x), y(y), z(z) {}

				shift operator>>(const shift& ott)
				{
					return shift(x = ott.y, y = ott.z, z = ott.x);
				}

				void log()
				{
					std::cout << "(" << x << ", " << y << ", " << ")";
				}
		};

		struct expo
		{
			public:
				int x, n, out;
				expo(int x, int n, int out) : x(x), n(n), out(out) {}

				expo operator^(const expo& tis)
				{
					for (out = x; out < n; out++)
					{
						out *= tis.n;
					}
					return expo(x, n, out);
				}

				void log()
				{
					std::cout << out << std::endl;
				}
		};

		float sqroot(float _x) // SQR ROOT FUNCTION using Newton-Raphson Method
		{
			if (_x < 0.0f) {
				errlog("complex-plane: arg < 0");
				return EXIT_FAILURE;
			}

			float guess = _x / 2.0f;
			float epsilon = 0.00000001f;

			while (abs(guess * guess - 1) > epsilon)
			{
				guess = (guess + _x / guess) / 2.0f;
			}

			return guess;
		}
	}

	// complex numbers - lets see how it goes


#define iota v_opt::sqroot(-1)

	namespace complex_plane
	{
		struct complex
		{
			public:
				float real_comp, im_comp, comp_val;
				complex(float _real_comp, float _im_comp) : real_comp(_real_comp), im_comp(_im_comp)
				{
					comp_val = _real_comp + _im_comp * iota;
					tlog("success: complex number defined.");
					EXIT_SUCCESS;
				}

				auto err() { errlog("failure: complex number not created."); return EXIT_FAILURE; }
		};
	}

}