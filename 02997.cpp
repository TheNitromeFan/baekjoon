#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a+3);
	if(a[1] - a[0] == a[2] - a[1]){
		a[3] = a[2] + a[1] - a[0];
	}else if(a[1] - a[0] < a[2] - a[1]){
		a[3] = (a[1] + a[2]) / 2;
	}else{
		a[3] = (a[0] + a[1]) / 2;
	}
	cout << a[3];
	return 0;
}
