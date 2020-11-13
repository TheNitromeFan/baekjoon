#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string line;
	while(getline(cin, line)){
		bool bug;
		do{
			bug = false;
			string new_line;
			for(unsigned i = 0; i < line.length(); ++i){
				if(i + 2 < line.length() && line[i] == 'B' && line[i + 1] == 'U' && line[i + 2] == 'G'){
					i += 2;
					bug = true;
					continue;
				}
				new_line += line[i];
			}
			line = new_line;
		}while(bug);
		cout << line << '\n';
	}
	return 0;
}
