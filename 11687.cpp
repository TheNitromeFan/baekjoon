#include <iostream>

using namespace std;

int trailing_zeroes(int n){
	int ret = 0;
	while(n >= 5){
		ret += n / 5;
		n /= 5;
	}
	return ret;
}

int search(int m){
	int low = 1, high = 1000000000;
	while(low < high){
		int mid = (low + high) / 2;
		if(trailing_zeroes(mid) >= m){
			high = mid;
		}else{
			low = mid + 1;
		}
	}
	if(trailing_zeroes(low) == m){
		return low;
	}else{
		return -1;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> m;
	cout << search(m);
	return 0;
}
