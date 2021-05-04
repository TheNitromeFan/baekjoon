#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q, n, a, b, c;
	cin >> q >> n >> a >> b >> c;
	if(q == 1){
		if(max(0, a + b - n) + c < n || max(0, b + c - n) + a < n || max(0, c + a - n) + b < n){
			cout << 0;
		}else{
			cout << a + b + c - 2 * n;
		}
	}else{
		cout << min(min(a, b), c);
	}
	return 0;
}
