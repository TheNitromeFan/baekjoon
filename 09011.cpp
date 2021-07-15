#include <iostream>
#include <vector>

using namespace std;

bool recover(vector<int> &r, vector<int> &c, vector<int> &s, int n){
	for(int i = n - 1; i >= 0; --i){
		if(r[i] >= (int)c.size()){
			return false;
		}
		s[i] = c[r[i]];
		c.erase(c.begin() + (unsigned)r[i]);
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		vector<int> r(n);
		for(int i = 0; i < n; ++i){
			cin >> r[i];
		}
		vector<int> c(n);
		for(int i = 0; i < n; ++i){
			c[i] = i + 1;
		}
		vector<int> s(n);
		if(recover(r, c, s, n)){
			for(int x : s){
				cout << x << ' ';
			}
			cout << '\n';
		}else{
			cout << "IMPOSSIBLE\n";
		}
	}
	return 0;
}
