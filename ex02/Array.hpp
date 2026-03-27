#pragma once
 
// Regular bold text
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"
#define NC "\e[0m"

#include <exception>
#include <cstddef>

template <typename T>
class Array
{
private:
    T	*_array;
	unsigned int	_n;

public:
    Array() : _array(new T[0]), _n(0) {}
    Array(unsigned int n) : _array(new T[n]), _n(n) {}
    Array(const Array& original) : _array(NULL), _n(0)
	{
		*this = original;
	}
    Array &operator=(const Array& original)
	{
		if (this != &original)
		{
			delete[] _array;
			_n = original._n;
			if (_n > 0)
			{
				_array = new T[_n];
				for (unsigned int i = 0; i < _n; i++)
					_array[i] = original._array[i];
			}
			else
				_array = NULL;
		}
		return *this;
	}
	~Array() { delete[] _array; }

	T &operator[](unsigned int index);
	unsigned int	size() const;

	class BadIndex : public std::exception
	{
		virtual const char	*what() const throw();
	};
};

template <typename T>
unsigned int Array<T>::size() const
{
	return _n;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _n || _array == NULL)
		throw Array::BadIndex();
	return _array[index];
}

template <class T>
const char	*Array<T>::BadIndex::what() const throw()
{
	return BRED "Index out of bounds" NC;
}