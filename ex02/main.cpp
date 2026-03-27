#include "Array.hpp"
#include <iostream>

int	main()
{
	std::cout << BWHT << "=== Empty array ===" << NC << "\n";
	Array<int>	empty;
	std::cout  << BGRN << "Empty size: " << empty.size() << NC << "\n";

	std::cout << BWHT << "=== Arrays of int ===" << NC << "\n";
	Array<int>	a1(5);
	for (unsigned int i = 0; i < a1.size(); i++)
		a1[i] = (i + 2) * 2;
	std::cout << BCYN << "a1[" << a1.size() << "] = ";
	for (unsigned int i = 0; i < a1.size(); i++)
		std::cout << a1[i] << " ";
	std::cout << "\n";

	Array<int>	b1 = a1;
	std::cout << BMAG << "b1[" << b1.size() << "] = ";
	for (unsigned int i = 0; i < b1.size(); i++)
		std::cout << b1[i] << " ";

	std::cout << BWHT << "\n=== Modifying b1 ===\n";
	std::cout << BMAG << "b1[" << b1.size() << "] = ";
	for (unsigned int i = 0; i < b1.size(); i++)
		b1[i] = (i + 3) * 8;
	for (unsigned int i = 0; i < b1.size(); i++)
		std::cout << b1[i] << " ";

	std::cout << BWHT << "\n=== No impact on a1 ===\n";
		std::cout << BCYN << "a1[" << a1.size() << "] = ";
	for (unsigned int i = 0; i < a1.size(); i++)
		std::cout << a1[i] << " ";
	std::cout << NC << "\n";

	std::cout << BWHT << "=== Out of bounds checking ===\n";
	try {
		std::cout << BYEL << a1[8] << NC << "\n";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << "\n";
	}
	return 0;
}

// #include <iostream>
// #include <cstdlib>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }