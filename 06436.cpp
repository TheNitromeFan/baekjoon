#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 0;
	while(true){
		int s;
		cin >> s;
		if(s == 0){
			break;
		}
		++t;
		int compressed = (s + 1) / 2;
		int uuencoded = compressed + (compressed + 1) / 2;
		int floppies = (uuencoded + 1859999) / 1860000;
		cout << "File #" << t << "\nJohn needs " << floppies << " floppies.\n\n";
	}
	return 0;
}
