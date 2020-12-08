#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int amicable[16] =
	{220, 284, 1184, 1210, 2620, 2924, 5020, 5564,
	6232, 6368, 10744, 10856, 12285, 14595, 17296, 18416};
	int pair[16] =
	{284, 220, 1210, 1184, 2924, 2620, 5564, 5020,
	6368, 6232, 10856, 10744, 14595, 12285, 18416, 17296};
	int s;
	cin >> s;
	int idx = 0;
	for(; idx < 16; ++idx){
		if(amicable[idx] >= s){
			break;
		}
	}
	cout << amicable[idx] << " " << pair[idx];
	return 0;
}
