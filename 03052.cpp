#include <iostream>

using namespace std;

int main(){
	int a[10];
	for(int i = 0; i < 10; ++i){
		cin >> a[i];
	}
	bool considered[42] = {};
	int cnt = 0;
	for(int i = 0; i < 10; ++i){
		if(!considered[a[i] % 42]){
			considered[a[i] % 42] = true;
			++cnt;
		}
	}
	cout << cnt << endl;
}
