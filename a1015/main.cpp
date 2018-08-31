#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int reverse_with_radix(int n, int d)
{
    vector<int> a;
    int t = n;
    while (t > 0){
        int r = t % d;
        t = t / d;
        a.push_back(r);
    }
    reverse(a.begin(), a.end());
    int sum = 0;
    int e = 0;
    for (auto co: a){
        sum += pow(d, e) * co;
        e++;
    }
    return sum;
}

int main()
{
    vector<pair<int, int> >ns;
    int max_n = -1;
    int n,d;
    do {
        cin >> n;
        if (n < 0) break;
        cin >> d;

        int rwr = reverse_with_radix(n, d);
        ns.push_back(make_pair(n, rwr));

        max_n = max(max_n, rwr);
        max_n = max(max_n, n);
    } while(n > 0);

    vector<bool> primes(max_n+1, true);
    primes[0] = false;
    primes[1] = false;
    //int limit = max_n / 2;
    for (int i = 2; i <=  max_n / 2; i++){
        for (int j = 2; j <= max_n; j++){
            int number = i*j;
            if (number > max_n) break;
            primes[number] = false;
        }
    }

    for(auto n: ns)
    {
        string str = primes[n.first] && primes[n.second] ? "Yes": "No";
        cout << str << "\n";
    }
    return 0;
}
