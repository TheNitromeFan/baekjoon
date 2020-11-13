#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string my_name, my_prefs;
	int d;
	cin >> my_name >> my_prefs >> d;
	int n;
	cin >> n;
	vector<string> names;
	for(int i = 0; i < n; ++i){
		string name;
		char gender;
		int dist;
		cin >> name >> gender >> dist;
		if((my_prefs.length() == 2 || my_prefs[0] == gender) && dist <= d){
			names.push_back(name);
		}
	}
	if(!names.empty()){
		sort(names.begin(), names.end());
		for(string name : names){
			cout << name << '\n';
		}
	}else{
		cout << "No one yet";
	}
	return 0;
}
