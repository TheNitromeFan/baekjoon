#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int sum = 0;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		sum += x;
	}
	cout << (sum % 3 == 0 ? "yes" : "no");
	return 0;
}
