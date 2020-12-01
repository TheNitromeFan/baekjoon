#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, n;
	cin >> x >> n;
	if((n == 0 && x > 0) || (n == 1 && x < 0)){
		cout << "INFINITE";
	}else if(n == 0 || n == 1){
		cout << 0;
	}else if(n % 2 == 1){
		cout << "ERROR";
	}else{
		int ans = 0;
		for(int i = x - n / 2; i > 0; i -= n / 2){
			++ans;
		}
		cout << ans;
	}
	return 0;
}
