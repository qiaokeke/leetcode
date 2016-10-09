/*
leetcode
32. Longest Valid Parentheses
借助辅助数组，表示当前是否匹配
最后遍历数组，求出结果

*/

#include <iostream>
#include <stack>

using namespace std;

int longestValidParentheses(string s) {
    int N = s.length();

    int lenArr[N];
    int maxlen=0;
    stack<char> charStack;

    int i=0;
    while(i<s.length()){
        char c = s[i];
        if(c=='('){
            charStack.push(c);
            lenArr[i]=0;
        }else{
            if(charStack.size()>0){
                charStack.pop();
                for(int j=i-1;j>=0;j--){
                    if(lenArr[j]!=1){
                        lenArr[j]=1;
                        break;
                    }
                }
                lenArr[i]=1;

            }else{
                lenArr[i]=0;
            }
        }
        i++;
    }
    int curlen=0;
    for(int k=0;k<N;k++){
        cout<<lenArr[k]<<ends;
        if(lenArr[k]==1){
            curlen++;
        }else{
            if(curlen>maxlen)
                maxlen =curlen;
            curlen=0;
        }
    }

    if(curlen>maxlen)
        maxlen =curlen;



    return maxlen;
}

int main(){

    string s = "))(()";

    int i = longestValidParentheses(s);

    cout<<endl<<i<<endl;


    return 0;
}
