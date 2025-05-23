#include <iostream>
#include <cassert>
#include <string>
#include <unordered_map>
#include <cctype>

bool is_palindrome_permutation(std::string str) {
    std::unordered_map<char, int> char_frequencies;
    for (char c : str) {
        char lower = std::tolower(c);
        if (char_frequencies.find(lower) == char_frequencies.end()) {
            char_frequencies[lower] = 1;
        } else {
            char_frequencies[lower] += 1;
        }
    }
    bool odd_found = false;
    for (const auto& pair : char_frequencies) {
        if (pair.first != ' ' && pair.second % 2 == 1) {
            if (odd_found) {
                return false;
            }
            odd_found = true;
        }
    }
    return true;
}

int main() {
    std::string input = "Tact Coa";
    std::string input2 = "Tact Voa";
    assert(is_palindrome_permutation(input) == true);
    assert(is_palindrome_permutation(input2) == false);
    std::cout << "All tests were passed." << std::endl;
    return 0;
}