#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
    private:
        T *elements;
        unsigned int length;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        ~Array();
        Array &operator=(const Array &other);
        T &operator[](unsigned int index);
        const T &operator[](unsigned int index) const;
        unsigned int size() const;

        class OutOfBoundsException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
    return "Array index is out of bounds";
}

template <typename T>
Array<T>::Array() : elements(NULL), length(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]()), length(n) {}

template <typename T>
Array<T>::Array(const Array &other) : elements(new T[other.length]()), length(other.length)
{
    for (unsigned int i = 0; i < length; ++i)
        elements[i] = other.elements[i];
}

template <typename T>
Array<T>::~Array()
{
    delete[] elements;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] elements;
        length = other.length;
        elements = new T[length]();
        for (unsigned int i = 0; i < length; ++i)
            elements[i] = other.elements[i];
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= length)
        throw OutOfBoundsException();
    return elements[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= length)
        throw OutOfBoundsException();
    return elements[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return length;
}

#endif