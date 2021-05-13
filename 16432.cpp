#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<int> &ans, bool a[][10], bool checked[][10], int n, int cur){
	if(cur > n){
		return true;
	}
	for(int x = 1; x <= 9; ++x){
		if(x != ans.back() && a[cur][x] && !checked[cur][x]){
			ans.push_back(x);
			if(dfs(ans, a, checked, n, cur + 1)){
				return true;
			}
			ans.pop_back();
			checked[cur][x] = true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	bool a[1001][10] = {};
	for(int i = 1; i <= n; ++i){
		int mi;
		cin >> mi;
		for(int j = 0; j < mi; ++j){
			int x;
			cin >> x;
			a[i][x] = true;
		}
	}
	vector<int> ans = {0};
	bool checked[1001][10] = {};
	if(dfs(ans, a, checked, n, 1)){
		for(int i = 1; i <= n; ++i){
			cout << ans[i] << '\n';
		}
	}else{
		cout << -1 << '\n';
	}
	return 0;
}
