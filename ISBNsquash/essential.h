#ifndef ESSENTIAL
#define ESSENTIAL
bool validate(std::string ISBNnumber, int len);

namespace check {
	bool calculate10(std::string ISBNnumber, int len);
	bool calculate13(std::string ISBNnumber, int len);
}
#endif
