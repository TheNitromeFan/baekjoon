#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	char ans[4] = "PSR";
	while(true){
		long long n;
		cin >> n;
		if(n == 0){
			break;
		}
		--n;
		int ternary_check = 0;
		while(n > 0){
			ternary_check += n % 3;
			n /= 3;
			ternary_check %= 3;
		}
		cout << ans[ternary_check] << '\n';
	}
	return 0;
}
