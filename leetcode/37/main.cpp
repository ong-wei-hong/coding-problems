#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		void solveSudoku(vector<vector<char>>& board) {
			r(board,0,0);
		}

		bool r(vector<vector<char>>& board,int i,int j) {
			if(i==9) return true;
			if(j==9) return r(board,i+1,0);
			if(board[i][j]!='.') return r(board,i,j+1);

			for(char ch='1';ch<='9';++ch) {
				bool valid=true;
				for(int k=0;k<9;++k) valid=valid&&(board[i][k]!=ch)&&(board[k][j]!=ch)&&(board[i/3*3+k/3][j/3*3+k%3]!=ch);
				if(valid) {
					board[i][j]=ch;
					if(r(board,i,j+1)) return true;
					board[i][j]='.';
				}
			}
			return false;
		}
	// time: O(1) (board size is fixed)
	//    or O(n ** 4) where n = board.size() (assumptions made like number of char to try = n, sub box size = n)
};
