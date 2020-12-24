#include <iostream>
#include <vector>

using namespace std;

bool prime(int n){
	for(int p = 2; p * p <= n; ++p){
		if(n % p == 0){
			return false;
		}
	}
	return true;
}

void shortest_primed_subsequence(vector<int> &v, vector<int> &psum, unsigned n){
	for(unsigned len = 2; len <= n; ++len){
		for(unsigned i = 0; i + len <= n; ++i){
			if(prime(psum[i + len] - psum[i])){
				cout << "Shortest primed subsequence is length " << len << ":";
				for(unsigned j = i + 1; j <= i + len; ++j){
					cout << " " << v[j];
				}
				cout << "\n";
				return;
			}
		}
	}
	cout << "This sequence is anti-primed.\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		unsigned n;
		cin >> n;
		vector<int> v(n + 1), psum(n + 1);
		for(unsigned i = 1; i <= n; ++i){
			cin >> v[i];
			psum[i] = psum[i - 1] + v[i];
		}
		shortest_primed_subsequence(v, psum, n);
	}
	return 0;
}
