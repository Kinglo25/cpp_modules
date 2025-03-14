#include <iostream>
#include <bitset>
#include "Data.hpp"

int main()
{
	Data input;

	input.firstName = "Loic";
	input.lastName = "mjr";
	input.nickname = "lomajeru";
	input.age = 30;
	input.level = 5;

	std::cout << "first name: " << input.firstName << std::endl;
	std::cout << "last name: " << input.lastName << std::endl;
	std::cout << "nickname: " << input.nickname << std::endl;
	std::cout << "age: " << input.age << std::endl;
	std::cout << "level: " << input.level << std::endl;

	std::cout << "------------------------" << std::endl;

	uintptr_t output_uintptr = serialize(&input);

	Data* output = deserialize(output_uintptr);

	std::cout << "first name: " << output->firstName << std::endl;
	std::cout << "last name: " << output->lastName << std::endl;
	std::cout << "nickname: " << output->nickname << std::endl;
	std::cout << "age: " << output->age << std::endl;
	std::cout << "level: " << output->level << std::endl;
}