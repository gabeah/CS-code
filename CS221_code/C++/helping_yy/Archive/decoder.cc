// CS221 HW8 - Huffman Encoding (decoder.cc)
// By Yik Yin Cheuk

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "huffman.hh"
#include "bitio.hh"

// Takes a file as input and produces a .plaintext of that file, which will be a
// decompression of the .comp of that file.
void decode_func(char* file) {
    std::ifstream input_file(file);
    std::string infile_name(file); // Gets the name so we can use it in our decoded file name
    if (!input_file.is_open()) {
        std::cerr << "It seems that the file, '" + infile_name + "', can't be opened.";
        return;
    }
    std::ofstream output_file;
    output_file.open(infile_name + ".plaintext");
    if (!output_file.is_open()) {
        std::cerr << "We can't seem to compress this file.";
        return;
    }
    // Goes through input bit by bit through bitio, feeds each bit into huffman,
    // and huffman pushes to the outfile when it has a completed character.
    Huffman huff;
    BitIO bit_io(nullptr, &input_file); //The same case as encoder for where the destruction of this object occurs;
    //apparently it still works.
    while (input_file) {
        bool bit = bit_io.input_bit();
        int symbol = huff.decode(bit);
        if (symbol >= 0)
        {
            output_file << char(symbol);
        }
    }
    output_file.close();
    return;
}

// Takes one or more files as arguments and produces .plaintext decompressions of them.
int main(int arg_count, char** args) {
    if (arg_count < 2) { // Counts itself to make sure there is some other argument passed as well
        std::cerr << "You must provide an argument.";
        return -1;
    }
    int i = 1;
    while (i < arg_count) {
        decode_func(args[i]);
        i++;
    }
    return 0;
}
