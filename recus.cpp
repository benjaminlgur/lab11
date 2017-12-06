#include <iostream>
#include <string>

using namespace std;

bool isEven(string s);
bool endCheck(string s,int &ing);
int nestLevel(string s);
int lengthCheck(string s);
char bracket(char thing);

int main(){
    string s;
    int inc = 0;
    cout << "Enter string to check for being well formed:\n";
    cin >> s;
    if(isEven(s) == false){
        cout << "Not well-formed\n"; //must be even in order to have all pairs therefore wellformed
        return 0;
    }
    if(endCheck(s, inc) == true){;
        cout << "Well-formed\n" << "The string has " << nestLevel(s) << " levels of nesting.\n";
    }
    else {
        cout << "Not well-formed\n"; 
    }
}

bool endCheck(string s,int &ing){ //subtracted length by one becuse of 0 indexing.
    static int count = 0;
    static int left = 0;
    static int right = 0;
    if (count == (lengthCheck(s)/2)){
        return true;
    }
    if(s[count + left] == '{' && s[(s.length() - 1) - count - right] == '}'){ 
        count++;
        endCheck(s, count);
    }
    else if(s[count + left] == '[' && s[(s.length() - 1) - count - right] == ']'){
        count++;
        endCheck(s, count);
    }
    else if(s[count + left] == '<' && s[(s.length() - 1) - count - right] == '>'){
        count++;
        endCheck(s, count);
    }
    else if(s[count + left] == '(' && s[(s.length() - 1) - count - right] == ')'){
        count++;
        endCheck(s, count);
    }
    else {
        if(bracket(s[count + left]) == 'c'){
            left++;
            endCheck(s, count);
        }
        else if(bracket(s[s.length() - 1 - count - right]) == 'c'){
            right++;
            endCheck(s, count);
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

char bracket(char thing){ //f is front bracket b is back bracket c is a difrent kind of char.
    if(thing == '{' || thing == '[' || thing == '(' || thing == '<'){
        return 'f';
    }
    else if (thing == '}' || thing == ']' || thing == ')' || thing == '>'){
        return 'b';
    }
    else {
        return 'c';
    }
}
