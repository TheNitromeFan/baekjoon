#include <iostream>
#include <string>
#include <utility>

using namespace std;

pair<int, int> key(char c){
	if(c <= 'c'){
		return make_pair(2, c - 'a' + 1);
	}else if(c <= 'f'){
		return make_pair(3, c - 'c');
	}else if(c <= 'i'){
		return make_pair(4, c - 'f');
	}else if(c <= 'l'){
		return make_pair(5, c - 'i');
	}else if(c <= 'o'){
		return make_pair(6, c - 'l');
	}else if(c <= 's'){
		return make_pair(7, c - 'o');
	}else if(c <= 'v'){
		return make_pair(8, c - 's');
	}else{
		return make_pair(9, c - 'v');
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int key_map[10];
	for(int i = 1; i <= 9; ++i){
		int x;
		cin >> x;
		key_map[x] = i;
	}
	string message;
	cin >> message;
	for(unsigned i = 0; i < message.length(); ++i){
		pair<int, int> p = key(message[i]);
		for(int j = 0; j < p.second; ++j){
			cout << key_map[p.first];
		}
		if(i + 1 < message.length() && p.first == key(message[i + 1]).first){
			cout << '#';
		}
	}
	return 0;
}
