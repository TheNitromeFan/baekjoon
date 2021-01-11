#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int fibs[41];
	fibs[0] = 1;
	fibs[1] = 1;
	for(int i = 2; i <= 40; ++i){
		fibs[i] = fibs[i - 1] + fibs[i - 2];
	}
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		cout << fibs[n] << '\n';
	}
	return 0;
}
