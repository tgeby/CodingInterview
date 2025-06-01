#include <iostream>
#include <string>
#include <cassert>

bool isRotation(std::string str1, std::string str2) {
    if (str1 == str2)
        return true;
    if (str1.length() != str2.length())
        return false;

    for (int i = 1; i < str2.length(); i++) {
        std::string one_start = str1.substr(0, i);
        std::string one_end = str1.substr(i, str1.length()-i);
        std::string two_start = str2.substr(0, str2.length() - i);
        std::string two_end = str2.substr(str2.length()-i, i);

        if (one_start == two_end && one_end == two_start) {
            return true;
        }
    }
    return false;
}

bool isRotationImproved(std::string str1, std::string str2) {
    std::string str1_double = str1 + str1;
    if (str1.length() == str2.length() && str1_double.find(str2) != std::string::npos)
        return true;
    return false;
}

int main() {
    assert(isRotation("waterbottle", "erbottlewat") ==  true);
    assert(isRotation("waterbottle", "bottlewatera") == false);
    assert(isRotation("abc", "ab") == false);
    assert(isRotation("rotation", "rotation") == true);
    assert(isRotation("abcde", "bcdea") == true);
    assert(isRotation("abcde", "cdeab") == true);
    assert(isRotation("", "a") == false);
    assert(isRotation("", "") == true);
    assert(isRotation("a", "b") == false);
    assert(isRotation("x", "x") == true);
    assert(isRotation("abcdefghij", "fghijabcde") == true);
    assert(isRotation("abcdefghij", "ghijabcdef") == true);

    assert(isRotationImproved("waterbottle", "erbottlewat") ==  true);
    assert(isRotationImproved("waterbottle", "bottlewatera") == false);
    assert(isRotationImproved("abc", "ab") == false);
    assert(isRotationImproved("rotation", "rotation") == true);
    assert(isRotationImproved("abcde", "bcdea") == true);
    assert(isRotationImproved("abcde", "cdeab") == true);
    assert(isRotationImproved("", "a") == false);
    assert(isRotationImproved("", "") == true);
    assert(isRotationImproved("a", "b") == false);
    assert(isRotationImproved("x", "x") == true);
    assert(isRotationImproved("abcdefghij", "fghijabcde") == true);
    assert(isRotationImproved("abcdefghij", "ghijabcdef") == true);
    std::cout << "All tests were passed." << std::endl;
}