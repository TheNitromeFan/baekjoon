#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		v[i] = i + 1;
	}
	for(int i = 0; i < n; ++i){
		int j = 0;
		while(j * (j + 1) / 2 < k){
			++j;
		}
		k -= j;
		cout << v[j] << ' ';
		v.erase(v.begin() + j);
	}
	return 0;
}
