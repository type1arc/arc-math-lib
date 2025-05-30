#include "arc.hpp"

void main()
{
	arc::vec3<float> v1 = arc::vec3<float>(1.0f, 1.0f, 1.0f);
	arc::vec3<float> v2 = arc::vec3<float>(-1.0f, 1.0f, -1.0f);

	float dot = arc::operators::dot_product(v1, v2);
	tlog(dot + 1);

	

	//auto init_ = arc::time::elapsed_init();
	//arc::time::delay();

	//float dot = arc::operators::dot_product(v1, v2);
	//arc::vec3<_type> cross = arc::operators::cross_product(v1, v2);

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

	final.log();*/
	
	

	std::cin.get();
	exit(1);
}