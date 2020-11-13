#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int src[10001], dest[10001];

int dp[10001][10];

int rotations(int n, int cur, int pivot){
	int new_src = (src[cur] + pivot) % 10;
	int pivot_left, pivot_right;
	if(dest[cur] > new_src){
		pivot_left = dest[cur] - new_src;
	}else{
		pivot_left = (dest[cur] - new_src + 10) % 10;
	}
	if(new_src > dest[cur]){
		pivot_right = new_src - dest[cur];
	}else{
		pivot_right = (new_src - dest[cur] + 10) % 10;
	}
	if(n == cur-1){
		return min(pivot_left, pivot_right);
	}
	int &ans = dp[cur][pivot];
	if(ans != -1){
		return ans;
	}
	ans = min(rotations(n, cur + 1, (pivot + pivot_left) % 10) + pivot_left,
				rotations(n, cur + 1, pivot) + pivot_right);
	return ans;
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 10; ++j){
			dp[i][j] = -1;
		}
	}
	string s, d;
	cin >> s >> d;
	for(int i = 0; i < n; ++i){
		src[i] = s[i] - '0';
		dest[i] = d[i] - '0';
	}
	cout << rotations(n, 0, 0);
	return 0;
}
