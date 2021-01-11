#include <cstdio>
#include <cassert>
#include <cstdlib>
using namespace std;

int main(int agrc, char **agrv){
    FILE *output = fopen(agrv[3],"r");
    
    char c;
    long long dap = 0;
    int cnt = 0;
    while (1) {
        int res = fscanf(output,"%c",&c);
        if (res == EOF) break;
        
        cnt++;
        assert(res == 1 && cnt <= 990316);
        
        long long tmp = 1;
        for (int i = 0; i < 814; i++) {
            tmp = (tmp*c)%20200429;
        }
        dap += tmp;
    }
    
    fclose(output);
    
    assert((dap%20200429) == 20200402);
    
    return 0;
}