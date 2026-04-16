#include "easyfind.hpp"
#include <map>
#include <iostream>

int main()
{
    try
    {
        std::map<int, int> nums;
        nums[1] = 1;
        nums[2] = 2;
        nums[3] = 3;
        nums[4] = 4;
        nums[5] = 5;

        std::map<int, int>::iterator it = easyfind(nums, 3);
        std::cout << "Element found: " << it->second << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
