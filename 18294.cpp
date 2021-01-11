#include <iostream>
#include <string>
#include <map>
#include <utility>

using namespace std;

string overtake(map<string, int> &animals, int n){
	for(pair<const string, int> &p : animals){
		string animal = p.first;
		int x = p.second;
		if(x > n - x){
			return animal;
		}
	}
	return "NONE";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	map<string, int> animals;
	for(int i = 0; i < n; ++i){
		string animal;
		cin >> animal;
		++animals[animal];
	}
	cout << overtake(animals, n);
	return 0;
}
