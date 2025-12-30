#include <fstream>
#include <iostream>
#include <string>

bool isInvalid(long long num) {
    std::string numStr = std::to_string(num);
    int len = numStr.length();
    
    for (int patternLen = 1; patternLen <= len / 2; patternLen++) {
        if (len % patternLen != 0) {
            continue;
        }
        
        std::string pattern = numStr.substr(0, patternLen);
        int repetitions = len / patternLen;
        
        if (repetitions < 2) {
            continue;
        }
        
        bool isRepeated = true;
        for (int i = 0; i < len; i++) {
            if (numStr[i] != pattern[i % patternLen]) {
                isRepeated = false;
                break;
            }
        }
        
        if (isRepeated) {
            return true;
        }
    }
    
    return false;
}

int main(void)
{
    std::ifstream infile("input.txt");
    std::string line;
    long long totalSum = 0;

    std::getline(infile, line);

    size_t pos = 0;
    while (pos < line.length()) {
        size_t commaPos = line.find(',', pos);
        if (commaPos == std::string::npos) {
            commaPos = line.length();
        }
        
        std::string range = line.substr(pos, commaPos - pos);
        
        size_t dashPos = range.find('-');
        long long start = std::stoll(range.substr(0, dashPos));
        long long end = std::stoll(range.substr(dashPos + 1));
        
        for (long long num = start; num <= end; num++) {
            if (isInvalid(num)) {
                totalSum += num;
            }
        }
        
        pos = commaPos + 1;
    }

    std::cout << totalSum << std::endl;
    
    infile.close();
    return 0;
}
