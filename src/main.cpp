#include<iostream>
#include<fstream>
#include<type_traits>

#include "meta.h"
#include "util.h"

int main(int argc, char const *argv[])
{
    std::cout << "little endian: " << id3::is_little_endian_system() << std::endl;
    unsigned int x = 0x01000000;
    std::cout << "on this system: " << x << " to big endian: " << id3::from_big_endian(x) << std::endl; 

    std::ifstream files_stream(argv[1]);
    id3::check_header(files_stream);
    id3::check_version(files_stream);
    id3::check_flags(files_stream);
    id3::get_size(files_stream);
    return 0;
}
