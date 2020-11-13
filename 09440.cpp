#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		unsigned n;
		cin >> n;
		if(n == 0){
			break;
		}
		vector<int> v(n, 0);
		for(unsigned i = 0; i < n; ++i){
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		unsigned nonzero_idx = 0;
		while(v[nonzero_idx] == 0){
			++nonzero_idx;
		}
		int a = v[nonzero_idx], b = v[nonzero_idx + 1];
		bool flag = (n % 2 == 1);
		unsigned i = 0;
		while(i < n){
			if(i != nonzero_idx && i != nonzero_idx + 1){
				if(flag){
					a = a * 10 + v[i];
				}else{
					b = b * 10 + v[i];
				}
				flag = !flag;
			}
			++i;
		}
		cout << a + b << '\n';
	}
	return 0;
}
