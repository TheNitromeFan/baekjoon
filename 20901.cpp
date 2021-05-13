#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>
#define PI acos(-1)

using namespace std;

bool tower(vector<pair<string, int>> b, int n){
	for(int i = 0; i + 1 < n; ++i){
		if((b[i].first == "cube" && b[i + 1].first == "cylinder" && b[i].second / sqrt(2) > b[i + 1].second)
		|| (b[i].first == "cylinder" && b[i + 1].first == "cube" && b[i].second > b[i + 1].second / 2)){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<string, int>> blocks(n);
	for(int i = 0; i < n; ++i){
		cin >> blocks[i].first >> blocks[i].second;
	}
	sort(blocks.begin(), blocks.end(), [](pair<string, int> a, pair<string, int> b){
		if(a.first == b.first){
			return a.second < b.second;
		}else if(a.first == "cube" && b.first == "cylinder"){
			return 4 * a.second < 2 * PI * b.second;
		}else{
			return 2 * PI * a.second < 4 * b.second;
		}
	});
	if(tower(blocks, n)){
		for(pair<string, int> p : blocks){
			cout << p.first << ' ' << p.second << '\n';
		}
	}else{
		cout << "impossible\n";
	}
	return 0;
}
