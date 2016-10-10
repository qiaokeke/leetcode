/**
leetcode38
38. Count and Say
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

操作字符串
一遍遍历，记录下第一个字符，后面判断是否相等，做出不同的对策

*/

#include <iostream>
#include <sstream>

using namespace std;

string convert(string& say){
    stringstream sStream;
    int count = 1 ;
    char last = say[0];

    for(int i=1;i<=say.length();i++){
        if(say[i]==last)
            count++;
        else{
            sStream<<count<<last;
            count=1;
            last = say[i];
        }
    }
    return sStream.str();
}


string countAndSay(int n){
    if(n<=0) return string();
    string say = "1";
    for(int i=1;i<n;i++){
        say=convert(say);
         cout<<say<<ends;
    }
    return say;
}


int main(){
    string r = countAndSay(3);
    cout<<r<<endl;
    return 0;
}
