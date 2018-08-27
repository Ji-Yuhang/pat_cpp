#include <iostream>
#include <cmath>
#include <map>
#include <iomanip>
using namespace std;

int main()
{
    int a,b;
    double x[1001] = {0};
    double y[1001] = {0};
    cin >> a;
    for (int i = 0; i < a; i++){
        int e;
        double co;
        cin >> e >> co;
        x[e] = co;
    }
    cin >> b;
    for (int i = 0; i < b; i++){
        int e;
        double co;
        cin >> e >> co;
        y[e] = co;
    }
    double z[2002] = {0};
    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            double co = x[i] * y[j];
            int e = i + j;
            z[e] += co;
        }
    }
    int count = 0;
    map<int, double> r;
    for (int i = 2001; i >=0 ; i--)
    {
        if( fabs(z[i]) >= 0.00000001){
            r[i] = z[i];
        }
    }
    cout << r.size() << setprecision(1) << fixed;
    for(map<int, double>::reverse_iterator it = r.rbegin(); it != r.rend(); it++){
        cout << " "<< it->first << " "<<it->second;
    }




    return 0;
}
