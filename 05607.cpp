#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a = 0, b = 0;
	for(int i = 0; i < n; ++i){
		int left, right;
		cin >> left >> right;
		if(left > right){
			a += left + right;
		}else if(left < right){
			b += left + right;
		}else{
			a += left;
			b += right;
		}
	}
	cout << a << ' ' << b;
	return 0;
}
