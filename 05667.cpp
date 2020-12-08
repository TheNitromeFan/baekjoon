#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	while(cin >> n){
		vector<int> v(n);
		int one = -1;
		for(int i = 0; i < n; ++i){
			cin >> v[i];
			if(v[i]){
				one = i;
			}
		}
		if(one == -1){
			cout << (n + 1) / 2 << '\n';
			continue;
		}
		vector<int> v1(n);
		for(int i = 0; i < n; ++i){
			v1[i] = v[(i + one) % n];
		}
		int ans = 0;
		int cur = 0;
		for(int i = 0; i < n; ++i){
			if(v1[i]){
				ans += cur / 2;
				cur = 0;
			}else{
				++cur;
			}
		}
		ans += cur / 2;
		cout << ans << '\n';
	}
	return 0;
}
