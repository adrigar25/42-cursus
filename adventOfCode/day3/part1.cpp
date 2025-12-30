#include <fstream>
#include <iostream>
#include <string>

int main(void)
{
    std::ifstream infile("input.txt");
    std::string line;
    long long totalSum = 0;

    while (std::getline(infile, line))
    {
        long long max1 = 0;
        size_t max1_pos = 0;
        
        for(size_t i = 0; i < line.length()-11; i += 1)
        {
            std::string numStr = line.substr(i, 1);
            long long num = std::stoll(numStr);
            if(num > max1)
            {
                max1 = num;
                max1_pos = i;
            }
        }
        
        long long max2 = 0;
        size_t max2_pos = 0;
        for(size_t j = max1_pos + 1; j < line.length()-10; j += 1)
        {
            std::string numStr = line.substr(j, 1);
            long long num = std::stoll(numStr);
            if(num > max2)
            {
                max2 = num;
                max2_pos = j;
            }
        }
        long long max3= 0;
        size_t max3_pos = 0;
        for(size_t j = max2_pos + 1; j < line.length()-9; j += 1)
        {
            std::string numStr = line.substr(j, 1);
            long long num = std::stoll(numStr);
            if(num > max3)
            {
                max3 = num;
                max3_pos = j;
            }
        }
        long long max4 = 0;
        size_t max4_pos = 0;
        for(size_t j = max3_pos + 1; j < line.length()-8; j += 1)
        {
            std::string numStr = line.substr(j, 1);
            long long num = std::stoll(numStr);
            if(num > max4)
            {
                max4 = num;
                max4_pos = j;
            }
        }
        long long max5 = 0;
        size_t max5_pos = 0;
        for(size_t j = max4_pos + 1; j < line.length()-7; j += 1)
        {
            std::string numStr = line.substr(j, 1);
            long long num = std::stoll(numStr);
            if(num > max5)
            {
                max5 = num;
                max5_pos = j;
            }
        }
        long long max6 = 0;
        size_t max6_pos = 0;
        for(size_t j = max5_pos + 1; j < line.length()-6; j += 1)
        {
            std::string numStr = line.substr(j, 1);
            long long num = std::stoll(numStr);
            if(num > max6)
            {
                max6 = num;
                max6_pos = j;
            }
        }
        long long max7 = 0;
        size_t max7_pos = 0;
        for(size_t j = max6_pos + 1; j < line.length()-5; j += 1)
        {
            std::string numStr = line.substr(j, 1);
            long long num = std::stoll(numStr);
            if(num > max7)
            {
                max7 = num;
                max7_pos = j;
            }
        }
        long long max8 = 0;
        size_t max8_pos = 0;
        for(size_t j = max7_pos + 1; j < line.length()-4; j += 1)
        {
            std::string numStr = line.substr(j, 1);
            long long num = std::stoll(numStr);
            if(num > max8)
            {
                max8 = num;
                max8_pos = j;
            }
        }
        long long max9 = 0;
        size_t max9_pos = 0;
        for(size_t j = max8_pos + 1; j < line.length()-3; j += 1)
        {
            std::string numStr = line.substr(j, 1);
            long long num = std::stoll(numStr);
            if(num > max9)
            {
                max9 = num;
                max9_pos = j;
            }
        }
        long long max10 = 0;
        size_t max10_pos = 0;
        for(size_t j = max9_pos + 1; j < line.length()-2; j += 1)
        {
            std::string numStr = line.substr(j, 1);
            long long num = std::stoll(numStr);
            if(num > max10)
            {
                max10 = num;
                max10_pos = j;
            }
        }
        long long max11 = 0;
        size_t max11_pos = 0;
        for(size_t j = max10_pos + 1; j < line.length()-1; j += 1)
        {
            std::string numStr = line.substr(j, 1);
            long long num = std::stoll(numStr);
            if(num > max11)
            {
                max11 = num;
                max11_pos = j;
            }
        }
        long long max12 = 0;
        size_t max12_pos = 0;
        for(size_t j = max11_pos + 1; j < line.length(); j += 1)
        {
            std::string numStr = line.substr(j, 1);
            long long num = std::stoll(numStr);
            if(num > max12)
            {
                max12 = num;
                max12_pos = j;
            }
        }
        std::cout << "Max numbers: " << max1 << max2 << max3 << max4 << max5 << max6 << max7 << max8 << max9 << max10 << max11 << max12 << std::endl;
    
    totalSum += std::stoll(std::to_string(max1) + std::to_string(max2) + std::to_string(max3) + std::to_string(max4) + std::to_string(max5) + std::to_string(max6) + std::to_string(max7) + std::to_string(max8) + std::to_string(max9) + std::to_string(max10) + std::to_string(max11) + std::to_string(max12));

    std::cout << totalSum << std::endl;
    }
    
    infile.close();
    return 0;
}
