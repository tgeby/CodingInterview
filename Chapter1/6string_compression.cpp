#include <iostream>
#include <string>
#include <cassert>

std::string compress_string(std::string str) {
    if (str.length() < 3) {return str;}
    std::string compressed_string;
    compressed_string.reserve(str.length());
    compressed_string += str[0];
    int duplicates = 1;
    char previous_char = str[0];
    for (int i=1; i<str.length(); i++) {
        if (str[i] == previous_char) {
            duplicates++;
        } else {
            compressed_string += std::to_string(duplicates);
            previous_char = str[i];
            compressed_string += str[i];
            duplicates = 1;
        }
    }
    compressed_string += std::to_string(duplicates);
    if (compressed_string.length() < str.length()) {
        return compressed_string;
    }
    return str;
}

int main() {
    std::string one = "aabcccccaaa";
    std::string two = "abcde"; 
    std::string one_compressed = compress_string(one);
    std::string two_compressed = compress_string(two);
    assert(two_compressed == "abcde");
    assert(one_compressed == "a2b1c5a3");
    std::cout << "All tests were passed." << std::endl;
    return 0;
}