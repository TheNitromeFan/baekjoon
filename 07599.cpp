#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string library;
		unsigned font;
		cin >> library >> font;
		if(library == "#" && font == 0){
			break;
		}
		cout << library << " Library\n";
		int c;
		cin >> c;
		for(int i = 1; i <= c; ++i){
			unsigned width;
			string text;
			cin >> width >> text;
			if(font * text.length() + 2 <= width){
				cout << "Book " << i << " horizontal\n";
			}else{
				cout << "Book " << i << " vertical\n";
			}
		}
	}
	return 0;
}
