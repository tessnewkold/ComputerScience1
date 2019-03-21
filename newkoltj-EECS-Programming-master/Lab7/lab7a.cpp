//Tess Newkold 
//Lab 7A

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
#include <cctype>

using namespace std;

int countChars(string input, char which_char){ // - Count the number of occurrencesin the input string
    int j = 0;
    int count = 0;
    for(j = 0; j < input.size(); j++){
        if (input[j] == which_char){
        count++;
        }
    }
  return count; 
}
    

int upperCaseChars(string numChars){ // - Given a string, return the number of uppercase characters.  Use isupper from the cctype library.
    int i = 0;
    int count = 0;
    for(i = 0; i < numChars.size(); i++){
    if (isupper(numChars[i])){
        count ++;  
    }
}
 return count; 
}

int lowerCaseChars( string numChars){// - Given a string, return the number of lowercase characters.  Use islower from the cctype library..
    int i = 0;
    int count = 0;
    for(i = 0; i < numChars.size(); i++){
    if (islower(numChars[i])){
    count ++;
    }
}
 return count; 
}

int numPunct( string numChars){//- Given a string, return the number of punctuation characters.  Use ispunct from the cctype library.
    int i = 0;
    int count = 0;
    for(i = 0; i < numChars.size(); i++){
        if (ispunct(numChars[i]) ){
     count ++;
    }
}
 return count;
}

string stringToupper(string numChar){ //- Given a string as a parameter, return a new string converted to uppercase
    int i = 0;
    for (i = 0; i < numChar.size(); i++){
        if(numChar[i] > 96 && numChar[i] < 123){
        numChar[i] = toupper(numChar[i]);
    }
}
    return numChar;
}

string stringToLower(string numChar){//- Given a string as a parameter, return a new string converted to lowercase
    int i = 0;
    for (i = 0; i < numChar.size(); i++){
        if(numChar[i] > 64 && numChar[i] < 92){
        numChar[i] = tolower(numChar[i]);
    }
}
return numChar;
}


vector <int> characterCounts(string numChar){
//- Given a string, return a vector of ints of length 26 containing the number 
//of times each letter was seen.  Index 0 corresponds to ‘a’, 1 to ‘b’, etc…  
//Treat upper-case letters as lower-case letters. 
//Please verify that the character is an alphabet character before updating the vector.
//Do not use an if/else cascade or switch statements in the solution to this problem.

vector <int> values;
numChar = stringToLower(numChar); 
for (char a = 'a'; a < 'a' + 26; a++){
    int count = 0;  
    for ( int i = 0; i < numChar.size(); i++){
        if (numChar[i] == a){
        count++;
        }
    }
    values.push_back (count);
}
    return values;
}

int numLines(string numChar){
// - Given a string, return the number of lines of text it contains.
//In UNIX, lines of text are delimited by the ‘\n’ character.  Note that 
//a string of characters which does NOT include a \n is considered a single line.

int lines = 1;
int i = 0;
for (i = 0; i < numChar.size(); i++){
    if (numChar[i] == '\n'){
        lines++;
    }
    else{
        lines;
    }
}
    return lines;
}

int numWords(string numChar){ 
//- Given a string, return the number of words it contains.  A word is 
//defined to be a sequence of alphabetic (isalpha) characters with non-alphabetic
//characters on each side.  If alphabetic characters start or end the string, 
//they are considered a word.

int words = 0;
int i = 0;
int spaceMaybe = 0;

for(i = 0; i < numChar.size(); i++){
    spaceMaybe = numChar.at(i);
    if (isspace(numChar[i])){
        words++;
    }
}

return words;
}


string rightRotateString(string to_rotate, int offset){ 
//- Rotate a string towards the “right” by the number of characters indicated 
//by the offset. The characters rotated off the end of the string are moved to the front of the string.

}

int main(){
    
    
char testChar = 'a';    
string testString= "AabAc,b!*aPb";
string testString2 = " abra\n#cadadabra0 I know you...\nWANT ME! 988";
//cout << testString2 << endl;

cout << "Number of matching chars: " << countChars(testString, testChar) << endl;
cout << "Number of Uppercase: " << upperCaseChars(testString) << endl;
cout << "Number of lowercase: " << lowerCaseChars(testString) << endl;
cout << "Number of punct: " << numPunct(testString) << endl;
cout << "Convert to upper: " << stringToupper(testString) << endl;
cout << "Convert to Lower: " << stringToLower(testString) << endl;

vector <int> result = characterCounts(testString);

for (int i = 0; i < 26; i++)
{
cout << "Character counts at " << i <<  " are: " << result.at(i) << endl;
}

cout << "Number of lines: " << numLines(testString2) << endl;
cout << "Number of words: " << numWords(testString2) << endl;

    return 0;
}
