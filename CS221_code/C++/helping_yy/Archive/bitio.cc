// CS221 HW8 - Huffman Encoding (bitio.cc)
// By Yik Yin Cheuk

#include "bitio.hh"
#include <cassert>

// Construct with input stream
BitInput::BitInput(std::istream& is)
  :instream_(is), pending_in_(0), count_(8){
}

// Read a single bit (or trailing zero)
bool BitInput::input_bit(){
  if (instream_.eof()){ // if next thing in istream is end
    std::cerr << "Past end of file." << '\n';
    throw ; // does an error
  }

  if (count_ == 8){ // have to do things in a byte (8 bits). if we've made it to 8, we can output a thing
    count_ = 0;
    pending_in_ = instream_.get(); // output the 8 bits we've assembled
  }
  count_++; // increment counter, could do anywhere after if statement
  
  auto ret = pending_in_ >> 7; //  ret == 0000000? where ? is the most sig digit of pending_in_
  pending_in_ = pending_in_ << 1; // move pending_in so we have a new most sig digit
  return ret;
}

// Construct with output stream
BitOutput::BitOutput(std::ostream& os) // start with LEAST SIGNIFICANT
  :outstream_(os), pending_out_(0), count_(0)
  {}

BitOutput::~BitOutput(){

  //if count isn't finished, output whatever you've got
  if (count_ != 0){
    int zeros = 8 - count_;
    pending_out_ = pending_out_ << (zeros);
    outstream_.put(pending_out_);
  }
 }

// Output a single bit (buffered)
void BitOutput::output_bit(bool bit){

  pending_out_ = pending_out_ << 1; // shift one to the left, make room for new bit
  pending_out_ = pending_out_ | bit; // logical or with new bit to add to end

  count_++;
  if (count_ == 8){ // we'll have a full byte of things waiting to go out
    count_ = 0;
    outstream_.put(pending_out_); // output our byte
    pending_out_ = 0; // empty output for next set of 8 bits
  }
 }
