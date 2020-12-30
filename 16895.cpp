#include <iostream>
#include <vector>

using namespace std;

int vxor(vector<int> &v, int n){
	int ret = 0;
	for(int x : v){
		ret ^= x;
	}
	return ret;
}

int nim(vector<int> &v, int n){
	if(vxor(v, n) == 0){
		return 0;
	}
	int ret = 0;
	for(int i = 0; i < n; ++i){
		for(int x = 0; x < v[i]; ++x){
			vector<int> w = v;
			w[i] = x;
			if(vxor(w, n) == 0){
				++ret;
			}
		}
	}
	return ret;
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
	cout << nim(v, n);
	return 0;
}
