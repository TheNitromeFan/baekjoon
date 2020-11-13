#include <iostream>
#include <string>
#include <set>

using namespace std;

bool play(set<string> &beat, int n, int g, int w, int l){
	int score = 0;
	for(int i = 0; i < n; ++i){
		string name;
		cin >> name;
		if(beat.find(name) == beat.end()){
			score -= l;
			if(score < 0){
				score = 0;
			}
		}else{
			score += w;
			if(score >= g){
				return true;
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, p, w, l, g;
	cin >> n >> p >> w >> l >> g;
	set<string> beat;
	for(int i = 0; i < p; ++i){
		string name;
		char res;
		cin >> name >> res;
		if(res == 'W'){
			beat.insert(name);
		}
	}
	if(play(beat, n, g, w, l)){
		cout << "I AM NOT IRONMAN!!";
	}else{
		cout << "I AM IRONMAN!!";
	}
	return 0;
}
