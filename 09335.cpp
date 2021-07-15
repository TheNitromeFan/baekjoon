#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int minimum_ads(vector<vector<int>> &adj, int n){
	for(int len = 1; len <= n; ++len){
		vector<int> bitmask(len, 1);
		bitmask.resize(n);
		do{
			vector<int> ads;
			for(int i = 0; i < n; ++i){
				if(bitmask[i]){
					ads.push_back(i);
				}
			}
			vector<bool> sees_ad(n);
			for(int ad : ads){
				sees_ad[ad] = true;
				for(int v : adj[ad]){
					sees_ad[v] = true;
				}
			}
			if(sees_ad == vector<bool>(n, true)){
				return len;
			}
		}while(prev_permutation(bitmask.begin(), bitmask.end()));
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		vector<vector<int>> adj(n);
		for(int u = 0; u < n; ++u){
			int d;
			cin >> d;
			for(int i = 0; i < d; ++i){
				int v;
				cin >> v;
				adj[u].push_back(v - 1);
			}
		}
		cout << minimum_ads(adj, n) << '\n';
	}
	return 0;
}
