#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <sys/time.h>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <iomanip>

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
    struct timeval tstart, tend;
    double elapsed_list;
    double elapsed_vec;

    if (argc < 2)
    {
        std::cerr << "Error: no arguments" << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; ++i)
    {
        const char *s = argv[i];
        if (!s || s[0] == '\0')
        {
            std::cerr << "Error: invalid value: " << argv[i] << std::endl;
            return 1;
        }
        
        for (const char *p = s; *p; ++p)
        {
            if (!std::isdigit(static_cast<unsigned char>(*p)))
            {
                std::cerr << "Error: invalid value: " << argv[i] << std::endl;
                return 1;
            }
        }
        char *endptr = NULL;
        unsigned long val = std::strtoul(s, &endptr, 10);
        if (endptr == NULL || *endptr != '\0' || val > (unsigned long)INT_MAX)
        {
            std::cerr << "Error: invalid value: " << argv[i] << std::endl;
            return 1;
        }
        int iv = static_cast<int>(val);
        vec.push_back(iv);
        lst.push_back(iv);
    }

    std:: cout << "Before:";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << " " << vec[i];
    std::cout << std::endl;

    gettimeofday(&tstart, NULL);
    PmergeMe::sortList(lst);
    gettimeofday(&tend, NULL);
    elapsed_list = (tend.tv_sec - tstart.tv_sec) * 1000.0 + (tend.tv_usec - tstart.tv_usec) / 1000.0;

    gettimeofday(&tstart, NULL);
    PmergeMe::sortVector(vec);
    gettimeofday(&tend, NULL);
    elapsed_vec = (tend.tv_sec - tstart.tv_sec) * 1000.0 + (tend.tv_usec - tstart.tv_usec) / 1000.0;

    std:: cout << "After (Vector): ";
    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << " " << *it;
    std::cout << std::endl;
    std:: cout << "After (List): ";
    for(std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << " " << *it;
    std::cout << std::endl;

    if (!isListSorted(lst))
    {
        std::cerr << "Error: list is not sorted" << std::endl;
        return 1;
    }
    if (!isVectorSorted(vec))
    {
        std::cerr << "Error: vector is not sorted" << std::endl;
        return 1;
    }
    std::cout << "Time to process a range of " << lst.size()
              << " elements with std::list : " << std::fixed << std::setprecision(3) << elapsed_list << " ms" << std::endl;
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << std::fixed << std::setprecision(3) << elapsed_vec << " ms" << std::endl;
}
