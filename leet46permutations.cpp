/**
leetcode 46. Permutations
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
Subscribe to see which companies asked this question


用dfs方法，深度遍历，用数组记录是否已遍历过，未遍历过继续遍历
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > results;
vector<int> result;
bool used[100];

void solve(vector<int>& nums){
    int N = nums.size();
    if(result.size() == N){
        results.push_back(result);
        for(int i=0;i<result.size();i++)
            cout<<result[i]<<ends;
        cout<<endl;
        return ;
    }

    for(int i=0;i<N;i++){

        if(used[i])
            continue;
        result.push_back(nums[i]);
        used[i] = true;
        solve(nums);
        result.pop_back();
        used[i] = false;
        //cout<<i<<used[i]<<endl;
    }
}

vector<vector<int> > permute(vector<int>& nums){
    solve(nums);
    return results;
}


int main(){
    int aa[] = {1,2,3};
    vector<int> nums(aa,aa+3);
   // nums.push_back(aa,aa+3);
    permute(nums);
    return 0;
}
