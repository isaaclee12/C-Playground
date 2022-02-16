//
// Created by Isaac on 2/15/2022.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
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
//    ifstream inFile("C:\\Users\\isaac\\Documents\\[Coding Projects]\\data-bubble-connector\\dictionary.txt");
//    ofstream outFile("C:\\Users\\isaac\\Documents\\[Coding Projects]\\data-bubble-connector\\results.txt");

    ifstream inFile(R"(C:\Users\isaac\Documents\[Coding Projects]\C-Playground\dictionary.txt)");
    ofstream outFile("results.txt");


    string line;
    time_t start, end;
    letters = {'l', 'a', 'd', 'y', 'b', 'u', 'g'};
    bool wordIsValid;

    // for every line in file
    time(&start);

    while (getline(inFile, line)) {
        cout << line << endl;
        outFile << line << endl;

        // Don't assume the word is valid yet
        wordIsValid = false;

        // for every char in str
        for (auto &ch : line) {

            // if chars in vector not in word, don't add word to outfile
            wordIsValid = findMatch(ch, line);

            if (wordIsValid) {
                // Add word to file
                outFile << line << endl;
            }
        }
    }

    time(&end);

    int totalTime = end - start;
    cout << totalTime << "s";

    inFile.close();
    outFile.close();

}