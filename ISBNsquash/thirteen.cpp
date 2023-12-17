#include <iostream>
#include <string>

namespace check {
    bool calculate13(std::string ISBNnumber, int len) {
        bool flag{ false };
        int cDigit{ 0 };
        int sum{ 0 };

        for (int a{ 0 }; a < len - 1; a++) {
            if (a % 2 == 0)
                sum += (ISBNnumber.at(a) - '0');
            else
                sum += (ISBNnumber.at(a) - '0') * 3;
        }

        if (sum % 10 < 10 == false)
            flag = false;
        else if ((sum % 10 == 0) && static_cast<int>(ISBNnumber.at(len - 1) - '0') == 0) {
            cDigit = 0;
            flag = true;
        }
        else if (static_cast<int>(ISBNnumber.at(len - 1) - '0') == (10 - sum % 10)) {
            cDigit = 10 - sum % 10;
            flag = true;
        }
        else
            flag = false;

        if (flag == true)
            std::cout << "The check digit is " << cDigit << std::endl;

        return flag;
    }
}
