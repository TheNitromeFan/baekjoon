#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

bool hamming(string &s1, string &s2, int k){
	int cnt = 0;
	for(int i = 0; i < k; ++i){
		if(s1[i] != s2[i]){
			++cnt;
			if(cnt > 1){
				return false;
			}
		}
	}
	return cnt == 1;
}

bool find_path(vector<string> &binary, vector<int> &prev, int n, int k, int start, int end){
	queue<int> q;
	q.push(start);
	prev[start] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(x == end){
			return true;
		}
		for(int j = 1; j <= n; ++j){
			if(prev[j] == -1 && hamming(binary[x], binary[j], k)){
				q.push(j);
				prev[j] = x;
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<string> binary(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> binary[i];
	}
	int a, b;
	cin >> a >> b;
	vector<int> prev(n + 1, -1);
	bool path = find_path(binary, prev, n, k, a, b);
	if(path){
		vector<int> ans = {b};
		while(ans.back() != a){
			ans.push_back(prev[ans.back()]);
		}
		reverse(ans.begin(), ans.end());
		for(int x : ans){
			cout << x << ' ';
		}
	}else{
		cout << -1;
	}
	return 0;
}
