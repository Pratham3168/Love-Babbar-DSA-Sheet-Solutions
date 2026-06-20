#include<bits/stdc++.h>
using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--){
        int m,n;
        cin >> m >> n;

        vector<int> xp(m-1);
        vector<int> yp(n-1);

        for(int i = 0 ; i< m-1 ; i++){
            cin >> xp[i];
        }
        for(int i = 0 ; i< n-1 ; i++){
            cin >> yp[i];
        }

        sort(xp.begin(),xp.end());
        sort(yp.begin(),yp.end());

        int v = xp.size() - 1;
        int h = yp.size() - 1;

        int vertical_cut = 1;
        int horizontal_cut = 1;

        int vertical_cost = 0;
        int horizontal_cost = 0;

        while(v >=0 && h>=0){
            if(xp[v] >= yp[h]){
                vertical_cut ++;
                vertical_cost += horizontal_cut * xp[v];
                v--;
            }
            else{  
                horizontal_cut ++;
                horizontal_cost += vertical_cut * yp[h];
                h--;
            }
        }

        while(v>=0){
            vertical_cut ++;
            vertical_cost += horizontal_cut * xp[v];
            v--;
        }

        while(h>=0){
            horizontal_cut ++;
            horizontal_cost += vertical_cut * yp[h];
            h--;
        }

        cout << (long long)vertical_cost + horizontal_cost << '\n';

    }

    

    return 0;
    


}