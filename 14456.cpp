#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[3] = {};
	for(int i = 0; i < n; ++i){
		int x, y;
		cin >> x >> y;
 		++a[(x + 3 - y) % 3];
	}
	/*
	for(int i = 0; i < 3; ++i){
		cout << a[i] << '\n';
	}
	*/
	cout << max(a[1], a[2]);
	return 0;
}
