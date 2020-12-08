#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, h;
	cin >> n >> h;
	int ans = 0;
	--n;
	for(int i = 0; i < h; ++i){
		ans *= 2;
		if(n % 2 == 1){
			++ans;
		}
		n /= 2;
	}
	cout << ans;
	return 0;
}
