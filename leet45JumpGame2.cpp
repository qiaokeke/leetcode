/**

leetcode45 jump game 2
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.

Subscribe to see which companies asked this question

运用贪心算法，先计算出所有的能跳到的位置。

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int jump(vector<int>& nums){
    int N = nums.size();
    if(N<=1) return 0;

    for(int i=0;i<N;i++)
        nums[i]+=i;

    int jumpX = nums[0];
    int times =1;
    int curX =0;
    while(jumpX<N-1){
        int maxX = jumpX;
        times++;
        for(int i=curX+1;i<=maxX;i++)
            if(nums[i]>jumpX)
                jumpX = nums[i];
        curX = maxX;
    }

    return times;

}

int main(){


    return 0;
}
