#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
using namespace std;

vector<int> find_max(const vector<int>& a, int mid);
vector<int> find_cross_mid(const vector<int>& a, int mid);
vector<int> find_max_left(const vector<int>& a, int mid)
{
    vector<int> left;
    copy(a.begin(), a.begin()+ mid + 1, back_inserter(left));
    if (left.size() <= 2) return find_cross_mid(left, mid /2);

    return find_max(left, left.size() / 2);
}
vector<int> find_max_right(const vector<int>& a, int mid)
{
    vector<int> right;
    copy(a.begin()+ mid, a.end(),  back_inserter(right));
    if (right.size() <= 2) return find_cross_mid(right, mid / 2);
    return find_max(right, right.size() / 2);

}
vector<int> find_cross_mid(const vector<int>& a, int mid)
{
    if (a.size() == 1){
        return a;
    }
    if (a.empty()) return a; // ???
    int max_left_sum = -9999;// TODO: -无穷
    int max_left_i = mid;
    for (int i = mid; i >= 0; i--)
    {
        // sum from i to mid
        int sum = 0;
        for (int j = i; j <= mid; j++)
        {
            sum += a[j];
        }
        if (sum > max_left_sum) {
             max_left_sum = sum;
             max_left_i = i;
        }
    }

    int max_right_sum = -9999;// TODO: -无穷
    int max_right_i = mid;

    for (int i = mid; i < a.size(); i++)
    {
        // sum from mid to i
        int sum = 0;
        for (int j = mid; j <= i; j++)
        {
            sum += a[j];
        }
        if (sum > max_right_sum) {
             max_right_sum = sum;
             max_right_i = i;
        }
    }
    vector<int> result;
    copy(a.begin()+max_left_i, a.begin()+max_right_i+1, back_inserter(result));

    return result;

}
vector<int> find_max(const vector<int>& a, int mid)
{
    if (a.size() == 1){
        return a;
    }
    vector<int> left = find_max_left(a, mid);
    vector<int> right = find_max_right(a, mid);
    vector<int> cross = find_cross_mid(a, mid);
    int left_sum = accumulate(left.begin(), left.end(), 0);
    int right_sum = accumulate(right.begin(), right.end(), 0);
    int cross_sum = accumulate(cross.begin(), cross.end(), 0);
    if (left_sum >= cross_sum && left_sum >= right_sum) return left;
    if (cross_sum >= right_sum && cross_sum >= left_sum) return cross;
    if (right_sum >= cross_sum && right_sum >= left_sum) return right;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    bool positive = false;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] >= 0) positive = true;
    }
    if (positive){
        vector<int> max = find_max(a, a.size() / 2);
        int sum = accumulate(max.begin(), max.end(), 0);
        cout << sum <<" "<< max.front() << " "<< max.back();
    } else {
        cout << 0 << " " << a[0] << " " << a[n - 1];
    }




    return 0;
}


