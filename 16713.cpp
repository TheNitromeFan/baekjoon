#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<int> pxor(n + 1);
	for(int i = 1; i <= n; ++i){
		int ai;
		cin >> ai;
		pxor[i] = pxor[i - 1] ^ ai;
	}
	int ans = 0;
	for(int j = 0; j < q; ++j){
		int si, ei;
		cin >> si >> ei;
		ans ^= pxor[ei] ^ pxor[si - 1];
	}
	cout << ans;
	return 0;
}
