/**
leetcode 39
合并求和
如果数字相加等于目标值，记录下来
运用dfs算法，深度遍历，并且记得回溯


*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > results;
vector<int> result;

void dfs(vector<int>& candidaties,int target,int sum,int level){
        for(int k=0;k<result.size();k++){
            cout<<result[k]<<ends;
        }
        cout<<sum<<ends;
        cout<<endl;
    if(sum>target){
        return;
    }
    if(sum == target){
        for(int k=0;k<result.size();k++){
            cout<<result[k]<<ends;
        }
        cout<<"dd"<<endl;
        results.push_back(result);
        return;
    }
    for(int i=level;i<candidaties.size();i++){
        result.push_back(candidaties[i]);
        sum += candidaties[i];
        dfs(candidaties,target,sum,i);

        result.pop_back();
        sum-=candidaties[i];
    }
}

vector<vector<int> >combinationSum(vector<int>& candidaties,int target){
    sort(candidaties.begin(),candidaties.end());
    dfs(candidaties,target,0,0);
    return results;
}

int main(){
    int arr[] = {2,3,5,7};
    vector<int> can(arr,arr+4);
    combinationSum(can,7);
    cout<<results.size()<<endl;
    for(int i=0;i<results.size();i++){
        for(int j=0;j<results[i].size();j++){
            cout<<results[i][j]<<ends;
        }
        cout<<endl;

    }

    return 0;
}
