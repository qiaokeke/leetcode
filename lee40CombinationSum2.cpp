/**
leetcode 40 combination sum2
40. Combination Sum II

given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Subscribe to see which companies asked this question

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > results;
vector<int> result;

void dfs(vector<int> &candidates,int target,int sum,int level){
    if(sum>target){
        return;
    }
    if(sum==target){
        results.push_back(result);
        return;
    }
    for(int i=level;i<candidates.size();i++){

        result.push_back(candidates[i]);
        sum += candidates[i];

        dfs(candidates,target,sum,i+1);
        result.pop_back();
        sum -= candidates[i];

        //在一次做完之后进行去重
        while(i<candidates.size()-1&&candidates[i]==candidates[i+1]) i++;
    }
}


vector<vector<int> > combinationSum2(vector<int>& candidates,int target){
    sort(candidates.begin(),candidates.end());
    dfs(candidates,target,0,0);
    return results;
}

int main(){
int arr[] = {10,1,2,7,6,1,5};
    vector<int> can(arr,arr+7);
    combinationSum2(can,8);
    cout<<results.size()<<endl;
    for(int i=0;i<results.size();i++){
        for(int j=0;j<results[i].size();j++){
            cout<<results[i][j]<<ends;
        }
        cout<<endl;

    }
    return 0;
}
