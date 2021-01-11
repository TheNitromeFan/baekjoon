#include <iostream>

using namespace std;

long long dance(int low, int high){
	if(high - low == 1){
		return 0;
	}else if(high - low == 2){
		return low * (low + 1);
	}else{
		return dance(low, (low + high + 1) / 2) + dance((low + high + 1) / 2, high);
	}
}

int main(){
	int n;
	cin >> n;
	cout << dance(1, n + 1);
	return 0;
}
