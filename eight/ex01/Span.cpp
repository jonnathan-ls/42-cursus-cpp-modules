#include <Span.hpp>
#include <limits>

static void validateOverflow(long long diff)
{
    if (diff > std::numeric_limits<int>::max() || diff < std::numeric_limits<int>::min())
        throw Span::OverflowException();
}

Span::Span(unsigned int size) : size(size) {}

Span::Span(const Span& other) : size(other.size), numbers(other.numbers) {}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        size = other.size;
        numbers = other.numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (numbers.size() >= size)
        throw Span::CapacityExceededException();
    numbers.push_back(number);
}

int Span::shortestSpan() const
{
    if (numbers.size() < 2)
        throw Span::NotEnoughNumbersException();

    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int shortest = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sortedNumbers.size(); ++i)
    {
        long long span = (long long)sortedNumbers[i] - (long long)sortedNumbers[i - 1];
        validateOverflow(span);
        if (span < shortest)
            shortest = (int)span;
    }
    return shortest;
}

int Span::longestSpan() const
{
    if (numbers.size() < 2)
        throw Span::NotEnoughNumbersException();

    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    long long diff = (long long)sortedNumbers.back() - (long long)sortedNumbers.front();
    validateOverflow(diff);
    
    return (int)diff;
}