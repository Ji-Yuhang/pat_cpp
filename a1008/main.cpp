#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    a[0] = 0;
    int sum = 0;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> a[i];
        int time = 0;
        if (a[i] > a[i-1]){
            //up
            time += 6*(a[i] - a[i - 1]) + 5;
        } else {
            time += 4*(a[i - 1] - a[i]) + 5;
        }
        sum += time;
    }
    cout << sum;
    return 0;
}
