#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <limits>
#include "essential.h"

class ISBNVerify {

private:
    std::string ISBNnumber{ "" };
    int len{ 0 };
    int choice{ 0 };
    bool flag{ false };

public:
    void input() {
        std::cout << "ISBN-VERIFIER"
            << std::endl
            << "************************"
            << std::endl;
    label0:
        std::cout << "1. 10-DIGIT ISBN NUMBER" << '\n' << "2. 13-DIGIT ISBN NUMBER" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {

        case 1:
            len = 10;
            // User Input for the 10 DIGIT ISBN Number
        label1:
            std::cout << "Enter the 10-DIGIT ISBN Number: ";
            std::cin >> ISBNnumber;

            if (validate(ISBNnumber, len) == false)
                goto label1;

            flag = check::calculate10(ISBNnumber, len);
            break;

        case 2:
            len = 13;
            // User Input for the 13 DIGIT ISBN Number
        label2:
            std::cout << "Enter the 13-DIGIT ISBN Number: ";
            std::cin >> ISBNnumber;

            if (validate(ISBNnumber, len) == false)
                goto label2;

            flag = check::calculate13(ISBNnumber, len);
            break;

        default:
            std::cout << "Invalid Choice! Enter either '1' or '2'" << std::endl;
            goto label0;
        }
    }

    void output() {
        if (flag == true)
            std::cout << "The ISBN Number provided is valid!" << std::endl;
        else if (flag == false)
            std::cout << "The ISBN Number provided is invalid!" << std::endl;
    }
};

int main() {
    ISBNVerify code{};
    code.input();
    code.output();

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return EXIT_SUCCESS;
}
