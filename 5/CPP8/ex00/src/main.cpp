#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
    try
    {
        std::vector<int> nums;
        nums.push_back(1);
        nums.push_back(2);
        nums.push_back(3);
        nums.push_back(4);
        nums.push_back(5);

        std::vector<int>::iterator it = easyfind(nums, 3);
        std::cout << "Element found: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
