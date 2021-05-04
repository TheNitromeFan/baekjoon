#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, s;
	cin >> x >> s;
	int hops = 0;
	while(x > 0 && s > 1){
		++hops;
		x -= s;
		s /= 2;
	}
	if(x > 0){
		hops += x;
	}
	cout << hops;
	return 0;
}
