#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	int x = 1;
	while(x + (x + 1) * ((1LL << (x + 1)) - 1) < n){
		++x;
	}
	cout << x;
	return 0;
}
