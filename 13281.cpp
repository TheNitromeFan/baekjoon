#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

bool decided(map<char, int> &v, int n, char &c, int remain){
	c = ' ';
	int max = 0;
	for(pair<char, int> p : v){
		if(p.second > max){
			c = p.first;
			max = p.second;
		}
	}
	if(max <= remain){
		return false;
	}
	for(pair<char, int> p : v){
		if(p.first == c){
			continue;
		}
		if(p.second + remain >= v[c]){
			return false;
		}
	}
	return true;
}

void winner(vector<char> &ballots, int n){
	map<char, int> votes;
	for(int i = 0; i < n; ++i){
		char c = ballots[i];
		if(votes.find(c) == votes.end()){
			votes[c] = 1;
		}else{
			++votes[c];
		}
		if(decided(votes, n, c, n - i - 1)){
			cout << c << ' ' << i + 1 << '\n';
			return;
		}
	}
	cout << "TIE\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		vector<char> ballots(n);
		for(int i = 0; i < n; ++i){
			cin >> ballots[i];
		}
		winner(ballots, n);
	}
	return 0;
}
