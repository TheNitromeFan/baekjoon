#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, k;
	cin >> a >> k;
	if(k == 0){
		cout << a;
	}else if(a % 2 == 0){
		cout << 1;
	}else{
		cout << a;
	}
	return 0;
}
