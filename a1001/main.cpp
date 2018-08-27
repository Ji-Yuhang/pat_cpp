#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
using namespace std;

int main()
{
    long long a = 0;
    long long b = 0;
    long long sum = 0;

    a = -1000000;
    b = 9;

    //cin >> a >> b;

    sum = a + b;

    stringstream ss;
    ss << sum;
    string str = ss.str();

    stringstream ss2;
    int mod = 3;
    int counter = 0;
    for(int i = str.size() - 1; i >= 0; --i){


        ss2 << str[i];

        counter++;

        if (counter % mod == 0 && i != 0) {
            if (i == 1 && !isdigit(str[0])) {
                continue;
            } else {
                ss2 << ',';
            }
        }
    }

    string reversed_str = ss2.str();
    reverse(reversed_str.begin(), reversed_str.end());

    cout << reversed_str;


    return 0;
}
