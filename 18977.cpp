#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		long long n;
		cin >> n;
		if(n % 3 == 0){
			cout << (n / 3) * (n / 3) * (n / 3) << '\n';
		}else if(n % 4 == 0){
			cout << (n / 2) * (n / 4) * (n / 4) << '\n';
		}else{
			cout << -1 << '\n';
		}
	}
	return 0;
}
