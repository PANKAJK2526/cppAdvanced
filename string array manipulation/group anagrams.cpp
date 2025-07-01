/*

Given a list of strings (e.g., ["abc", "cba", "bca", "xyz", "zyx", "foo", "oof"]), group them into categories where each group contains strings that are anagrams of each other (i.e., they contain exactly the same characters, possibly in a different order).

input: std::vector<std::string> input = {"abc", "cba", "bca", "xyz", "zyx", "foo", "oof"};

output: {
  {"abc", "cba", "bca"},
  {"xyz", "zyx"},
  {"foo", "oof"}
}

*/

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{

  string input[] = {"abc", "cba", "bca", "xyz", "zyx", "foo", "oof"};
  map<string, vector<string>> anagramGroups;

  for(auto i: input)
  {
    string sortedWord = i;
    sort(sortedWord.begin(), sortedWord.end());
    anagramGroups[sortedWord].push_back(i);
  }

  for(auto i: anagramGroups)
  {
    for(auto j: i.second)
    {
      cout<<j<<",";
    }
    cout<<endl;
  }

  return 0;
}