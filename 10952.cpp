#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
	int a = 0, b = 0;
	while(true){
		cin >> a >> b;
		if(a == 0 && b == 0)
			break;
		cout << a+b << endl;
	}
	return 0;
}
