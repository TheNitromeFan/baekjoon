#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int mush[10];
	for(int i = 0; i < 10; ++i){
		cin >> mush[i];
	}
	int ans = 0;
	for(int i = 0; i < 10; ++i){
		int tmp = ans + mush[i];
		if(abs(tmp - 100) < abs(ans - 100) || (abs(tmp - 100) == abs(ans - 100) && tmp >= 100)){
			ans = tmp;
		}else{
			break;
		}
	}
	cout << ans;
	return 0;
}
