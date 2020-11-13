#include <iostream>
#include <string>

using namespace std;

int main(){
	string x, y, z;
	cin >> x >> y >> z;
	bool a = (x == "true"), b = (z == "true");
	bool ans;
	if(y == "AND"){
		ans = a && b;
	}else{
		ans = a || b;
	}
	cout << (ans ? "true" : "false");
	return 0;
}
