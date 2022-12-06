
#include <iostream>
using namespace std;
#include<vector>

bool isSafe(int newx, int newy, vector<vector<int>> arr, vector<vector<bool>>& vis, int n ){
  if((newx>=0 && newx<n) && (newy>=0 && newy<n) && (vis[newx][newy]==0) && (arr[newx][newy]==1))
    return true;
  else
    return false;
}
void solve(int x, int y, vector<vector<int>>&arr, vector<vector<bool>>& vis, vector<string> &ans, string path, int n, int dx[], int dy[]){
  //base case
  if(x==n-1 && y==n-1){
    ans.push_back(path);
    return;
  }
  string str="DLRU";
  for(int i=0; i<4; i++){
    int newx = x+dx[i];
    int newy = y+dy[i];
    if(isSafe(newx,newy,arr,vis,n)){
      vis[x][y]=1;
      solve(newx, newy, arr, vis, ans, path+str[i], n,dx,dy);
      vis[x][y]=0;
      }
  }
}
int main() {
    vector<vector<int>> arr{{1,1,0},
                           {1,1,0},
                           {0,1,1}};
    int n=3;
    vector<vector<bool>> vis (n, vector<bool>(n,0));
    vector<string>ans;
    string path="";
  
    int dx[]={1,0,0,-1};
    int dy[]={0,-1,1,0};
  
    if(arr[0][0]==1)
      solve(0, 0, arr, vis, ans, path, n, dx, dy);
   }
