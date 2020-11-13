#include <iostream>
#include <string>

using namespace std;

string strings[11] = {"0", "1", "10", "11", "100", "101", "110", "111", "1000", "1001", "1010"};

int main(){
	int n;
	cin >> n;
	for(int i = 0; i <= n; ++i){
		cout << strings[i];
	}
	return 0;
}
