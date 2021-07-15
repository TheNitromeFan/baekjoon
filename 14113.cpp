#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	int bags = 0;
	while(a > 0){
		++bags;
		--a;
	}
	while(b > 0){
		++bags;
		--b;
		if(e > 0){
			--e;
		}
	}
	while(c > 0){
		++bags;
		--c;
		if(d > 0){
			--d;
		}else if(e > 1){
			--e;
			--e;
		}else if(e > 0){
			--e;
		}
	}
	while(d > 0){
		++bags;
		--d;
		if(d > 0){
			--d;
			if(e > 0){
				--e;
			}
		}else if(e > 2){
			--e;
			--e;
			--e;
		}else if(e > 1){
			--e;
			--e;
		}else if(e > 0){
			--e;
		}
	}
	bags += (e + 4) / 5;
	cout << bags << '\n';
	return 0;
}
