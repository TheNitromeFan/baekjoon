#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int wc, hc, ws, hs;
	cin >> wc >> hc >> ws >> hs;
	cout << (wc >= ws + 2 && hc >= hs + 2);
	return 0;
}
