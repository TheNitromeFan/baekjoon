#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int maxPoints = 0;
	string maxName;
	for(int i = 0; i < n; ++i){
		string name;
		int points;
		cin >> name >> points;
		if(points > maxPoints || (points == maxPoints && name < maxName)){
			maxPoints = points;
			maxName = name;
		}
	}
	cout << maxName;
	return 0;
}
