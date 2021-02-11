#include<iostream>
using namespace std;

int getcount(int coins[], int n, int sum){
	if(sum==0) 
		return 1;
	if(n==0)
		return 0;
	int res = getcount(coins,n-1,sum);
	if(coins[n-1]<=sum)
		res = res + getcount(coins,n,sum-coins[n-1]);
	return res;
}

int counttab(int coins[], int n, int sum){
	int dp[sum+1][n+1];
	for(int i=0;i<=sum;i++)
		dp[i][0]=1;
	for(int i=0;i<=n;i++)
		dp[0][i] = 0;
	for(int i=1;i<=sum;i++){
		for(int j=1;j<=n;j++){
			dp[i][j] = dp[i][j-1];
			if(coins[j-i]<=i)
				dp[i][j] = dp[i][j] + dp[i-coins[j-1]][i];
		}
	}
	return dp[sum][n];
}

int main(){
	int coins[] = {1,2,3};
	int sum = 4;
	cout<<"Recursive: "<<getcount(coins, 3, sum)<<endl;
	cout<<"Tabulation: "<<counttab(coins, 3, sum)<<endl;
}
