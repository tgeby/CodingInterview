// 1unique.cpp

#include <cassert>
#include <iostream>
#include <string>
#include <unordered_set>

bool is_unique(const std::string& word, bool use_data_structures) {
    if (use_data_structures) {
        std::unordered_set<char> seen_letters;
        for (char c : word) {
            if (seen_letters.count(c) != 0) {
                return false;
            } else {
                seen_letters.insert(c);
            }
        }
        return true;
    } else {
        // TODO
        // I think the easiest no data structure approach is to loop across, and for each char it sees, 
        // it to the characters that come after it. That way, the first already seen characters are not 
        // checked again
        for (int i=0; i<word.length(); i++) {
            char current = word[i];
            for (int j=i+1; j<word.length(); j++) {
                if (current == word[j]) {
                    return false;
                }
            }
        }
        return true;
    }
}

int main() {
    std::string word_one = "apple";
    std::string word_two = "pear";
    assert(is_unique(word_one, false) == false);
    assert(is_unique(word_one, true) == false);
    assert(is_unique(word_two, false) == true);
    assert(is_unique(word_two, true) == true);
    std::cout << "All tests were passed." << std::endl;
    return 0;  
}
