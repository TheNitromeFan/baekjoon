#include <iostream>

using namespace std;

int main(){
	int finger;
	long long cnt;
	cin >> finger >> cnt;
	long long ans = 0;
	if(finger == 1){
		ans = 8 * cnt;
	}else if(finger == 5){
		ans = 4 + 8 * cnt;
	}else if(finger == 2){
		if(cnt % 2 == 0){
			ans = 1 + 8 * (cnt / 2);
		}else{
			ans = 7 + 8 * (cnt / 2);
		}
	}else if(finger == 4){
		if(cnt % 2 == 0){
			ans = 3 + 8 * (cnt / 2);
		}else{
			ans = 5 + 8 * (cnt / 2);
		}
	}else{
		if(cnt % 2 == 0){
			ans = 2 + 8 * (cnt / 2);
		}else{
			ans = 6 + 8 * (cnt / 2);
		}
	}
	cout << ans;
	return 0;
}
