#include <iostream>
#include <string>
#define MAX 50001

using namespace std;

bool rearrange(int psum[][MAX], int a, int b, int c, int d){
	for(int x = 0; x < 26; ++x){
		if(psum[x][b] - psum[x][a - 1] != psum[x][d] - psum[x][c - 1]){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int psum[26][MAX] = {};
	for(unsigned i = 0; i < s.length(); ++i){
		for(int c = 0; c < 26; ++c){
			psum[c][i + 1] = psum[c][i];
			if(s[i] == c + 'a'){
				++psum[c][i + 1];
			}
		}
	}
	int q;
	cin >> q;
	for(int a0 = 0; a0 < q; ++a0){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << (rearrange(psum, a, b, c, d) ? "DA" : "NE") << "\n";
	}
	return 0;
}
