#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a1, a2, a3, a4;
	cin >> a1 >> a2 >> a3 >> a4;
	int groups = 0;
	while(a4 > 0){
		++groups;
		--a4;
	}
	while(a3 > 0){
		++groups;
		--a3;
		if(a1 > 0){
			--a1;
		}
	}
	while(a2 > 0){
		++groups;
		--a2;
		if(a2 > 0){
			--a2;
		}else if(a1 > 1){
			--a1;
			--a1;
		}else if(a1 > 0){
			--a1;
		}
	}
	groups += (a1 + 3) / 4;
	cout << groups << '\n';
	return 0;
}
