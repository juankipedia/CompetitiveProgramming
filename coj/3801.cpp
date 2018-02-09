# include <iostream>

size_t rabbit(size_t n, size_t r1, size_t r2)
{
	size_t r_aux = 0;
	for (size_t i = 0; i < n - 2; ++i)
	{
		r_aux = r2 % 1000000;
		r2 = (r1 % 1000000) * (r2 % 1000000);
		r1 = r_aux;
	}

	return r2 % 1000000;
}

int main()
{
	char *test_cstr;
	size_t tests_numbers;

	std::cin >> tests_numbers;
	size_t n[tests_numbers * 3];
	for (size_t i = 0; i < tests_numbers; ++i)
		for (short j = 0; j < 3; ++j)
			std::cin >> n[(i * 3) + j];

	for (size_t i = 0; i < tests_numbers; ++i)
			std::cout << "At week " 
	<< 2 * n[(i * 3) + 0] + n[(i * 3) + 0] - 2 <<" we obtain "
<< rabbit(n[(i * 3) + 0], n[(i * 3) + 1], n[(i * 3) + 2]) << " new rabbits.\n";

	return 0;
}