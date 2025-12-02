#include <bits/stdc++.h>
#include <iostream>
#include <cctype>
using namespace std;

void isPalindrome(string word) {
    string rev = word;

    reverse(word.begin(), word.end());

    if (word == rev)
        cout << "True" << endl;
      
    else
        cout << "False" << endl;
}

void to_upper(string &s)
{
    for (char &c : s)
        c = static_cast<char>(toupper(static_cast<unsigned char>(c)));
}


int main() {
    string word1;
    string word2;
    cout << "masukkan kata kata : ";
    getline(cin, word1);

    for (char c : word1) {
        if (isalnum(static_cast<unsigned char>(c))) {
            word2 += c;
        }
    }

    to_upper(word2);
	cout << "Hasil untuk '" << word1 << "': "; isPalindrome(word2);

    return 0;
}