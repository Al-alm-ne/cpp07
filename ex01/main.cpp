#include "iter.hpp"
#include <iostream>
#include <string>

int main()
{
    int	iarray[5] = {6, 78, 3, 97, 22};
	double const	darray[4] = {2.14, 8.37, 78.45, 18.36};
    char	carray[3] = {'e', 'W', 'k'};
    std::string	sarray[2] = {"42Lisboa", "42Porto"};
    std::string const	csarray[3] = {"Hello", "42", "Paris"};

    iter(iarray, 5, doubleIndex);
    std::cout   << "New iarray[5] = {";
    for (size_t i = 0; i < 5; i++)
    {
        if (i == 4) {std::cout << iarray[i];}
        else {std::cout   << iarray[i] << ", ";}
    }
    std::cout << "}\n\n";

	iter(darray, 4, retIndex);
    std::cout   << "New darray[4] = {";
    for (size_t i = 0; i < 4; i++)
    {
        if (i == 3) {std::cout << darray[i];}
        else {std::cout   << darray[i] << ", ";}
    }
    std::cout << "}\n\n";

	iter(carray, 3, nextIndex);
    std::cout   << "New carray[3] = {";
    for (size_t i = 0; i < 3; i++)
    {
        if (i == 2) {std::cout << carray[i];}
        else {std::cout   << carray[i] << ", ";}
    }
    std::cout << "}\n\n";

	iter(sarray, 2, capitalize);
    std::cout   << "New sarray[2] = {"
                << sarray[0] << " ,"
                << sarray[1] << "}\n\n";

    std::cout << "csarray printed: ";
    iter(csarray, 3, printArray);
    std::cout << "\n";
    return 0;
}