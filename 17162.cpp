#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int pops(vector<stack<int, vector<int>>> &r, stack<int, vector<int>> &a, int mod){
	int ans = 1000000;
	for(int i = 0; i < mod; ++i){
		if(r[i].empty()){
			return -1;
		}
		ans = min(ans, r[i].top());
	}
	return (int)a.size() - ans + 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, mod;
	cin >> n >> mod;
	stack<int, vector<int>> a;
	vector<stack<int, vector<int>>> r(mod);
	for(int i = 0; i < n; ++i){
		int query;
		cin >> query;
		if(query == 1){
			int num;
			cin >> num;
			a.push(num);
			r[num % mod].push((int)a.size());
		}else if(query == 2){
			if(a.empty()){
				continue;
			}
			int num = a.top();
			a.pop();
			r[num % mod].pop();
		}else{
			cout << pops(r, a, mod) << '\n';
		}
	}
	return 0;
}
