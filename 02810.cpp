#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	cin >> n;
	string seats;
	cin >> seats;
	int cnt = 1, i = 0;
	while(i < n){
		if(seats[i] == 'S'){
			i += 1;
		}else{
			i += 2;
		}
		++cnt;
	}
	if(cnt > n){
		cnt = n;
	}
	cout << cnt;
	return 0;
}
