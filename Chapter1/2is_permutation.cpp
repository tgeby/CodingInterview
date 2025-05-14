// 2is_permutation.cpp

#include <iostream>
#include <string>
#include <unordered_map>

bool are_permutations(std::string& word_one, std::string& word_two) {
    std::unordered_map<char, int> word_one_map;
    for (char c : word_one) {
        if (word_one_map.find(c) != word_one_map.end()) {
            word_one_map[c] = word_one_map[c] + 1;
        } else {
            word_one_map[c] = 1;
        }
    }
    for (char c : word_two) {
        if (word_one_map.find(c) == word_one_map.end()) {
            return false;
        } else if (word_one_map[c] == 0) {
            return false;
        } else {
            word_one_map[c] = word_one_map[c] - 1;
        }
    }
    for (const auto& pair: word_one_map) {
        if (pair.second > 1) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string word_one = "listen";
    std::string word_two = "silent";
    std::string word_three = "lent is";
    std::string word_four = "abe";
    if (are_permutations(word_one, word_two)) {
        std::cout << '"' << word_one << "\" and \"" << word_two << "\" are permutations of each other." << std::endl;
    } else {
        std::cout << '"' << word_one << "\" and \"" << word_two << "\" are NOT permutations of each other." << std::endl;
    }
    if (are_permutations(word_one, word_three)) {
        std::cout << '"' << word_one << "\" and \"" << word_three << "\" are permutations of each other." << std::endl;
    } else {
        std::cout << '"' << word_one << "\" and \"" << word_three << "\" are NOT permutations of each other." << std::endl;
    }
    if (are_permutations(word_one, word_four)) {
        std::cout << '"' << word_one << "\" and \"" << word_four << "\" are permutations of each other." << std::endl;
    } else {
        std::cout << '"' << word_one << "\" and \"" << word_four << "\" are NOT permutations of each other." << std::endl;
    }
    return 0;
}