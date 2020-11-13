#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
	int sum_odd = 0, min_odd = 101;
	for(int i = 0; i < 7; ++i){
		int n = 0;
		cin >> n;
		if(n % 2 == 1){
			sum_odd += n;
			if(n < min_odd)
				min_odd = n;
		}
	}
	if(sum_odd == 0)
		cout << "-1";
	else
		cout << sum_odd << "\n" << min_odd;
	return 0;
}
