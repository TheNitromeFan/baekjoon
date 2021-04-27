#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	if(n % 4 == 0){
		cout << "Even";
	}else if(n % 4 == 2){
		cout << "Odd";
	}else{
		cout << "Either";
	}
	return 0;
}
