#include <iostream>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::map;
/*
 * Missing Alphabet
 * Goal: Find the missing letters in the string generated/given
 * Plan:
 *      -clean up string, CAPS, symbols
 *      -traverse through string
 *      -take note of alphabet and occurrences (map)
 *      -loop through ascii alphabet values and
 *          those values that are not present, to the string
 *      - Only add missing letters to the string, not symbols
 *          multiply those chars by the highest amount of occurrences
 *
 */

/*  maxOccur(): find the largest occurrences in the map
 *  parameters: map<char, int> a
 *  return: max value
 */
int maxOccur(map<char, int> a){
    int max = 0;
    for (auto& [x, y]:a) {
        if (y >= max)
            max = y;
    }
    return max;
}
/*  isAlpha(): filter out ascii value that is not a letter
 *  parameters: char a
 *  return: bool
 */
bool isAlpha(char a){
    if (a >= 'a' && a <= 'z'){ return true; }
    return false;
}
/*  MissingAlpha(): Will traverse the given string and input those values in the map. Followed by, appending
 *                  the missing values into a string with the correct number of occurrences.
 *  parameters: string str, string of letters and their occurrences
 *  return: string of missing letters
 */
string MissingAlpha(string str){

    //Clean the string by eliminating probability of capital letters (different ascii)
    std::transform (str.begin(), str.end(), str.begin(), ::tolower);
    // return string
    string missing_letter;
    // occurrence multiplier
    int multiplier = 0;
    map<char, int> all_letters;
    //Loop through string and add them and the times occurred to a order map.
    for (int x = 0; str[x]; x++) {
        //Checks if the letter exists in the map, if not then creates a new map
        if (all_letters.find(str[x]) == all_letters.end()) {
            // Filters out non lower case alphabet
            if (isAlpha(str[x])){
                all_letters.insert(std::make_pair(str[x], 1));
            }
        }
        // if the letter exists in the map, then increment the value by 1++
        else { all_letters[str[x]]++; }
    }

    //Find multiplier only after the map is finished being constructed
    multiplier = maxOccur(all_letters);

    //Loop through all 26 ascii values and append those that don't exist in map.
    for (int a = 97; a <= 122; a++){
        if (all_letters.find((char) a) == all_letters.end()) {
            // multiple the ascii value by multiplier
            missing_letter += string(multiplier, (char) a);
        }
    }
    return missing_letter;
}

int main() {
    cout << "First attempt: " << "\t";
    cout << MissingAlpha("aAbbCcddeewWzz") << endl;

    cout << "Second attempt: " <<  "\t";
    cout << MissingAlpha("abcabcabcxyzxyz") << endl;

    cout << "Third attempt: " <<  "\t";
    cout << MissingAlpha("bdfhjlnprtvxz") << endl;

    return 0;
}