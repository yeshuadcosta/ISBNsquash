#include <iostream>
#include <string>

bool validate(std::string ISBNnumber, int len) {
    bool flag{ true };
    int temp{ 0 };

    // Checking whether each element of the string input is a numeral
    for (int a{ 0 }; a < static_cast<int>(ISBNnumber.length()); a++) {
        temp = ISBNnumber.at(a);
        if ((temp >= 48 && temp <= 57) || temp == 'X' || temp == 'x')
            continue;
        else {
            flag = false;
            std::cout << "You have entered invalid characters when you should have entered numbers!" << std::endl;
            break;
        }
    }

    // Checking whether the length of the string input is valid
    if (static_cast<int>(ISBNnumber.length()) != len) {
        std::cout << "You have entered " << ISBNnumber.length() << " digits when you should have entered " << len << std::endl;
        flag = false;
    }

    return flag;
}
