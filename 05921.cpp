#include <iostream>
#include <vector>

using namespace std;

bool no_carry(vector<int> &v){
	for(int i = 0; i < 9; ++i){
		int sum = 0;
		for(int &x : v){
			sum += x % 10;
			x /= 10;
		}
		if(sum >= 10){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	unsigned ans = 0;
	for(int a0 = 0; a0 < (1 << n); ++a0){
		vector<int> w;
		int m = a0;
		for(int j = 0; j < n; ++j){
			if(m % 2 == 1){
				w.push_back(v[j]);
			}
			m /= 2;
		}
		if(no_carry(w) && ans < w.size()){
			ans = w.size();
		}
	}
	cout << ans;
	return 0;
}
