#include <iostream>
#include <vector>

using namespace std;

unsigned zigzag(vector<int> &v, unsigned n){
	unsigned ret = 1;
	unsigned idx = 1;
	while(idx < n && v[idx] == v[idx - 1]){
		++idx;
	}
	if(idx == n){
		return ret;
	}else if(v[idx] > v[idx - 1]){
		while(idx < n){
			++ret;
			while(idx < n && v[idx] >= v[idx - 1]){
				++idx;
			}
			if(idx == n){
				break;
			}
			++ret;
			while(idx < n && v[idx] <= v[idx - 1]){
				++idx;
			}
		}
	}else{
		while(idx < n){
			++ret;
			while(idx < n && v[idx] <= v[idx - 1]){
				++idx;
			}
			if(idx == n){
				break;
			}
			++ret;
			while(idx < n && v[idx] >= v[idx - 1]){
				++idx;
			}
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned n;
	cin >> n;
	vector<int> v(n);
	for(unsigned i = 0; i < n; ++i){
		cin >> v[i];
	}
	cout << zigzag(v, n) << '\n';
	return 0;
}
