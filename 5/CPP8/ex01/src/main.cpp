#include "Span.hpp"
#include <iostream>
#include <exception>
#include <vector>
#include <cstdlib>
#include <ctime>

int main(void)
{
    // --- Test básico del subject (debe imprimir 2 y 14) ---
    std::cout << "=== Test basico ===" << std::endl;
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan:  " << sp.longestSpan()  << std::endl;
    }

    // --- Test con 10000 números usando addRange + iteradores ---
    std::cout << "\n=== Test 10000 numeros con addRange(iteradores) ===" << std::endl;
    {
        std::srand((unsigned int)std::time(NULL));

        // Creamos un vector de 10000 enteros aleatorios
        std::vector<int> numbers;
        for (int i = 0; i < 10000; i++)
            numbers.push_back(std::rand());

        // addRange recibe un par de iteradores: begin y end
        Span big(10000);
        big.addRange(numbers.begin(), numbers.end());

        std::cout << "shortestSpan: " << big.shortestSpan() << std::endl;
        std::cout << "longestSpan:  " << big.longestSpan()  << std::endl;
    }

    // --- Test addRange sobre subrangos con iteradores ---
    std::cout << "\n=== Test addRange subrango ===" << std::endl;
    {
        std::vector<int> source;
        for (int i = 0; i < 20; i++)
            source.push_back(i * 3);   // 0, 3, 6, ..., 57

        // Solo los primeros 10 elementos usando aritmética de iteradores
        Span partial(10);
        partial.addRange(source.begin(), source.begin() + 10);

        std::cout << "shortestSpan: " << partial.shortestSpan() << std::endl;
        std::cout << "longestSpan:  " << partial.longestSpan()  << std::endl;
    }

    // --- Test excepciones ---
    std::cout << "\n=== Test excepciones ===" << std::endl;
    {
        try
        {
            Span small(2);
            small.addNumber(1);
            small.addNumber(2);
            small.addNumber(3);
        }
        catch (const std::exception& e)
        {
            std::cout << "SpanFull (addNumber): " << e.what() << std::endl;
        }

        try
        {
            std::vector<int> v(5, 42);
            Span small(3);
            small.addRange(v.begin(), v.end());
        }
        catch (const std::exception& e)
        {
            std::cout << "SpanFull (addRange):  " << e.what() << std::endl;
        }

        try
        {
            Span one(1);
            one.addNumber(42);
            one.shortestSpan();
        }
        catch (const std::exception& e)
        {
            std::cout << "NoSpan (1 elemento):  " << e.what() << std::endl;
        }

        try
        {
            Span empty(5);
            empty.longestSpan();
        }
        catch (const std::exception& e)
        {
            std::cout << "NoSpan (vacio):       " << e.what() << std::endl;
        }
    }

    return (0);
}
