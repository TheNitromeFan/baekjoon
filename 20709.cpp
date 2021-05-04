#include <iostream>
#include <string>

using namespace std;

bool balloon2021(string &s){
	int zeroes = 0, ones = 0, twos = 0;
	for(char c : s){
		switch(c){
			case '0':
				++zeroes;
				break;
			case '1':
				++ones;
				break;
			case '2':
				++twos;
				break;
		}
	}
	return zeroes >= 1 && ones >= 1 && twos >= 2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int idx = 0;
	int min_price = 10000000;
	for(int i = 1; i <= n; ++i){
		int p;
		string balloons;
		cin >> p >> balloons;
		if(balloon2021(balloons) && p < min_price){
			idx = i;
			min_price = p;
		}
	}
	cout << idx;
	return 0;
}
