#include <iostream>
#include <string>

using namespace std;

bool beautiful(string notes){
	for(unsigned i = 0; i + 1 < notes.length(); ++i){
		switch((notes[i + 1] + 7 - notes[i]) % 7){
			case 0:
			case 1:
			case 3:
			case 5:
				return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string line;
		cin >> line;
		if(line == "#"){
			break;
		}
		cout << (beautiful(line) ? "That music is beautiful." : "Ouch! That hurts my ears.") << '\n';
	}
	return 0;
}
