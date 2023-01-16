#include <iostream>

struct Data {
	int num;
	char c;
	std::string str;
};

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main( void )
{
	Data *data = new Data;
	data->num = 10;
	data->c = 'h';
	data->str = "hello world";

	std::cout << "pointer data: " << (uintptr_t)data << std::endl;
	

	uintptr_t num1 = serialize(data);
	std::cout << "serialize:    " << num1 << std::endl;

	Data *data1 = deserialize(num1);
	std::cout << "deserialize:  "  << (uintptr_t)data1 << std::endl;

	delete data;

    return 0;
}
