#include <iostream>
#define MAX 200003

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	int a[MAX]; // a[i]: xor of i-th and i + 1-th
	for(int i = 1; i < n; ++i){
		cin >> a[i];
	}
	int pxor[MAX] = {}; // pxor[i]: xor of 1st to i-th
	pxor[2] = a[1];
	for(int i = 3; i <= n; ++i){
		pxor[i] = pxor[i - 1] ^ a[i - 1];
	}
	for(int a0 = 0; a0 < q; ++a0){
		int c;
		cin >> c;
		if(c){
			int x, y, d;
			cin >> x >> y >> d;
			cout << (pxor[y] ^ pxor[x] ^ d) << '\n';
		}else{
			int x, y;
			cin >> x >> y;
			cout << (pxor[y] ^ pxor[x]) << '\n';
		}
	}
	return 0;
}
