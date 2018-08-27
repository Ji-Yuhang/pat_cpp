#include <iostream>
#include <map>

using namespace std;
// 1006 Sign In and Sign Out
int main()
{
    int n;
    cin >> n;

    // < time, id >
    map<string, string> in_record;
    map<string, string> out_record;
    for (int i =0; i < n; i++)
    {
        string id, in_time_str, out_time_str;
        cin >> id >> in_time_str >> out_time_str;
        in_record.insert(make_pair(in_time_str, id));
        out_record.insert(make_pair(out_time_str, id));
    }
    cout << in_record.begin()->second << " ";
    cout << out_record.rbegin()->second;
    return 0;
}
