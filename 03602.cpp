#include <iostream>
#include <algorithm>

using namespace std;

int side(int b, int w){
	if(b > w){
		swap(b, w);
	}
	for(int n = 142; n > 0; --n){
		if((n % 2 == 0 && b >= n * n / 2) || (n % 2 == 1 && b >= n * n / 2 && w >= n * n / 2 + 1)){
			return n;
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int b, w;
	cin >> b >> w;
	int ans = side(b, w);
	if(ans){
		cout << ans;
	}else{
		cout << "Impossible";
	}
	return 0;
}
