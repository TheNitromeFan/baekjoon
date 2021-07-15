#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool potato_sack(vector<int> &v, int c){
	for(int x = 0; x < (1 << 10); ++x){
		int sum = 0;
		for(int i = 0; i < 10; ++i){
			if(x & (1 << i)){
				sum += v[i];
			}
		}
		if(sum == c){
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int k, c;
		cin >> k >> c;
		vector<int> v(10);
		for(int i = 0; i < 10; ++i){
			cin >> v[i];
		}
		cout << k << ' ' << (potato_sack(v, c) ? "YES" : "NO") << '\n';
	}
	return 0;
}
