#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long a = -2000000000000, b = -2000000000000, c = 2000000000000, d = 2000000000000;
	for(int i = 0; i < n; ++i){
		long long x, y;
		cin >> x >> y;
		if(y + x > a){
			a = y + x;
		}
		if(y + x < c){
			c = y + x;
		}
		if(y - x > b){
			b = y - x;
		}
		if(y - x < d){
			d = y - x;
		}
	}
	long long side = max(b - d, a - c);
	if(side % 2 == 0){
		cout << side * (side / 2);
	}else{
		cout << (side + 1) * ((side - 1) / 2) << ".5";
	}
	return 0;
}
