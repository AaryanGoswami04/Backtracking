//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
class Solution {
public:
//left: stores how many '(' are remeaining 
//right: stores how many ')' are remaining
  
    void addParens(vector<string>& res,string& parens,int left, int right){
        if(left>right || left==0) //If ) get exhausted before ( does then return
            return;
        if(left == 0 && right == 0){  //base case: If no ')' and '(' are remaining then store in ans and return 
            res.push_back(parens);
            return;
        }
        parens.push_back('(');
        addParens(res, parens, left-1, right);
        parens.pop_back();  //backtrack

        parens.push_back(')');
        addParens(res, parens, left, right-1);
        parens.pop_back();
    }  
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string parens;
        addParens(res, parens, n, n);
        return res;
    }
};
