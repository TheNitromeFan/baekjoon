#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	if(n % 2 != 0){
		long long m = (n + 1) / 2, k = (n - 1) / 2;
		cout << m << ' ' << k;
	}else if(n % 4 != 0){
		cout << "impossible";
	}else{
		long long m = n / 4 + 1, k = n / 4 - 1;
		cout << m << ' ' << k;
	}
	return 0;
}
