#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long sum = 0, xsum = 0;
	int m;
	cin >> m;
	for(int a0 = 0; a0 < m; ++a0){
		int d;
		cin >> d;
		if(d == 1){
			int x;
			cin >> x;
			sum += x;
			xsum ^= x;
		}else if(d == 2){
			int x;
			cin >> x;
			sum -= x;
			xsum ^= x;
		}else if(d == 3){
			cout << sum << '\n';
		}else{
			cout << xsum << '\n';
		}
	}
	return 0;
}
