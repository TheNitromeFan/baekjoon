#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int b;
		cin >> b;
		if(b == 0){
			break;
		}
		int maxD = 1;
		int a = 1;
		for(int d = 1; d * d <= 2 * b; ++d){
			if(2 * b % d == 0 && d % 2 != (2 * b / d) % 2){
				maxD = d;
				a = (2 * b / d - d + 1) / 2;
			}
		}
		cout << a << ' ' << maxD << '\n';
	}
	return 0;
}
