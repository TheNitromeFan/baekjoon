#include <iostream>

using namespace std;

int legendre(int n, int a){
	int ret = 0;
	while(n >= a){
		ret += n / a;
		n /= a;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a;
	cin >> n >> a;
	cout << legendre(n, a);
	return 0;
}
