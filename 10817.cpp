#include <iostream>

using std::cin;
using std::cout;

static int middle(int a, int b, int c){
	if(a < b){
		if(b < c)
			return b;
		else if(a > c)
			return a;
	}else{
		if(a < c)
			return a;
		else if(b > c)
			return b;
	}
	return c;
}

int main(){
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	cout << middle(a, b, c);
	return 0;
}
