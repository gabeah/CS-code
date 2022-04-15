// CS221 HW8 - Huffman Encoding (encoder.cc)
// By Yik Yin Cheuk

#include <iostream>
#include <fstream>
#include <string>
#include "huffman.hh"
#include "bitio.hh"

// Encodes a single file

void encode_func(char* file) {
    // First establishing our streams and files and checking that they're working
    std::ifstream input_file(file);
    std::string infile_name(file); // Get the name of our file as a string
    if (!input_file.is_open()) {
        std::cerr << "It seems that the file, '" + infile_name + "', can't be opened.";
        return;
    }
    std::ofstream output_file;
    output_file.open(infile_name + ".comp");
    if (!output_file.is_open()) {
        std::cerr << "We can't seem to compress this file.";
        return;
    }

    // Goes through input bit by bit through bitio, gets the compressed path to
    // that character in bits. BitIO pushes those bits into output file.
    Huffman huff;
    BitOutput bit_io(&output_file, nullptr);
    while (input_file.get(byte)) {
        Huffman::bits_t bit_path = huff.encode(byte);
        for (bool bit : bit_path) {
            bit_output.output_bit(bit);
        }
    }
    output_file.close();
}


//Checks there are an appropriate number of arguments, then encodes each one with a helper function
//In general, takes one or more files as input, and produces .comp compressed versions of those files.
int main(int arg_count, char** args) {
    if (arg_count < 2) {//arg_count counts itself so we make sure there is some other argument passed as well
        std::cerr << "You must provide an argument.";
        return 1;
    }
    int i = 1;
    while (i < arg_count) {
        encode_func(args[i]);
        i++;
    }
    return 0;
}
