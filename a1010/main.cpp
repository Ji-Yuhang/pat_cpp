#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

int main()
{
    string n1,n2;
    int tag, radix;
    cin >> n1 >>n2 >>tag>> radix;

    string source;
    string target;

    if (tag == 1){
        source = n1;
        target = n2;
    } else {
        source = n2;
        target = n1;
    }

    //int sum;
    size_t *pos = 0;
    long long sum = stoll(source, pos, radix);
    //cout << sum;
    bool alpha = false;
    for(auto c: target){
        if (isalpha(c)) alpha = true;
    }
    int i = 2;
    if (alpha){
        i = 11;
    }
    for (; i<= 36; i++){
        size_t *t_pos = 0;

        double t_sum = 0;
        int e = 0;
        for(int j = target.size() - 1; j >= 0; j--){
            int co;
            char ch = target[j];
            if (isalpha(ch)){
                ch = toupper(ch);
                co = ch - 'A' + 10;
            } else {
                co = stoi(string()+ch);
            }
            t_sum += co * pow(i, e);
            e++;
        }
        //long long t_sum = stoll(target, t_pos, i);
        if (fabs(t_sum - sum) < 0.00000001){
            cout << i;
            return 0;
        }
    }
    cout <<"Impossible";



    return 0;
}
