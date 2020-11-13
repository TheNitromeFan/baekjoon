#include <iostream>
#include <string>

using namespace std;

int main(){
	string shout, diagnose;
	cin >> shout >> diagnose;
	cout << ((shout.length() >= diagnose.length()) ? "go" : "no");
	return 0;
}
