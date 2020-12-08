#include <iostream>
#include <vector>

using namespace std;

int max_afford(vector<int> &sticker, vector<int> &t){
	int ret = 1000000;
	for(int type : sticker){
		if(ret > t[type]){
			ret = t[type];
		}
	}
	return ret;
}

int cash(vector<vector<int>> &stickers, vector<int> &prize, vector<int> &t, int n){
	int ret = 0;
	for(int pos = 0; pos < n; ++pos){
		int prizes_num = max_afford(stickers[pos], t);
		ret += prizes_num * prize[pos];
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> stickers(n);
		vector<int> prize(n);
		for(int i = 0; i < n; ++i){
			int k;
			cin >> k;
			stickers[i].resize(k);
			for(int j = 0; j < k; ++j){
				cin >> stickers[i][j];
			}
			cin >> prize[i];
		}
		vector<int> t(m + 1);
		for(int l = 1; l <= m; ++l){
			cin >> t[l];
		}
		cout << cash(stickers, prize, t, n) << '\n';
	}
	return 0;
}
