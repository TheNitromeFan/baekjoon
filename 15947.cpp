#include <cstdio>
#include <string>

using namespace std;

string lyric(int n){
	string ret;
	int rep;
	switch(n % 14){
		case 1:
		case 13:
			ret = "baby";
			break;
		case 2:
		case 0:
			ret = "sukhwan";
			break;
		case 5:
			ret = "very";
			break;
		case 6:
			ret = "cute";
			break;
		case 9:
			ret = "in";
			break;
		case 10:
			ret = "bed";
			break;
		case 3:
		case 7:
		case 11:
			rep = (n - 1) / 14;
			switch(rep){
				case 0:
					ret = "tururu";
					break;
				case 1:
					ret = "turururu";
					break;
				case 2:
					ret = "tururururu";
					break;
				default:
					ret = "tu+ru*" + to_string(rep + 2);
					break;
			}
			break;
		case 4:
		case 8:
		case 12:
			rep = (n - 1) / 14;
			switch(rep){
				case 0:
					ret = "turu";
					break;
				case 1:
					ret = "tururu";
					break;
				case 2:
					ret = "turururu";
					break;
				case 3:
					ret = "tururururu";
					break;
				default:
					ret = "tu+ru*" + to_string(rep + 1);
					break;
			}
			break;
	}
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%s", lyric(n).c_str());
	return 0;
}
