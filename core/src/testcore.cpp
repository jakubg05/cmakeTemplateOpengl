#include <testcore.h>
#include <iostream>
#include <fstream>
#include <string>

void helloworld() {
	std::cout << "hello world from core" << std::endl;
}

void readtxtfile() {
	std::ifstream file(RESOURCES_PATH "file.txt");

	//read the file
	std::string str((std::istreambuf_iterator<char>(file)),
		std::istreambuf_iterator<char>());
	std::cout << str;
}