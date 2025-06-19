/*

Given a list of strings (e.g., ["abc", "cba", "bca", "xyz", "zyx", "foo", "oof"]), group them into categories where each group contains strings that are anagrams of each other (i.e., they contain exactly the same characters, possibly in a different order).

input: std::vector<std::string> input = {"abc", "cba", "bca", "xyz", "zyx", "foo", "oof"};

output: {
  {"abc", "cba", "bca"},
  {"xyz", "zyx"},
  {"foo", "oof"}
}

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& input) {
    std::unordered_map<std::string, std::vector<std::string>> anagramGroups;

    for (const auto& word : input) {
        std::string sortedWord = word;
        std::sort(sortedWord.begin(), sortedWord.end());
        anagramGroups[sortedWord].push_back(word);
    }

    std::vector<std::vector<std::string>> result;
    for (auto& pair : anagramGroups) {
        result.push_back(std::move(pair.second));
    }

    return result;
}

int main() {
    std::vector<std::string> input = {"abc", "cba", "bca", "xyz", "zyx", "foo", "oof"};

    auto groups = groupAnagrams(input);

    std::cout << "{\n";
    for (const auto& group : groups) {
        std::cout << "  { ";
        for (const auto& word : group) {
            std::cout << "\"" << word << "\" ";
        }
        std::cout << "}\n";
    }
    std::cout << "}\n";

    return 0;
}
