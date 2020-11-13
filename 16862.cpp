#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string line;
	getline(cin, line);
	for(int i = 0; i < n; ++i){
		getline(cin, line);
		for(unsigned idx = 0; idx < line.length(); ++idx){
			if(line[idx] == 'A' || line[idx] == 'a'){
				if(idx + 2 < line.length()
				&& (line[idx + 1] == 'R' || line[idx + 1] == 'r')
				&& (line[idx + 2] == 'E' || line[idx + 2] == 'e')){
					cout << (line[idx] == 'A' ? 'R' : 'r');
					idx += 2;
					continue;
				}else if(idx + 2 < line.length()
				&& (line[idx + 1] == 'N' || line[idx + 1] == 'n')
				&& (line[idx + 2] == 'D' || line[idx + 2] == 'd')){
					cout << '&';
					idx += 2;
					continue;
				}else if(idx + 1 < line.length()
				&& (line[idx + 1] == 'T' || line[idx + 1] == 't')){
					cout << '@';
					++idx;
					continue;
				}
			}else if(line[idx] == 'B' || line[idx] == 'b'){
				if(idx + 2 < line.length()
				&& (line[idx + 1] == 'E' || line[idx + 1] == 'e')
				&& (line[idx + 2] == 'A' || line[idx + 2] == 'a' || line[idx + 2] == 'E' || line[idx + 2] == 'e')){
					cout << (line[idx] == 'B' ? 'B' : 'b');
					idx += 2;
					continue;
				}else if(idx + 1 < line.length()
				&& (line[idx + 1] == 'E' || line[idx + 1] == 'e')){
					cout << (line[idx] == 'B' ? 'B' : 'b');
					++idx;
					continue;
				}
			}else if(line[idx] == 'T' || line[idx] == 't'){
				if(idx + 2 < line.length()
				&& (line[idx + 1] == 'O' || line[idx + 1] == 'o' || line[idx + 1] == 'W' || line[idx + 1] == 'w')
				&& (line[idx + 2] == 'O' || line[idx + 2] == 'o')){
					cout << 2;
					idx += 2;
					continue;
				}else if(idx + 1 < line.length()
				&& (line[idx + 1] == 'O' || line[idx + 1] == 'o')){
					cout << 2;
					++idx;
					continue;
				}
			}else if(line[idx] == 'F' || line[idx] == 'f'){
				if(idx + 3 < line.length()
				&& (line[idx + 1] == 'O' || line[idx + 1] == 'o')
				&& (line[idx + 2] == 'U' || line[idx + 2] == 'u')
				&& (line[idx + 3] == 'R' || line[idx + 3] == 'r')){
					cout << 4;
					idx += 3;
					continue;
				}else if(idx + 2 < line.length()
				&& (line[idx + 1] == 'O' || line[idx + 1] == 'o')
				&& (line[idx + 2] == 'R' || line[idx + 2] == 'r')){
					cout << 4;
					idx += 2;
					continue;
				}
			}else if(idx + 2 < line.length()
			&& (line[idx] == 'S' || line[idx] == 's')
			&& (line[idx + 1] == 'E' || line[idx + 1] == 'e')
			&& (line[idx + 2] == 'A' || line[idx + 2] == 'a' || line[idx + 2] == 'E' || line[idx + 2] == 'e')){
				cout << (line[idx] == 'S' ? 'C' : 'c');
				idx += 2;
				continue;
			}else if(idx + 2 < line.length()
			&& (line[idx] == 'E' || line[idx] == 'e')
			&& (line[idx + 1] == 'Y' || line[idx + 1] == 'y')
			&& (line[idx + 2] == 'E' || line[idx + 2] == 'e')){
				cout << (line[idx] == 'E' ? 'I' : 'i');
				idx += 2;
				continue;
			}else if(idx + 2 < line.length()
			&& (line[idx] == 'Y' || line[idx] == 'y')
			&& (line[idx + 1] == 'O' || line[idx + 1] == 'o')
			&& (line[idx + 2] == 'U' || line[idx + 2] == 'u')){
				cout << (line[idx] == 'Y' ? 'U' : 'u');
				idx += 2;
				continue;
			}else if(line[idx] == 'O' || line[idx] == 'o'){
				if(idx + 2 < line.length()
				&& (line[idx + 1] == 'N' || line[idx + 1] == 'n')
				&& (line[idx + 2] == 'E' || line[idx + 2] == 'e')){
					cout << 1;
					idx += 2;
					continue;
				}else if(idx + 2 < line.length()
				&& (line[idx + 1] == 'W' || line[idx + 1] == 'w')
				&& (line[idx + 2] == 'E' || line[idx + 2] == 'e')){
					cout << (line[idx] == 'O' ? 'O' : 'o');
					idx += 2;
					continue;
				}else if(idx + 1 < line.length()
				&& (line[idx + 1] == 'H' || line[idx + 1] == 'h')){
					cout << (line[idx] == 'O' ? 'O' : 'o');
					++idx;
					continue;
				}
			}else if(line[idx] == 'W' || line[idx] == 'w'){
				if(idx + 2 < line.length()
				&& (line[idx + 1] == 'H' || line[idx + 1] == 'h')
				&& (line[idx + 2] == 'Y' || line[idx + 2] == 'y')){
					cout << (line[idx] == 'W' ? 'Y' : 'y');
					idx += 2;
					continue;
				}else if(idx + 2 < line.length()
				&& (line[idx + 1] == 'O' || line[idx + 1] == 'o')
				&& (line[idx + 2] == 'N' || line[idx + 2] == 'n')){
					cout << 1;
					idx += 2;
					continue;
				}
			}
			cout << line[idx];
		}
		cout << '\n';
	}
	return 0;
}
