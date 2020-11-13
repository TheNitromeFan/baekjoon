#include "NB.h"
#include <algorithm>

using namespace std;

int len;
bool candidates[10000];

bool valid_number(int n){
	if(len == 4){
		if(n > 9999){
			return false;
		}
		int a = n / 1000, b = n / 100 % 10, c = n / 10 % 10, d = n % 10;
		return a != b && b != c && c != d && a != c && b != d && a != d;
	}else{
		if(n > 999){
			return false;
		}
		int a = n / 100, b = n / 10 % 10, c = n % 10;
		return a != b && b != c && a != c;
	}
}

void initialize_candidates(){
	for(int i = 12; i <= 9876; ++i){
		if(valid_number(i)){
			candidates[i] = true;
		}
	}
}

pair<int, int> sb(string n, string m){
	int strikes = 0;
	for(unsigned i = 0; i < n.length(); ++i){
		if(n[i] == m[i]){
			++strikes;
		}
	}
	int strikes_plus_balls = 0;
	for(unsigned i = 0; i < n.length(); ++i){
		for(unsigned j = 0; j < m.length(); ++j){
			if(n[i] == m[j]){
				++strikes_plus_balls;
			}
		}
	}
	return make_pair(strikes, strikes_plus_balls - strikes);
}

void filter_candidates(string a, int strikes, int balls){
	for(int i = 12; i <= 9876; ++i){
		if(!valid_number(i)){
			continue;
		}
		string b = to_string(i);
		b = string(len - b.length(), '0') + b;
		pair<int, int> p = sb(a, b);
		if(candidates[i] && !(strikes == p.first && balls == p.second)){
			candidates[i] = false;
		}
	}
}

void init(int T, int N) {
    // init
    len = N;
}

void game() {
    // game
    initialize_candidates();
    for(int i = 12; i <= 9876; ++i){
    	if(!valid_number(i) || !candidates[i]){
    		continue;
		}
		string b = to_string(i);
		b = string(len - b.length(), '0') + b;
		// cout << b << '\n';
		pair<int, int> p = guess(b);
		int strikes = p.first, balls = p.second;
		// cout << strikes << ' ' << balls << '\n';
		if(strikes == len && balls == 0){
			break;
		}
		filter_candidates(b, strikes, balls);
	}
}
