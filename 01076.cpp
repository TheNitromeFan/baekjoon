#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	map<string, int> colors;
	colors["black"] = 0;
	colors["brown"] = 1;
	colors["red"] = 2;
	colors["orange"] = 3;
	colors["yellow"] = 4;
	colors["green"] = 5;
	colors["blue"] = 6;
	colors["violet"] = 7;
	colors["grey"] = 8;
	colors["white"] = 9;
	string ten, one, multiplier;
	cin >> ten >> one >> multiplier;
	long long resistance = colors[ten] * 10LL + colors[one];
	for(int i = 0; i < colors[multiplier]; ++i){
		resistance *= 10;
	}
	cout << resistance << endl;
	return 0;
}
