#include "arc.hpp"

void main()
{
	//arc::fvec3 v1 = arc::fvec3(1.0f, 1.0f, 1.0f);
	//arc::fvec3 v2 = arc::fvec3(-1.0f, 1.0f, -1.0f);

	//arc::fvec3 v_o = arc::operators::Add(v1, v2);
	//arc::fvec3 v_n = arc::operators::normalize(v_o);

	//auto init_ = arc::time::elapsed_init();
	//arc::time::delay();

	//float dot = arc::operators::dot_product(v1, v2);
	//arc::fvec3 cross = arc::operators::cross_product(v1, v2);

	//auto final_ = arc::time::elapsed_final();
	//arc::time::delay();

	//auto elapsed_time = arc::time::elapsed_time(init_, final_);
	//std::cout << elapsed_time.count();
	//
	//arc::mat3 matrix = arc::mat3(1.0f); // creating the matrix
	//arc::logm(matrix.mat); // logging the matrix in tabular form

	//std::cout << std::endl << "mat[1][1]" << " = " << matrix.mat[1][1]; // access elements of the matrix

	/*int x = 1;
	int y = 0;

	arc::vortex::opt::swap sw(x, y);
	arc::vortex::opt::swap swped(x, y);
	arc::vortex::opt::swap final = sw && swped;

	int a = 3;
	int b = 2;
	int out = 1;

	arc::vortex::opt::expo exponent1(a, b, out);
	arc::vortex::opt::expo exponent2(a, b, out);

	arc::vortex::opt::expo _o = (exponent1 ^ exponent2);
	_o.log();
	

	final.log();*/

	arc::complex_plane::complex complex_number = arc::complex_plane::complex(1.0f, 2.0f);
	tlog(arc::complex_plane::iabs(complex_number));
	tlog(arc::complex_plane::conjugate(complex_number));

	std::cin.get();
	exit(1);
}