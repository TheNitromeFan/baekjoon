#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int days;
	cin >> days;
	long long money = 100;
	int prev = (1 << 30);
	for(int i = 0; i < days; ++i){
		int cur;
		cin >> cur;
		if(cur > prev){
			money += min(money / prev, 100000LL) * (cur - prev);
		}
		prev = cur;
	}
	cout << money;
	return 0;
}
