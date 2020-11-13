#include <iostream>

using std::cin;
using std::cout;

int main(){
	int d = 0;
	cin >> d;
	for(int i = 0; i < d; ++i){
		int n = 0;
		cin >> n;
		int place = 0;
		while(n > 0){
			if(n % 2 == 1)
				cout << place << " ";
			n /= 2;
			++place;
		}
		cout << "\n";
	}
	return 0;
}
