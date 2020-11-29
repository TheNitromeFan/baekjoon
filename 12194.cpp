#include <iostream>

using namespace std;

int clicks(bool digits[10], int x){
	// cout << x << "\n";
	if(x < 10 && digits[x]){
		return 1;
	}else if(x >= 10 && x < 100 && digits[x / 10] && digits[x % 10]){
		return 2;
	}else if(x == 100 && digits[0] && digits[1]){
		return 3;
	}
	int ret = -1;
	for(int p = 2; p < 10; ++p){
		if(digits[p] && x % p == 0){
			int c = clicks(digits, x / p);
			if(c != -1 && (ret == -1 || ret > c + 2)){
				ret = c + 2;
			}
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		bool digits[10];
		for(int i = 0; i < 10; ++i){
			cin >> digits[i];
		}
		int x;
		cin >> x;
		int ans = clicks(digits, x);
		if(ans != -1){
			cout << "Case #" << a0 << ": " << ans + 1 << "\n";
		}else{
			cout << "Case #" << a0 << ": Impossible\n";
		}
	}
	return 0;
}
