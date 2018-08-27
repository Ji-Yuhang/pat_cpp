#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 1005 Spell It Right
int main()
{
    string str;
    cin >> str;

    unsigned long long sum = 0;
    for (size_t i = 0; i < str.size(); ++i)
    {
        string temp = string() + str[i];
        int digit = stoi(temp);
        sum += digit;
    }
    string sum_str = to_string(sum);
    const string a[10]={"zero", "one","two","three","four","five","six","seven","eight","nine"};
    string temp = string() + sum_str[0];
    int digit = stoi(temp);
    cout << a[digit];
    for (size_t i = 1; i < sum_str.size(); ++i)
    {
        string temp = string() + sum_str[i];
        int digit = stoi(temp);
        cout << " "<< a[digit];

    }
    return 0;
}
