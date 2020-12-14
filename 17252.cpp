#include <iostream>

using namespace std;

bool three(long long n){
	if(n == 0){
		return false;
	}
	while(n > 0){
		if(n % 3 == 2){
			return false;
		}
		n /= 3;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	cout << (three(n) ? "YES" : "NO");
	return 0;
}
