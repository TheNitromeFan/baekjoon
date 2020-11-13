#include <iostream>
#include <queue>

using namespace std;

int main(){
	int x, k;
	cin >> x >> k;
	queue<int> zeroes;
	for(int i = 0; i < 64; ++i){
		if(x % 2 == 0){
			zeroes.push(i);
		}
		x /= 2;
	}
	long long y = 0;
	while(k > 0){
		if(k % 2 == 1){
			y += (1LL << zeroes.front());
		}
		k /= 2;
		zeroes.pop();
	}
	cout << y;
	return 0;
}
