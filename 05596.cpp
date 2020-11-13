#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int s = 0, t = 0, a;
	for(int i = 0; i < 4; ++i){
		cin >> a;
		s += a;
	}
	for(int i = 0; i < 4; ++i){
		cin >> a;
		t += a;
	}
	cout << max(s, t);
	return 0;
}
