#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long a[65] = {};
	int h;
	cin >> h;
	a[1] = 1;
	a[2] = 1;
	for(int i = 3; i <= h + 1; ++i){
		a[i] = a[i - 2] + (1LL << (i - 2));
	}
	cout << a[h + 1];
	return 0;
}
