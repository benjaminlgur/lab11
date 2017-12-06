#include <iostream>
#include <string>

using namespace std;

bool isEven(string s);
//Precondition: s is a string with bracket symbols other ascii charecters may be included.
//Postconditon: Will return true if there is an even amount of bracket symbols in s.
bool wellFormed(string s);
////Precondition: s is a string with bracket symbols other ascii charecters may be included.
//Postconditon: Will return true if s is considered wellformed.
int nestLevel(string s);
//Precondition: s is a string with bracket symbols other ascii charecters may be included but must be wellformed.
//Postcondition: will return an int of how many levels of nesting within the string s.
int lengthCheck(string s);
//Precondition:  s is a string with bracket symbols other ascii charecters may be included.
//Postcondition: Will return an int with the number of brackets within the string s.
char bracket(char letter);
//Precondition: letter is a char obtained by a portion of the string s such as s[i]
//Postcondition: will return 'f' if letter is a front bracket b if back bracket c if another kind of charecter.

int main(){
    string s;
    int inc = 0;
    cout << "Enter string to check for being well formed:\n";
    cin >> s;
    if(isEven(s) == false){
        cout << "Not well-formed\n"; //must be even in order to have all pairs therefore wellformed
        return 0;
    }
    if(wellFormed(s) == true){;
        cout << "Well-formed\n" << "The string has " << nestLevel(s) << " levels of nesting.\n";
    }
    else {
        cout << "Not well-formed\n"; 
    }
}

bool wellFormed(string s){ 
    static int count = 0;
    static int left = 0;
    static int right = 0;
    if (count == (lengthCheck(s)/2)){
        return true;
    }
    if(s[count + left] == '{' && s[(s.length() - 1) - count - right] == '}'){ 
        count++; //subtracted s.length() by one due to 0 indexing.
        wellFormed(s);
    }
    else if(s[count + left] == '[' && s[(s.length() - 1) - count - right] == ']'){
        count++;
        wellFormed(s);
    }
    else if(s[count + left] == '<' && s[(s.length() - 1) - count - right] == '>'){
        count++;
        wellFormed(s);
    }
    else if(s[count + left] == '(' && s[(s.length() - 1) - count - right] == ')'){
        count++;
        wellFormed(s);
    }
    else {
        if(bracket(s[count + left]) == 'c'){
            left++;
            wellFormed(s);
        }
        else if(bracket(s[s.length() - 1 - count - right]) == 'c'){
            right++;
            wellFormed(s);
        }
        else if(bracket(s[count + left]) == 'b' || bracket(s[s.length() - 1 - count - right]) == 'f'){
            return false;
        }
    }
}

bool isEven(string s){
    if(lengthCheck(s) % 2 == 0){
        return true;
    }
    else {
        return false;
    }
}

int nestLevel(string s){
    return lengthCheck(s) / 2;
}

int lengthCheck(string s){
    int val = 0; //stores the return value.
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '<' || s[i] == '>' || s[i] == '(' || s[i] == ')' || s[i] == '{' || s[i] == '}' || s[i] == '[' || s[i] == ']'){
        val++;
        }
    }
    return val;
}

char bracket(char letter){ //f is front bracket b is back bracket c is a another kind of char.
    if(letter == '{' || letter == '[' || letter == '(' || letter == '<'){
        return 'f';
    }
    else if (letter == '}' || letter == ']' || letter == ')' || letter == '>'){
        return 'b';
    }
    else {
        return 'c';
    }
}
