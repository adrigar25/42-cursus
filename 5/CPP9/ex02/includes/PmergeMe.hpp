#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe& operator=(const PmergeMe &other);
    static void sortVector(std::vector<int> &vec);
    static void sortList(std::list<int> &lst);
    ~PmergeMe();
};

#endif