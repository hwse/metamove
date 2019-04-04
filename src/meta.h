#include<istream>

namespace id3 {

    void check_header(std::istream& stream);

    void check_version(std::istream& stream);

    void check_flags(std::istream& stream);

    int get_size(std::istream& stream);

}