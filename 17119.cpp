#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cout << i % 5 + 1;
	}
	return 0;
}
