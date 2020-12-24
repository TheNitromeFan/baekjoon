#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int a, b, c, ab, bc, ca;
		cin >> a >> b >> c >> ab >> bc >> ca;
		int ans = 0;
		for(int i = 0; i < 1000; ++i){
			for(int j = 0; j < 1000; ++j){
				if(a >= i && b >= i + j && c >= j){
					ans = max(ans, i * ab + j * bc + min(a - i, c - j) * ca);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
