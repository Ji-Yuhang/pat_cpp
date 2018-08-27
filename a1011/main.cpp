#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double a[3] = {0.0};
    int b[3] = {0};
    char c[3] = {'W','T','L'};
    for (int i = 0; i < 3; i++)
    {

        double max_odd = -1.0;
        for (int j = 0; j < 3; j++){
            double odd;
            int max_j = 0;
            cin >> odd;
            if (odd > max_odd){
                max_odd = odd;
                max_j = j;
                a[i] = max_odd;
                b[i] = max_j;
            }
        }
    }
    double sum = 1.0;
    for (int i = 0; i < 3; i++){
        sum *= a[i];
        cout << c[b[i]] << " ";
    }
    cout << setprecision(2)<<fixed<< (sum* 0.65 - 1.0) * 2;

    return 0;
}
