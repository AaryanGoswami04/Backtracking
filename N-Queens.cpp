/*The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.*/
class Solution {
public:
//optimised approach
    void addSolution(vector<vector<string>>& ans,vector<vector<string>>& board,int n){
       vector<string> temp;
        for(int row=0; row<n; row++){
            string str;
            for(int col=0; col<n; col++)
                str += (board[row][col]);
             temp.push_back(str);
        }
        ans.push_back(temp);
    }

    void solve(int col,vector<vector<string>>& ans,vector<vector<string>>& board,int n,  unordered_map<int,bool>& Row, unordered_map<int,bool>&UpperDiag, unordered_map<int,bool>& LowerDiag){
        //base case
        if(col == n){
            cout<<"hello"<<endl;
            addSolution(ans, board, n);
            return;
        }

        for(int row=0; row<n; row++){
            if(Row[row]==0 && UpperDiag[n-1+col-row]==0 && LowerDiag[row+col]==0){  //placing queen is safe
                board[row][col] = "Q";
                Row[row]=1;
                UpperDiag[n-1+col-row]=1;
                LowerDiag[row+col]=1;
                solve(col+1, ans, board, n, Row, UpperDiag, LowerDiag);

                //backtrack
                board[row][col] = ".";
                Row[row]=0;
                UpperDiag[n-1+col-row]=0;
                LowerDiag[row+col]=0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board(n, vector<string>(n, "."));
        vector<vector<string>> ans;
        unordered_map<int,bool> Row, UpperDiag, LowerDiag;
        //Row: Stores if each row has a queen
        //UpperDiag: Stores if each upper diag has a queen
        //LowerDiag: Stores if each lower diag has a queen

        solve(0, ans, board, n, Row, UpperDiag, LowerDiag);
        return ans;
    }
};
