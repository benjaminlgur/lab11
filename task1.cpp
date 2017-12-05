#include <iostream>
#include <string>

using namespace std;

bool isEven(string s);
bool endCheck(string s, int count);

int main(){
    string s;
    cout << "Enter string to check for being well formed:\n";
    cin >> s;
    if(isEven(s) == false){
        cout << "Not well-formed\n"; //must be even in order to have all pairs therefore wellformed
        return 0;
    }
    for(int i = 0; i < (s.length()/2); i++){
        if(endCheck(s, i) == false){
            cout << "Not well-formed\n"; 
            return 0;
        }
    }
    cout << "Well-formed\n";
}

bool endCheck(string s, int count){ //subtracted length by one becuse of 0 indexing.
    if(s[count] == '{' && s[(s.length() - 1) - count] == '}'){ 
        return true;
    }
    else if(s[count] == '[' && s[(s.length() - 1) - count] == ']'){
        return true;
    }
    else if(s[count] == '<' && s[(s.length() - 1) - count] == '>'){
        return true;
    }
    else if(s[count] == '(' && s[(s.length() - 1) - count] == ')'){
        return true;
    }
    else {
        return false;
    }
}

bool isEven(string s){
    if(s.length() % 2 == 0){
        return true;
    }
    else {
        return false;
    }
}
