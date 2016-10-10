/*
leetcode36
valid SudoKu
验证数独的正确性
三遍遍历，遍历行，遍历列，遍历3*3格子

*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool check(char ch,bool used[9]){
    if(ch=='.') return true;
    if(used[ch-'1']) return false;

    used[ch-'1'] = true;
    return true;
}

bool isValidSudoKu(vector<vector<char> >& board){
    bool used[9];

    for(int i=0;i<9;i++){
        fill(used,used+9,false);
        for(int j=0;j<9;j++){
            if(!check(board[i][j],used))
                return false;
        }
        fill(used,used+9,false);
        for(int j=0;j<9;j++){
            if(!check(board[j][i],used))
                return false;
        }
        //放大缩小
        for(int r=0;r<3;r++){
            for(int c=0;c<3;c++){
                fill(used,used+9,false);
                for(int i=r*3;i<r*3+3;i++){
                    for(int j=c*3;j<c*3+3;j++){
                       if(!check(board[i][j],used))
                            return false;
                    }
                }
            }

        }
    }
    return true;

}

bool solve(vector<vector<char> >& board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'){
                for(int k=1;k<=9;k++){
                    board[i][j]=(char)(k+'0');
                    if(isValidSudoKu(board)&&solve(board))
                        return true;
                }
                board[i][j]='.';
                return false;
            }
        }
    }
    return true;

}

void solveSudoKu(vector<vector<char> >& board){
    solve(board);
}


int main(){




    return 0;
}
