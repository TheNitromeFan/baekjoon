#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		int k, c, s;
		cin >> k >> c >> s;
		cout << "Case #" << a0 << ": ";
		if(c * s < k){
			cout << "IMPOSSIBLE\n";
			continue;
		}
		for(int i = 1; i <= k; i += c){
			long long p = 1;
			for(int j = 0; j < c; ++j){
				p = (p - 1) * k + min(i + j, k);
			}
			cout << p << " ";
		}
		cout << "\n";
	}
	return 0;
}
