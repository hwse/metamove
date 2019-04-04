#include<algorithm>

namespace id3 {
    constexpr bool is_big_endian_system() {
        union {
            unsigned int i;
            char c[4];
        } bint = {0x01020304};
        return bint.c[0] == 1; 
    }

    constexpr bool is_little_endian_system() {
        return !is_big_endian_system();
    }

    template<typename T>
    void endian_swap(T* object) {
        unsigned char* pointer = reinterpret_cast<unsigned char*>(object);
        std::reverse(pointer, pointer + sizeof(T)); 
    }

    template<typename T>
    T from_big_endian(T nr) {
        if (!is_big_endian_system())
            endian_swap(&nr);
        return nr;
    }

}