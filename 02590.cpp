#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a1, a2, a3, a4, a5, a6;
	cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
	int boards = 0;
	while(a6 > 0){
		++boards;
		--a6;
	}
	while(a5 > 0){
		++boards;
		--a5;
		a1 -= min(a1, 11);
	}
	while(a4 > 0){
		++boards;
		--a4;
		if(a2 < 5){
			a1 -= min(a1, 20 - 4 * a2);
			a2 = 0;
		}else{
			a2 -= 5;
		}
	}
	while(a3 > 0){
		++boards;
		if(a3 == 1){
			a3 = 0;
			if(a2 < 5){
				a1 -= min(a1, 27 - 4 * a2);
				a2 = 0;
			}else{
				a2 -= 5;
				a1 -= min(a1, 7);
			}
		}else if(a3 == 2){
			a3 = 0;
			if(a2 < 3){
				a1 -= min(a1, 18 - 4 * a2);
				a2 = 0;
			}else{
				a2 -= 3;
				a1 -= min(a1, 6);
			}
		}else if(a3 == 3){
			a3 = 0;
			if(a2 > 0){
				--a2;
				a1 -= min(a1, 5);
			}else{
				a1 -= min(a1, 9);
			}
		}else{
			a3 -= 4;
		}
	}
	while(a2 > 0){
		++boards;
		if(a2 < 9){
			a1 -= min(a1, 36 - 4 * a2);
			a2 = 0;
		}else{
			a2 -= 9;
		}
	}
	boards += (a1 + 35) / 36;
	cout << boards << '\n';
	return 0;
}
