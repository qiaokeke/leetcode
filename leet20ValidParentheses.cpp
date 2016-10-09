/**
    leetcode
    20. Valid Parentheses
    https://leetcode.com/problems/valid-parentheses/
    Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
    The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
    Subscribe to see which companies asked this question

*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;


bool isVaild(string s){
    stack<char> charStack;

    int i = 0;

    while(i<s.length()){
        char c = s[i];
        if (c != ')' && c != '}' && c != ']'){
            charStack.push(c);
        }else{
            if(charStack.size()==0)
                return false;
            char pre = charStack.top();
            switch(c){
            case ')':
                if(pre=='(')
                    charStack.pop();
                else
                    return false;
                break;
            case ']':
                if(pre=='[')
                    charStack.pop();
                else
                    return false;
                break;
            case '}':
                if(pre=='{')
                    charStack.pop();
                else
                    return false;
                break;
            }
        }
        i++;
    }
    if(charStack.size()==0)
        return true;
    else
        return false;
}

int main(){
    bool b = isVaild("{}");
    cout<<b<<endl;
    return 0;
}
