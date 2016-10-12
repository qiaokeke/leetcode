#include<iostream>

using namespace std;


bool isMatch(string s,string p){
    int M = s.length(),N = p.length();

    int m=0,n=0;
    int m1=-1,n1=-1;
    while(m<M){
        if(n<N&&(p[n]=='?'||s[m]==p[n])){
            m++;n++;
            continue;
        }
        if(n<N&&p[n]=='*'){
            n1 = n;
            n++;
            m1 = m;
            continue;
        }
        if(n1!=-1){
            n = n1+1;
            m = m1+1;
            m1++;
            continue;
        }
        return false;

    }
   while(p[n]=='*') n++;
   return n==N;
}


/*

bool isMatch(string s,string p){
   if(p.length()<=0) return s.length()<=0;
   if(s.length()<=0) return false;

    if(p[0]=='?'||s[0]==p[0]){
        return isMatch(s.substr(1),p.substr(1));

    }
    if(p[0]=='*'){
        int i = 1;
        while(p[i]=='*') i++;
        int j =0;
        while(j<s.length()){
            if(isMatch(s.substr(j),p.substr(i))) return true;
            j++;
        }
        return isMatch(s.substr(j),p.substr(i));
    }
    return false;

}

*/
int main(){
string s = "aa",p="*";
bool b = isMatch(s,p);
cout<<b<<endl;

return 0;
}
