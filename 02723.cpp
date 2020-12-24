#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long ans[12] = {0, 1, 5, 25, 149, 1081, 9365, 94585, 1091669, 14174521, 204495125, 3245265145};
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int b;
		cin >> b;
		cout << ans[b] << '\n';
	}
	return 0;
}
