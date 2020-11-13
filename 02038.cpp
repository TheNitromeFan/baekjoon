#include <iostream>
#include <map>

using namespace std;

map<int, int> gol;

long long golomb(int n){
	if(n == 1){
		return 1;
	}
	gol[1] = 1;
	long long sum = 1;
	for(long long i = 2; i <= n; ++i){
		if(gol.find(i) != gol.end()){
			continue;
		}
		gol[i] = 1 + gol[i - gol[gol[i - 1]]];
		sum += gol[i];
		if(sum >= n){
			return i;
		}
	}
	return -1;
}

int main(){
	int n;
	cin >> n;
	cout << golomb(n);
	return 0;
}
