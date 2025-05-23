#include <iostream>
#include <cassert>
#include <string> 
#include <cstdlib>

bool check_one_remove(std::string longer, std::string shorter) {
    size_t longer_index = 0;
    size_t shorter_index = 0;
    while (longer_index < longer.length() && shorter_index < shorter.length() && longer[longer_index] == shorter[shorter_index]) {
        longer_index++;
        shorter_index++;
    }
    longer_index++;
    while (longer_index < longer.length() && shorter_index < shorter.length() && longer[longer_index] == shorter[shorter_index]) {
        longer_index++;
        shorter_index++;
    }
    if (longer_index == longer.length() && shorter_index == shorter.length()) {
        return true;
    }
    return false;
}

bool check_replace_char(std::string str1, std::string str2) {
    assert(str1.length() == str2.length());
    int mismatches = 0;
    for (int i=0; i<str1.length(); i++) {
        if (str1[i] != str2[i]) {
            if (++mismatches > 1) {
                return false;
            }
        }
    }
    return mismatches <= 1;
}

bool is_one_away(std::string str1, std::string str2) {
    int absolute_difference = std::abs(static_cast<int>(str1.length()) - static_cast<int>(str2.length()));
    if (absolute_difference > 1) {
        return false;
    } else if (absolute_difference == 1) {
        // must either insert one character or remove one to be equal
        // checking if you can insert a character or remove a character has the same
        // condition, so I only check for one.
        if (str1.length() > str2.length()) {
            return check_one_remove(str1, str2);
        } else {
            return check_one_remove(str2, str1);
        }
    } else {
        return check_replace_char(str1, str2);
    }
}

int main() {
    std::string pale = "pale";
    std::string ple = "ple";
    std::string pales = "pales";
    std::string bale = "bale";
    std::string bake = "bake";
    assert(is_one_away(pale, pale) == true);
    assert(is_one_away(pale, ple) == true);
    assert(is_one_away(pales, pale) == true);
    assert(is_one_away(pale, bale) == true);
    assert(is_one_away(pale, bake) == false);
    assert(is_one_away("a", "") == true);
    assert(is_one_away("", "") == true);
    assert(is_one_away("a", "b") == true);
    assert(is_one_away("ab", "cd") == false);
    std::cout << "All tests were passed." << std::endl;
    return 0;
}