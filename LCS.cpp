#include<iostream>
#include<vector>

using namespace std;

int LCS(int i1, int i2, const vector<int> &v1, const vector<int> &v2 ,vector<vector<int>> &dp){
    if(i1== v1.size() || i2 == v2.size())
        return 0;
    if(dp[i1][i2] != -1)
        return dp[i1][i2];
    if(v1[i1] == v2[i2]){
        dp[i1][i2] =  1+LCS(i1+1,i2+1,v1,v2, dp);
        return dp[i1][i2];
    }
    dp[i1][i2] =  max(LCS(i1+1,i2,v1,v2,dp), LCS(i1,i2+1,v1,v2,dp));
    return dp[i1][i2];
}
int findLCS(const vector<int> &v1, const vector<int> &v2){
    vector<vector<int> > dp(v1.size(), vector<int>(v2.size(),0));
    return LCS(0,0,v1,v2,dp);
}
int main(){
    vector<int> v1 = {1 ,2 ,4 ,5,6,7,8};
    vector<int> v2 = {2, 5,7 ,2};
    cout << findLCS(v1,v2) << endl;
}

