#include <iostream>
#include <map>
#include <iomanip>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    //A+B for Polynomials
//2 1 2.4 0 3.2
//2 2 1.5 1 0.5
//3 2 1.5 1 2.9 0 3.2
    map<int, double> hash;
    int count1 = 0;
    int count2 = 0;
    cin >> count1;
    for ( int i = 0; i < count1; ++i){
        int e = 0;
        double co = 0.0;
        cin >> e >> co;
        hash[e] = co;
    }

    cin >> count2;
    for ( int i = 0; i < count2; ++i){
        int e = 0;
        double co = 0.0;

        cin >> e >> co;

        map<int, double>::iterator iter = hash.find(e);
        if (iter != hash.end()) {
            double last_co = iter->second;
            hash[e] = co + last_co;
        } else {
            hash[e] = co;
        }
    }

    map<int, double>::iterator iter = hash.begin();
    for(; iter != hash.end(); ){
        if (fabs(iter->second) < 0.00000001) {
            iter = hash.erase(iter);
        } else {
            iter++;
        }
    }
    cout << hash.size();
    //printf("%d", hash.size());
    cout << showpoint <<setiosflags(ios::fixed) << setprecision(1);


    map<int, double>::reverse_iterator  riter = hash.rbegin();
    map<int, double>::reverse_iterator  riter_end = hash.rend();
    for(; riter != riter_end; riter++){
        cout << " "<< riter->first << " "<< riter->second;
        //printf(" %d %.1f", riter->first, riter->second);
    }
    return 0;
}
