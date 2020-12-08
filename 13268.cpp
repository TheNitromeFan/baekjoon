#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	n %= 100;
	int ans = -1;
	if(n == 0 || n == 10 || n == 30 || n == 60){
		ans = 0;
	}else if(n > 75 && n < 85){
		ans = 4;
	}else if((n > 40 && n < 50) || (n > 70 && n < 90)){
		ans = 3;
	}else if((n > 15 && n < 25) || (n > 35 && n < 55) || (n > 65 && n < 95)){
		ans = 2;
	}else{
		ans = 1;
	}
	cout << ans;
	return 0;
}
