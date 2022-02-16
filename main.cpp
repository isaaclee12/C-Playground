//
// Created by Isaac on 2/15/2022.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<char> letters;
char reqLetter = 'g';

bool findMatch(char ch, const string& word) {
    for (auto &ch2 : letters) {
        if (ch == ch2) {
            // If we find a match, keep going through the word
            return true;
        }
    }

    // otherwise return false
    return false;
}

int main() {
//    ifstream fin("C:\\Users\\isaac\\Documents\\[Coding Projects]\\data-bubble-connector\\dictionary.txt");
//    ofstream fout("C:\\Users\\isaac\\Documents\\[Coding Projects]\\data-bubble-connector\\results.txt");

    ifstream fin("dictionary.txt");
    ofstream fout("results.txt");

    string line;
    letters = {'l', 'a', 'd', 'y', 'b', 'u', 'g'};
    bool wordIsValid;
    bool foundLetterMatch;

    // for every line in file
    while (getline(fin, line)) {
        cout << line << endl;

        // Don't assume the word is valid yet
        wordIsValid = false;

        // for every char in str
        for (auto &ch : line) {

            // if chars in vector not in word, don't add word to outfile
            wordIsValid = findMatch(ch, line);

            if (wordIsValid) {
                // Add word to file
                fout << line << endl;
            }
        }
    }

    fin.close();
    fout.close();

}


