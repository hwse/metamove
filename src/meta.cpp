#include<iostream>
#include<stdexcept>
#include<bitset>

#include "meta.h"
#include "error.h"
#include "util.h"

namespace id3 {

    void check_header(std::istream& stream) {
        char h0, h1, h2;
        stream >> h0 >> h1 >> h2;
        std::cout << "header: " << h0 << h1 << h2 << std::endl;
        if (!(h0 == 'I' && h1 == 'D' && h2 == '3')) {
            throw std::runtime_error("id3 header did not start with 'ID3'");
        }
    }

    void check_version(std::istream& stream) {
        unsigned char major, minor;
        stream >> major >> minor;
        std::cout << "major: " << +major << " minor: " << +minor << std::endl; 
    }

    void check_flags(std::istream& stream) {
        char flags;
        stream >> flags;
        std::bitset<8> bit_flags(flags);
        std::cout << "flags: " << bit_flags << std::endl;
    }

    int get_size(std::istream& stream) {
        int header_size;
        stream >> header_size;
        header_size = from_big_endian(header_size);
        std::cout << "header size: " << header_size << std::endl;
        return header_size;
    }

}