#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	int previous = 1, current = 3;
	for(int i = 2; i < n; ++i){
		int temp = current;
		current = (current +  2 * previous) % 10007;
		previous = temp;
	}
	cout << current << endl;
	return 0;
}
