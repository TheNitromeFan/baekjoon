#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int toys, lost;
		cin >> toys >> lost;
		if(toys == 0 && lost == 0){
			break;
		}
		int back = toys - lost;
		if(back == 1){
			cout << 0 << ' ' << 0 << '\n';
		}else if(back % 2 == 0){
			cout << back / 2 << ' ' << 0 << '\n';
		}else{
			cout << (back - 3) / 2 << ' ' << 1 << '\n';
		}
	}
	return 0;
}
