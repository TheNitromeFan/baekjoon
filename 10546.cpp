#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	map<string, int> racers;
	for(int i = 0; i < n; ++i){
		string racer;
		cin >> racer;
		if(racers.find(racer) == racers.end()){
			racers[racer] = 1;
		}else{
			++racers[racer];
		}
	}
	for(int i = 1; i < n; ++i){
		string racer;
		cin >> racer;
		--racers[racer];
	}
	for(auto p : racers){
		if(p.second == 1){
			cout << p.first;
			break;
		}
	}
	return 0;
}
