#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int evols = 0;
	string maxName;
	int maxEvols = 0;
	for(int i = 0; i < n; ++i){
		string name;
		cin >> name;
		int ki, mi;
		cin >> ki >> mi;
		int evoli = 0;
		while(mi >= ki){
			++evoli;
			mi -= ki;
			mi += 2;
		}
		evols += evoli;
		if(maxEvols < evoli){
			maxEvols = evoli;
			maxName = name;
		}
	}
	cout << evols << '\n' << maxName;
	return 0;
}
