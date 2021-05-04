#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string alphabet, hum;
	cin >> alphabet >> hum;
	int i = -1;
	for(char c : hum){
		do{
			++i;
		}while(alphabet[i % 26] != c);
	}
	cout << i / 26 + 1;
	return 0;
}
