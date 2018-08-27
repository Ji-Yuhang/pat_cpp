//#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
//1007 Maximum Subsequence Sum
struct Group {
    Group() : sum(-999999) {}
    vector<int> array;
    int sum;
};

vector<Group> cache_max_g(vector<int> array)
{
    static map<vector<int>, vector<Group> > cache;
    auto it = cache.find(array);
    if (it != cache.end()) {
        auto temp = cache[array];
        cache.erase(it);
        return temp;
    }

    vector<int> last_part;
    if (!array.empty()) {
        vector<int> part;
        part.push_back(array[0]);
        vector<Group> groups;


        int sum = 0;
        vector<int> temp;
        for (int j = 0; j < part.size(); j++) {
            temp.push_back(part[j]);
            sum += part[j];
        }
        Group g;
        g.sum = sum;
        g.array = temp;
        groups.push_back(g);
        cache[part] = groups;
        last_part = part;
    }
    for (int i = 1; i < array.size(); i++) {
        int d = array[i];
        vector<int> part = last_part;
        part.push_back(array[i]);
        vector<Group> groups;
        for (Group g : cache[last_part]) {
            g.sum += d;
            g.array.push_back(d);
            groups.push_back(g);
        }
        Group g;
        g.sum = d;
        vector<int> temp;
        temp.push_back(d);
        g.array = temp;
        groups.push_back(g);
        cache[part] = groups;
        last_part = part;
    }
    it = cache.find(array);
    if (it != cache.end()) {
        auto temp = cache[array];
        cache.erase(it);
        return temp;
    }

}
Group max_g(vector<int> array)
{
    int max_sum = 0;
    map<int, Group> cache;

    vector<Group> groups = cache_max_g(array);
    for (int i = 0; i < groups.size(); i++) {
        int sum = groups[i].sum;
        if (i == 0) { max_sum = sum; }
        cache[sum] = groups[i];
        max_sum = max(max_sum, sum);
    }
    return cache[max_sum];
    //groups
    for (int i = 0; i < array.size(); i++) {
        int sum = 0;
        vector<int> temp;
        for (int j = i; j < array.size(); j++) {
            temp.push_back(array[j]);
            sum += array[j];
        }
        Group g;
        g.sum = sum;
        g.array = temp;
        cache[sum] = g;
        if (i == 0) { max_sum = sum; }
        max_sum = max(max_sum, sum);
    }
    return cache[max_sum];
}
Group max_f(vector<int> array, Group g)
{
    vector<int> part = array;
    int last = array.back();
    part.pop_back();

    if (part.empty()) {
        Group temp;
        vector<int> a;
        a.push_back(last);
        temp.sum = last;
        temp.array = a;
        if (temp.sum < g.sum) {
            return g;
        }
        else {
            return temp;
        }
        //return temp;
    }
    Group other_g = max_g(array);
    Group t1 = max_f(part, other_g);
    if (t1.sum < g.sum) {
        return g;
    }
    else {
        return t1;
    }
}

int main2()
{
    int n;
    cin >> n;
    vector<int> a;
    vector<int> sum;
    a.resize(n);
    sum.resize(n);

    bool positive = false;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        a[i] = d;
        if (d >= 0) positive = true;
    }

    if (positive) {
        Group g = max_f(a, Group());
        cout << g.sum << " " << g.array.front() << " " << g.array.back();
    }
    else {
        cout << 0 << " " << a[0] << " " << a[n - 1];
    }
    //system("pause");
    return 0;
}
