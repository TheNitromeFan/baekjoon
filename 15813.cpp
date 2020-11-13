#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string name;
	cin >> name;
	int points = 0;
	for(char c : name){
		points += c - 'A' + 1;
	}
	cout << points;
	return 0;
}
