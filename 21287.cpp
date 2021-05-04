#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string rgb;
	cin >> rgb;
	unsigned idx = 0;
	for(int i = 0; i < n; ++i){
		bool red = false, green = false, blue = false;
		while(!red || !green || !blue){
			if(rgb[idx] == 'R'){
				red = true;
				if(green && blue){
					cout << 'R';
				}
			}else if(rgb[idx] == 'G'){
				green = true;
				if(red && blue){
					cout << 'G';
				}
			}else{
				blue = true;
				if(red && green){
					cout << 'B';
				}
			}
			++idx;
		}
	}
	return 0;
}
