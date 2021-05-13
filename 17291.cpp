#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a[21] = {}; // a[year]
	a[0] = 1;
	a[1] = 1;
	for(int i = 2; i <= 20; ++i){
		a[i] = a[i - 1] * 2;
		if(i >= 4 && i % 2 == 0){
			a[i] -= a[i - 4];
		}
		if(i >= 5 && i % 2 == 0){
			a[i] -= a[i - 5];
		}
	}
	int n;
	cin >> n;
	cout << a[n];
	return 0;
}
