#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int young = 0, min = 0;
	for(int i = 0; i < n; ++i){
		int t;
		cin >> t;
		young += ((t / 30) + 1) * 10;
		min += ((t / 60) + 1) * 15;
	}
	if(young < min){
		printf("Y %d", young);
	}else if(young > min){
		printf("M %d", min);
	}else{
		printf("Y M %d", young);
	}
	return 0;
}
