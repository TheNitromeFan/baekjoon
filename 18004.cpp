#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	int ops = 0;
	while(a > b){
		if(a % 2 == 1){
			++a;
			++ops;
		}
		a /= 2;
		++ops;
	}
	while(a < b){
		++a;
		++ops;
	}
	cout << ops;
	return 0;
}
