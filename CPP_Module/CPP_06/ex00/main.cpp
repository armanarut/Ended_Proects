#include "Conversion.hpp"

int main(int argc, char *argv[])
{
	std::string str;

	if (argc == 1) {
		std::cerr << "**invalid count of arguments**" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; i++)
		str.append(argv[i]);

	Conversion cast(str);

    return 0;
}
