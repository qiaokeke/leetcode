/*
¡¾leetcode31Ìâ¡¿ ¡¾Next Permutation¡¿
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 ¡ú 1,3,2
3,2,1 ¡ú 1,2,3
1,1,5 ¡ú 1,5,1
Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>

using namespace std;

void nextPermutation(vector<int>& nums) {
    int N = nums.size();
    if(N<=1)
        return;
    for(int i=N-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            for(int j=N-1;j>i;j--){
                if(nums[i]<nums[j]){
                    int t = nums[i];
                    nums[i]=nums[j];
                    nums[j]=t;

                    int k=i+1;
                    int l=N-1;
                    while(k<l){
                        int t2 = nums[k];
                        nums[k] = nums[l];
                        nums[l] = t2;
                        k++;
                        l--;
                    }
                    return;
                }
            }
        }
    }

    int m=0,n=N;
    while(m<n){
        int t3 = nums[m];
        nums[m] = nums[n];
        nums[n] = t3;
        m++;
        n--;
    }

}


int main(){
    cout<<"dd";
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(3);
    nums.push_back(2);
    nextPermutation(nums);


    for(int i=0;i<nums.size();i++){

        cout<<nums[i]<<ends;
    }
    return 0;
}

