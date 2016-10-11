/**
leetcode 43Multiply Strings

Given two numbers represented as strings, return multiplication of the numbers as a string.

Note:
The numbers can be arbitrarily large and are non-negative.
Converting the input string to integer is NOT allowed.
You should NOT use internal library such as BigInteger.
Subscribe to see which companies asked this question

两个大字符串相乘，返回字符串结果
首先每一位相乘，放到指定位置，并加起来。
然后处理进位问题。
*/

#include<iostream>
#include<vector>

using namespace std;

string multiply(string num1,string num2){
    int M = num1.length(),N=num2.length();
    int K = M+N;

    vector<int> tmp(K,0);

    for(int m=0;m<M;m++){
        for(int n=0;n<N;n++){
            tmp[K-2-m-n] += (num1[m]-'0')*(num2[n]-'0');
        }
    }

    int c=0;//进位
    for(int i=0;i<K;i++){
        tmp[i] += c;
        c = tmp[i]/10;
        tmp[i] %= 10;
    }
    int i = K-1;
    while(tmp[i] == 0) i--;
    if(i<0) return "0";
    string res;
    for(;i>=0;i--){
        res.push_back(tmp[i]+'0');
    }
    return res;

}

int main(){
    string res = multiply("11","12");
    cout<<res<<endl;
    return 0;
}
