#include <iostream>

using std::cin;
using std::cout;

int main(){
	int x = 0;
	cin >> x;
	int num = 1, den = 1, count = 1;
	while(count < x){
		if((num + den) % 2 == 0){
			++den;
			if(num > 1)
				--num;
		}else{
			++num;
			if(den > 1)
				--den;
		}
		++count;
	}
	cout << num << "/" << den;
	return 0;
}
