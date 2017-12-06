/*
  Author: <Benjamin Gur>
  Course: {136}
  Instructor: <Pajula>
  Assignment: <lab 11> 

  This program finds wether a string including brackets is wellformed according to the parmeters of lab 11.
*/

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
    cout << "Enter string to check for being well formed:\n";
    getline(cin, s); //using getline in order to see white space.
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

//This function works by scaning the string from both the left and the right meeting in the middle of the brakets. All brackets from the left should be front brackets and all brackets from the right should be back brackets.
bool wellFormed(string s){ 
    static int count = 0; //These 3 static ints are used to move through the string.
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

/* Test cases

An empty string returns wellformed.
A sting of only non bracket charecters returns well formed. 
Inputing {[{}]} is well-formed. The string has 3 levels of nesting.
Inputing <[()]> is well-formed. The string has 3 levels of nesting.
Inputing <<(<()>)>> is well-formed. The string has 5 levels of nesting.
Inputing {(){ is well-formed. The string has 2 levels of nesting.
Inputing <[()]()> is well-formed. The string has 4 levels of nesting.
Inputing {(}) is well-formed. The string has 2 levels of nesting.
Inputing <asd{dsa}dsa> is well-formed. The string has 2 levels of nesting.
Inputing y=(mx+b) is well-formed. The string has 1 levels of nesting.
Inputing (b^2)={ac} is well-formed. The string has 2 levels of nesting.
Inputing <><><><><><><><> is well-formed. The string has 8 levels of nesting.
Inputing apple as<<< dsaasdas >>> dadad is well-formed. The string has 3 levels of nesting.
Inputing (<>)() is well-formed. The string has 3 levels of nesting.
Inputing <(<{}?)> is not well-formed
*/
