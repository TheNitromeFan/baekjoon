#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	if(n == 0){
		cout << "Yes\n1 1";
	}else if(n == 1){
		cout << "No";
	}else if(n == 4){
		cout << "No";
	}else if(n % 4 == 0){
		long long x = (n / 2 + 2) / 2, y = (n / 2 - 2) / 2;
		cout << "Yes\n" << x << ' ' << y;
	}else if(n % 2 == 0){
		cout << "No";
	}else{
		long long x = (n + 1) / 2, y = (n - 1) / 2;
		cout << "Yes\n" << x << ' ' << y;
	}
	return 0;
}
