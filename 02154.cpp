#include <iostream>
#include <string>
#define MAX 100000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	for(int i = 1; i <= MAX; ++i){
		s += to_string(i);
	}
	int n;
	cin >> n;
	cout << s.find(to_string(n)) + 1;
	return 0;
}
