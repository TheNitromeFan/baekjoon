#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void coordinates(int n, int &h, int &w){
	int x = (int)sqrt(n) + 2;
	while(x * x >= n){
		--x;
	}
	h = x + 1;
	w = n - x * x;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	if(a > b){
		swap(a, b);
	}
	int ha = -1, wa = -1, hb = -1, wb = -1;
	coordinates(a, ha, wa);
	coordinates(b, hb, wb);
	int cnt = 0;
	while(ha < hb){
		if(wa % 2 == 0){
			if(wa < wb){
				++wa;
				++cnt;
			}else{
				--wa;
				++cnt;
			}
		}else{
			++ha;
			++wa;
			++cnt;
		}
	}
	cnt += max(wa - wb, wb - wa);
	cout << cnt;
	return 0;
}
