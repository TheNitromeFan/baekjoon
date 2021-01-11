#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	long long ans = 0;
	if(n % 6 == 0){
		ans = n * n / 2 - 5 * n / 3;
	}else if(n % 6 == 3){
		ans = (n * n * 3 - 7 * n) / 6;
	}else if(n % 6 == 1 || n % 6 == 5){
		ans = (n * n - n) / 2;
	}else{
		ans = n * n / 2 - n;
	}
	cout << ans;
	return 0;
}
