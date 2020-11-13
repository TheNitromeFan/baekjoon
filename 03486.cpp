#include <iostream>

using namespace std;

int reversed(int n){
	int ret = 0;
	while(n > 0){
		ret = ret * 10 + (n % 10);
		n /= 10;
	}
	return ret;
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int a, b;
		cin >> a >> b;
		cout << reversed(reversed(a) + reversed(b)) << '\n';
	}
	return 0;
}
