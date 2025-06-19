#include<iostream>
using namespace std;

int main() {
    string s = "hello world";
    string k = "aeiouAEIOU";

    for(int i = 0; i < s.size(); i++) {
        if(k.find(s[i]) != string::npos) {
            cout << s[i] << " ";
        }
    }

    cout << endl;
    return 0;
}