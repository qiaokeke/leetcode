/*
leetcode42题，在一个坐标中填水

先找到中间最高点

一次从左右分别开始计算

*/

#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int trap(vector<int>& height){
    vector<int>::iterator maxIt,it;
    maxIt = max_element(height.begin(),height.end());

    int total = 0;
    int curVal = 0;
    for(it=height.begin();it!=maxIt;it++){
        if(*it>curVal)
            curVal = *it;
        else{
            total += (curVal-*it);
        }
       // cout<<total<<endl;
    }
    curVal = 0;
    for(it=height.end()-1;it!=maxIt;it--){
        if(*it>curVal)
            curVal = *it;
        else{
            total += (curVal-*it);
        }
        //cout<<total<<endl;
    }
    return total;
}


int main(){
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> hei(height,height+12);
    int area = trap(hei);
    cout<<area<<endl;
    return 0;
}
