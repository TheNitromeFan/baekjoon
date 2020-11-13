#include <iostream>

using namespace std;

int main(){
	for(int i = 0; i < 3; ++i){
		int sh, sm, st, eh, em, et;
		cin >> sh >> sm >> st >> eh >> em >> et;
		int start = sh * 60 * 60 + sm * 60 + st;
		int end = eh * 60 * 60 + em * 60 + et;
		int dur = end - start;
		int dh = dur / 60 / 60, dm = dur / 60 % 60, dt = dur % 60;
		cout << dh << ' ' << dm << ' ' << dt << '\n';
	}
	return 0;
}
