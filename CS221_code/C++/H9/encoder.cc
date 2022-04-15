#include "huffman.hh"
#include "bitio.hh"
#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
    std::vector<std::string> args(argv, argv + argc);

    if (argc == 1) {
        std::cout << "Usage: " << args[0] << " [filename]" << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        std::ifstream in(args[i]);
        if (!in.is_open()) {
            std::cout << "Cannot open file!" << std::endl;
            return 2;
        }
        std::ofstream ofs(args[i] + ".comp");
        if (!ofs.is_open()) {
            std::cout << "Cannot write to new file!" << std::endl;
            return 3;
        }
        BitOutput out(ofs);

        Huffman huff;
        char byte = 0;

        while (in.get(byte)) {
            auto bits = huff.encode(byte);
            for (auto bit: bits) {
                out.output_bit(bit);
            }
        }
        auto bits = huff.encode(Huffman::HEOF);
        for (auto bit: bits) {
            out.output_bit(bit);
        }
    }
}
