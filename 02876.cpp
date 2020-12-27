#include <iostream>
#define MAX 100000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a[MAX][2];
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> a[i][0] >> a[i][1];
	}
	int dp[MAX][2] = {};
	dp[0][0] = 1;
	dp[0][1] = 1;
	for(int i = 1; i < n; ++i){
		if(a[i][0] == a[i - 1][0]){
			dp[i][0] = dp[i - 1][0] + 1;
		}else if(a[i][0] == a[i - 1][1]){
			dp[i][0] = dp[i - 1][1] + 1;
		}else{
			dp[i][0] = 1;
		}
		if(a[i][1] == a[i - 1][0]){
			dp[i][1] = dp[i - 1][0] + 1;
		}else if(a[i][1] == a[i - 1][1]){
			dp[i][1] = dp[i - 1][1] + 1;
		}else{
			dp[i][1] = 1;
		}
	}
	int max_length = 0, grade = 0;
	for(int i = 0; i < n; ++i){
		if(max_length < dp[i][0] || (max_length == dp[i][0] && grade > a[i][0])){
			max_length = dp[i][0];
			grade = a[i][0];
		}
		if(max_length < dp[i][1] || (max_length == dp[i][1] && grade > a[i][1])){
			max_length = dp[i][1];
			grade = a[i][1];
		}
	}
	cout << max_length << ' ' << grade;
	return 0;
}
