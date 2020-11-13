#include <iostream>

using namespace std;

int main(){
	int mod = 10007;
	int n;
	cin >> n;
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	int previous = 1, current = 2;
	for(int i = 2; i < n; ++i){
		int temp = current;
		current = (current + previous) % mod;
		previous = temp;
	}
	cout << current << endl;
	return 0;
}
