#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>

class NotFoundException : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Element not found in container";
	}
};

template<typename T>
typename T::iterator easyfind(T& container, int value)
{
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
	{
		if (*it == value)
			return it;
	}
	throw NotFoundException();
}

#endif