#pragma once

#include <cctype>
#include <cstdlib>
#include <iostream>

template <typename T>
T   nextIndex(T &index)
{
    return index + 1;
}

template <typename T>
T	doubleIndex(T& index)
{
    return index * 2;
}

template <typename T>
T	retIndex(T const& index)
{
    return index;
}

template <typename T>
T	capitalize(T& index)
{
	for (size_t i = 0; i < index.size(); i++)
	{
		if (std::islower(index[i]))

			index[i] = std::toupper(index[i]);
	}
	return index;
}

template <typename T>
T	printArray(T const& index)
{
	std::cout << index << " ";
	return index;
}

template <typename T>
void	iter(T *array, const size_t len, T (*func)(T &index))
{
    for (size_t i = 0; i < len; i++)
        array[i] = func(array[i]);
}

template <typename T>
void	iter(T const *array, const size_t len, T (*func)(T const& index))
{
    for (size_t i = 0; i < len; i++)
        func(array[i]);
}