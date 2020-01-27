#include "libencoding/encoding.h"
#include <cstdint>
#include <fstream>
#include <iostream>
#include <variant>

int main(int argc, char const **argv) {
	assert(argc == 2);
	std::ifstream input(*++argv, std::ios::binary);
	unsigned char encoding[4];
	while (input.read(reinterpret_cast<char *>(encoding), sizeof(encoding))) {
		std::visit([](auto &&instruction) {
			std::cout << instruction << std::endl;
		},
		           regular::createInstruction(encoding[0] | encoding[1] << 8 | encoding[2] << 16 | encoding[3] << 24));
	}
	return 0;
}
