#include <iostream>

using namespace std;

bool even_permutation(int a[4], int b[4]){
	return (a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3])
	|| (a[0] == b[0] && a[1] == b[2] && a[2] == b[3] && a[3] == b[1])
	|| (a[0] == b[0] && a[1] == b[3] && a[2] == b[1] && a[3] == b[2])
	|| (a[0] == b[1] && a[1] == b[0] && a[2] == b[3] && a[3] == b[2])
	|| (a[0] == b[1] && a[1] == b[3] && a[2] == b[2] && a[3] == b[0])
	|| (a[0] == b[1] && a[1] == b[2] && a[2] == b[0] && a[3] == b[3])
	|| (a[0] == b[2] && a[1] == b[1] && a[2] == b[3] && a[3] == b[0])
	|| (a[0] == b[2] && a[1] == b[0] && a[2] == b[1] && a[3] == b[3])
	|| (a[0] == b[2] && a[1] == b[3] && a[2] == b[0] && a[3] == b[1])
	|| (a[0] == b[3] && a[1] == b[2] && a[2] == b[1] && a[3] == b[0])
	|| (a[0] == b[3] && a[1] == b[0] && a[2] == b[2] && a[3] == b[1])
	|| (a[0] == b[3] && a[1] == b[1] && a[2] == b[0] && a[3] == b[2]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k;
	for(int a0 = 0; a0 < k; ++a0){
		int a[4], b[4];
		for(int i = 0; i < 4; ++i){
			cin >> a[i];
		}
		for(int i = 0; i < 4; ++i){
			cin >> b[i];
		}
		cout << even_permutation(a, b) << '\n';
	}
	return 0;
}
