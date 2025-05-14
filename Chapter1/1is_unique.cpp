// 1unique.cpp

#include <iostream>  // for std::cout and std::endl
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
    if (is_unique(word_one, false)) {
        std::cout << word_one << " has all unique letters." << std::endl;
    } else {
        std::cout << word_one << " has duplicate letters." << std::endl;
    }
    if (is_unique(word_two, false)) {
        std::cout << word_two << " has all unique letters." << std::endl;
    } else {
        std::cout << word_two << " has duplicate letters." << std::endl;
    }
    return 0;  
}
