class Solution {
public:
//T(C(N)=O(N)) and S(C(N)=O(N**2)) as it requires non contiguous memory allocation at each iteration 
int dp[101][201];//dynamic programmming(dp)2d array size declare
int stone(int i,int m,vector<int>&p){//stone funct declare
    if(i>=p.size())return 0;//Pile's vector size initialize
    if(dp[i][m]!=-1)return dp[i][m];//printing dp[i][m] to -1 determined
    int total=0;//Total initialize
    int out=INT_MIN;//output variable declare
    for(int j=0;j<2*m;j++){//iterating jth indx 
        if(i+j<p.size())total+=p[i+j];//total size incrment 
        out=max(out,total-stone(i+j+1,max(m,j+1),p));//maximum stone game output declare
    }
    //return out;
    return dp[i][m]=out;//printing output declare
}
    int stoneGameII(vector<int>&p) {//stone game function declare
        int sum=0;//initializn sum
        memset(dp,-1,sizeof(dp));//dp memset's size calculation
        for(auto a:p)sum+=a;//iterating sum at each stone on pile 
        int diff=stone(0,1,p);//difference calculation
        return (sum+=diff)/2;//printing pile's half incremtend sum       
    }
};
