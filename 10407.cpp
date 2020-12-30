#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string h;
	cin >> h;
	cout << (h == "1" ? 2 : 1);
	return 0;
}
