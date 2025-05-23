#include <iostream>
#include <cassert>
#include <string>

void shift_right(std::string& str, int start_index, int shift_size) {
    for (int i=str.length()-1; i>start_index; i--) {
        str[i] = str[i-shift_size];
    }
}

void urlify(std::string& str, int length) {
    for (int i=0; i<length; i++) {
        if (str[i] == ' ') {
            shift_right(str, i, 2);
            str[i] = '%';
            str[i+1] = '2';
            str[i+2] = '0';
        }
    }
    return;
}

int main() {
    std::string string_one = "Mr John Smith    ";
    urlify(string_one, 13);
    std::cout << string_one << std::endl;
    assert(string_one == "Mr%20John%20Smith");
    std::cout << "All tests were passed." << std::endl;
    return 0;
}