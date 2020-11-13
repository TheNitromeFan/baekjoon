#include <iostream>
#include <string>

using namespace std;

void letter_count(int c[26], string word){
	for(char letter : word){
		++c[letter - 'A'];
	}
}

bool similar(string s, string t){
	if(t.length() > s.length() + 1 || s.length() > t.length() + 1){
		return false;
	}
	int a[26] = {}, b[26] = {};
	letter_count(a, s);
	letter_count(b, t);
	int unequal = 0;
	for(int i = 0; i < 26; ++i){
		if(a[i] - b[i] < -1 || a[i] - b[i] > 1){
			return false;
		}else if(a[i] - b[i] == -1 || a[i] - b[i] == 1){
			++unequal;
		}
		if(unequal > 2){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	cin >> n;
	string word;
	cin >> word;
	int cnt = 0;
	for(int i = 1; i < n; ++i){
		string cmp;
		cin >> cmp;
		if(similar(word, cmp)){
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}
