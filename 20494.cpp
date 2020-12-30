#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	unsigned sushi = 0;
	for(int i = 0; i < n; ++i){
		string bi;
		cin >> bi;
		sushi += bi.length();
	}
	cout << sushi;
	return 0;
}
