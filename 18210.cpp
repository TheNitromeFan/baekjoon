#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long t;
	cin >> t;
	if(t == 0){
		cout << 0;
		return 0;
	}
	t += 1;
	long long ans = 0;
	while(true){
		t -= 2;
		ans += 2;
		long long q = t / 3, r = t % 3;
		ans += r;
		if(q <= 1){
			ans += q;
			break;
		}
		t = q;
	}
	cout << ans - 1;
	return 0;
}
