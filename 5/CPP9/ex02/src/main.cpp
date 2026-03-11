#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <ctime>

static int isVectorSorted(const std::vector<int> &vec)
{
    for (size_t i = 1; i < vec.size(); i++)
    {
        if (vec[i] < vec[i - 1])
            return (0);
    }
    return (1);
}

static int isListSorted(const std::list<int> &lst)
{
    if (lst.empty())
        return (1);

    std::list<int>::const_iterator it = lst.begin();
    int prev = *it;
    ++it;

    for (; it != lst.end(); ++it)
    {
        if (*it < prev)
            return (0);
        prev = *it;
    }
    return (1);
}

int main(int argc, char **argv)
{
    std::vector<int> vec;
    std::list<int> lst;
    std::clock_t start;
    double elapsed_list;
    double elapsed_vec;

    if(argc < 2)
    {
        std::cout << "Error: no arguments" << std::endl;
        return (1);
    }

    for(int i = 1; i < argc; i++)
    {
        if(!std::isdigit(*argv[i]))
        {
            std::cout << "Error: invalid value: " << argv[i] << std::endl;
            return (1); 
        }
        vec.push_back(std::atoi(argv[i]));
        lst.push_back(std::atoi(argv[i]));
    }

    std:: cout << "Before: ";
    for(size_t i = 0; i < vec.size(); i++)
        std::cout << " " << vec[i];
    std::cout << std::endl;

    start = std::clock();
    PmergeMe::sortList(lst);
    elapsed_list = (std::clock() - start) / (double)CLOCKS_PER_SEC * 1e6;

    start = std::clock();
    PmergeMe::sortVector(vec);
    elapsed_vec = (std::clock() - start) / (double)CLOCKS_PER_SEC * 1e6;

    std:: cout << "After (Vector): ";
    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << " " << *it;
    std::cout << std::endl;
    std:: cout << "After (List): ";
    for(std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << " " << *it;
    std::cout << std::endl;

    if(!isListSorted(lst))
    {
        std::cout << "Error: list is not sorted" << std::endl;
        return (1);
    }
    if(!isVectorSorted(vec))
    {
        std::cout << "Error: vector is not sorted" << std::endl;
        return (1);
    }
    std::cout << "Time to process a range of " << lst.size()
              << " elements with std::list : " << elapsed_list << " us" << std::endl;
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << elapsed_vec << " us" << std::endl;
}
