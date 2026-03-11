#include "PmergeMe.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <ctime>

PmergeMe::PmergeMe(){};

PmergeMe::PmergeMe(const PmergeMe &other){(void)other;};

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
    (void)other;
    return (*this);
}

PmergeMe::~PmergeMe(){};

static void insertBinarySearchList(std::list<int> &lst, int value)
{
    int lo = 0;
    int hi = (int)lst.size();

    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        std::list<int>::iterator it = lst.begin();
        std::advance(it, mid);
        if (*it < value)
            lo = mid + 1;
        else
            hi = mid;
    }
    std::list<int>::iterator pos = lst.begin();
    std::advance(pos, lo);
    lst.insert(pos, value);
}

static void insertBinarySearchVector(std::vector<int> &vec, int value)
{
    int lo = 0;
    int hi = (int)vec.size();

    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        std::vector<int>::iterator it = vec.begin();
        std::advance(it, mid);
        if (*it < value)
            lo = mid + 1;
        else
            hi = mid;
    }
    std::vector<int>::iterator pos = vec.begin();
    std::advance(pos, lo);
    vec.insert(pos, value);
}

void PmergeMe::sortList(std::list<int> &lst)
{
    if (lst.size() <= 1)
        return;

    std::list<std::pair<int, int> > pairs;
    int straggler = -1;
    bool has_straggler = false;

    // Step 1: pair up elements, keep (smaller, larger) order
    std::list<int>::iterator it = lst.begin();
    while (it != lst.end())
    {
        int a = *it++;
        if (it != lst.end())
        {
            int b = *it++;
            if (a < b)
                pairs.push_back(std::make_pair(a, b));
            else
                pairs.push_back(std::make_pair(b, a));
        }
        else
        {
            straggler = a;
            has_straggler = true;
        }
    }

    // Step 2: build main chain (larger of each pair) and pending chain (smaller)
    std::list<int> main_chain;
    std::list<int> pending;
    for (std::list<std::pair<int, int> >::iterator p = pairs.begin(); p != pairs.end(); ++p)
    {
        main_chain.push_back(p->second);
        pending.push_back(p->first);
    }

    // Step 3: recursively sort main chain
    PmergeMe::sortList(main_chain);

    int j0 = 0, j1 = 1;
    int pending_size = (int)pending.size();

    while (j0 < pending_size)
    {
        int j2 = j1 + 2 * j0;

        for (int k = std::min(j1, pending_size); k > j0; --k)
        {
            std::list<int>::iterator it = pending.begin();
            std::advance(it, k - 1);

            insertBinarySearchList(main_chain, *it);
        }

        j0 = j1;
        j1 = j2;
    }

    // Step 6: insert straggler if odd number of elements
    if (has_straggler)
        insertBinarySearchList(main_chain, straggler);

    lst = main_chain;
}

void PmergeMe::sortVector(std::vector<int> &vec)
{
    if (vec.size() <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;
    bool has_straggler = false;

    // Step 1: pair up elements, keep (smaller, larger) order
    std::vector<int>::iterator it = vec.begin();
    while (it != vec.end())
    {
        int a = *it++;
        if (it != vec.end())
        {
            int b = *it++;
            if (a < b)
                pairs.push_back(std::make_pair(a, b));
            else
                pairs.push_back(std::make_pair(b, a));
        }
        else
        {
            straggler = a;
            has_straggler = true;
        }
    }

    // Step 2: build main chain (larger of each pair) and pending chain (smaller)
    std::vector<int> main_chain;
    std::vector<int> pending;
    for (std::vector<std::pair<int, int> >::iterator p = pairs.begin(); p != pairs.end(); ++p)
    {
        main_chain.push_back(p->second);
        pending.push_back(p->first);
    }

    // Step 3: recursively sort main chain
    PmergeMe::sortVector(main_chain);


    int j0 = 0, j1 = 1;
    int pending_size = (int)pending.size();

    while (j0 < pending_size)
    {
        int j2 = j1 + 2 * j0;
        for (int k = std::min(j1, pending_size); k > j0; --k)
            insertBinarySearchVector(main_chain, pending[k - 1]);
        j0 = j1;
        j1 = j2;
    }
    

    if (has_straggler)
        insertBinarySearchVector(main_chain, straggler);

    vec = main_chain;
}
