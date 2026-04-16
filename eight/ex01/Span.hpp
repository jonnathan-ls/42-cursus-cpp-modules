#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
	private:
		unsigned int size;
		std::vector<int> numbers;
	public:
		Span(unsigned int size);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;

		class CapacityExceededException : public std::exception
		{
		public:
			virtual const char* what() const throw()
			{
				return "Cannot add number: capacity exceeded";
			}
		};

		class NotEnoughNumbersException : public std::exception
		{
		public:
			virtual const char* what() const throw()
			{
				return "Not enough numbers to find a span";
			}
		};

		class OverflowException : public std::exception
		{
		public:
			virtual const char* what() const throw()
			{
				return "Span difference exceeds int range (overflow)";
			}
		};
};

#endif
