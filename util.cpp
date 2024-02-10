#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;

std::string convToLower(std::string src) {
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}


/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(const string &rawWords) {
    std::set<std::string> words;
    std::string word;
    std::stringstream ss(rawWords);
    while (ss >> word) {
        word = convToLower(word);
        word = trim(word);
        int nextPunc;
        while (word.size() > 2) {
            string piece;
            // Find the next punctuation
            if (nextPunc = word.find_first_of(".,;:!?()[]{}") != string::npos) {
                piece = word.substr(0, nextPunc);
                word = word.substr(nextPunc + 1);
            } else {    // No punctuation
                piece = word;
                word = "";
            }
            if (piece.size() > 2)
                words.insert(piece);
        }
    }
    return words;
}


/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(),
            std::find_if(s.begin(),
                         s.end(),
                         std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
            std::find_if(s.rbegin(),
                         s.rend(),
                         std::not1(std::ptr_fun<int, int>(std::isspace))).base(),
            s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
