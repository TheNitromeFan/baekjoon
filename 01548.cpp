#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool triangle(vector<int> &c){
	for(unsigned i = 0; i < c.size(); ++i){
		for(unsigned j = 0; j < i; ++j){
			for(unsigned k = 0; k < j; ++k){
				if(c[k] + c[j] <= c[i]){
					return false;
				}
			}
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> b(n);
	for(int i = 0; i < n; ++i){
		cin >> b[i];
	}
	sort(b.begin(), b.end());
	for(int k = n; k >= 2; --k){
		vector<int> bitmask(k, 1);
		bitmask.resize(n, 0);
		do{
			vector<int> c;
			for(int i = 0; i < n; ++i){
				if(bitmask[i]){
					c.push_back(b[i]);
				}
			}
			if(triangle(c)){
				cout << k;
				return 0;
			}
		}while(prev_permutation(bitmask.begin(), bitmask.end()));
	}
	return 0;
}
