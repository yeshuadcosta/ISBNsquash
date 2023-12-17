#include <string>
#include <iostream>

namespace check {
    bool calculate10(std::string ISBNnumber, int len) {
        bool flag{ false };
        int cDigit{ 0 };
        int sum{ 0 };
        int num{ 10 };

        for (int a{ 0 }; a < len - 1; a++, num--) {
            sum += (ISBNnumber.at(a) - '0') * num;
        }

        while ((sum + cDigit) % 11 != 0) {
            cDigit++;
        }

        if (ISBNnumber.at(len - 1) == 'X' || ISBNnumber.at(len - 1) == 'x') {
            if (cDigit == 10)
                flag = true;
            else
                flag = false;
        }
        else if (cDigit == static_cast<int>(ISBNnumber.at(len - 1) - '0'))
            flag = true;
        else
            flag = false;

        if (flag == true)
            std::cout << "The check digit is " << cDigit << std::endl;

        return flag;
    }
}
