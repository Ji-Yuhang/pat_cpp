
```
Q: int 类型如何转 string  
A: 
// 1. stringstream
#include <sstream>
stringstream ss;
ss << sum;
string str = ss.str();

// 2. to_string
double f = 23.43;
std::string f_str = std::to_string(f);

```
```
Q: char 如何转 string
A:
sting str = string() + "a";

```
```
Q: string 类型转为 int double 等类型
A:
    std::string str1 = "45";
    std::string str2 = "3.14159";
    std::string str3 = "31337 with words";
    std::string str4 = "words and 2";
    int myint1 = std::stoi(str1);
    int myint2 = std::stoi(str2);
    int myint3 = std::stoi(str3);

```
```
Q: string 或 vector 容器内容如何逆序，调换顺序，头尾互换
A:
#include <algorithm>
#include <iterator>
std::vector<int> v({1,2,3});
reverse(v.begin(),v.end());

int a[] = {4, 5, 6, 7};
std::reverse(std::begin(a), std::end(a));

```
```
Q: 返回 string 或 vector 容器逆序后的结果，原容器不变
A:
#include <algorithm>
    std::vector<int> v({1,2,3});
    for (const auto& value : v) {
        std::cout << value << " ";
    }
    std::cout << '\n';

    std::vector<int> destination(3);
    std::reverse_copy(std::begin(v), std::end(v), std::begin(destination));
    for (const auto& value : destination) {
        std::cout << value << " ";
    }

```
```
Q: 如何判断字符是否数字
A:
#include <cctype>
char ch;
isdigit(ch);

```
```
Q: 如何判断字符是否大写字母
A:
#include <cctype>
char ch;
isupper(ch);

```
```
Q: 如何判断字符是否小写字母
A:
#include <cctype>
char ch;
islower(ch);

```
```
Q: 如何判断字符是否字母(包含大小写)
A:
#include <cctype>
char ch;
isalpha(ch);

```
```
Q: 如何判断字符是否字母或数字(包含大小写字母、数字)
A:
#include <cctype>
char ch;
isalnum(ch);

```
```
Q: 如何判断字符是否标点符号(!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~)
A:
#include <cctype>
char ch;
ispunct(ch);

```
```
Q: 如何判断字符是否可见字符（字母、数字、标点符号）（不包括空格）
A:
#include <cctype>
char ch;
isgraph(ch);

```
```
Q: 如何判断字符是否空格或制表符(space or tab)
A:
#include <cctype>
char ch;
isgraph(ch);

```
```
Q: 浮点数判断与 0 相等
A: 
#include <cmath>
double d(0.0);
if(fabs(d) < 0.00000001) {}

```
```
Q: 如何在容器循环内容删除元素    
A:
std::map<int, std::string> c = {{1, "one"}, {2, "two"}, {3, "three"},
                                    {4, "four"}, {5, "five"}, {6, "six"}};
    // erase all odd numbers from c
    for(auto it = c.begin(); it != c.end(); )
        if(it->first % 2 == 1)
            it = c.erase(it);
        else
            ++it;
    for(auto& p : c)
        std::cout << p.second << ' ';

```
```
Q: 如何用 C++11 auto for 循环 遍历容器
A:
std::vector<int> v = {0, 1, 2, 3, 4, 5};
    for (const int& i : v) // 以 const 引用访问
        std::cout << i << ' ';
    std::cout << '\n';

    for (auto i : v) // 以值访问， i 的类型是 int
        std::cout << i << ' ';
    std::cout << '\n';

    for (auto& i : v) // 以引用访问， i 的类型是 int&
        std::cout << i << ' ';
    std::cout << '\n';

    for (int n : {0, 1, 2, 3, 4, 5}) // 初始化器可以是花括号初始化列表
        std::cout << n << ' ';
    std::cout << '\n';

    int a[] = {0, 1, 2, 3, 4, 5};
    for (int n : a) // 初始化器可以是数组
        std::cout << n << ' ';
    std::cout << '\n';

```
```
Q: cout 如何显示小数点后面的0？ 如：1.0显示为 1.0 而不是 1
A: 
// showpoint
#include <iostream>
std::cout << "1.0 with showpoint: " << std::showpoint << 1.0 << '\n'
              << "1.0 with noshowpoint: " << std::noshowpoint << 1.0 << '\n';


```
```
Q: cout 设置小数精度
A: 
// setprecision
#include <iomanip>
const long double pi = std::acos(-1.L);
std::cout << "default precision (6): " << pi << '\n'
              << "std::setprecision(10): " << std::setprecision(10) << pi << '\n'
              << "max precision:         "
              << std::setprecision(std::numeric_limits<long double>::digits10 + 1)
              << pi << '\n';

```
```
Q: c++ 获取三角函数 PI 的具体数值
A:
#include <cmath>
const long double pi = std::acos(-1.L);

```
```
Q: c++ 科学计数法输出小数
A:
cout << "The number 0.01 inscientific:   " << std::scientific<< 0.01 << '\n'

```
```
Q: cout 输出小数固定小数位数
A:
cout << "The number 0.01 fixed:   " << std::fixed<< 0.01 << '\n'

```
```
Q: cout 十六进制输出数字,  并控制显示0x
A:
//showbase
#include <iostream>
#include <sstream>
int main(){
    std::cout << "The number 42 in octal:   " << std::oct << 42 << '\n'
              << "The number 42 in decimal: " << std::dec << 42 << '\n'
              << "The number 42 in hex:     " << std::hex << 42 << '\n';
    std::cout << std::hex
              << "showbase: " << std::showbase << 42 << '\n'
              << "noshowbase: " << std::noshowbase << 42 << '\n';
    int n;
    std::istringstream("2A") >> std::hex >> n;
    std::cout << std::dec << "Parsing \"2A\" as hex gives " << n << '\n';
}

```
```
Q: 数组取最大值的下标
A:
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
static bool abs_compare(int a, int b)
{
    return (std::abs(a) < std::abs(b));
}
int main()
{
    std::vector<int> v{ 3, 1, -14, 1, 5, 9 };
    std::vector<int>::iterator result;

    result = std::max_element(v.begin(), v.end());
    std::cout << "max element at: " << std::distance(v.begin(), result) << '\n';

    result = std::max_element(v.begin(), v.end(), abs_compare);
    std::cout << "max element (absolute) at: " << std::distance(v.begin(), result);
}

```
```
Q: 同时获取数组的最小值和最大值的下标
A: 
std::vector<int> v = { 3, 9, 1, 4, 2, 5, 9 };

auto result = std::minmax_element(v.begin(), v.end());

std::cout << "min element at: " << (result.first - v.begin()) << '\n';
std::cout << "max element at: " << (result.second - v.begin()) << '\n';

```
```
Q: C++ 数组求和或求乘积
A:
// accumulate
std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int sum = std::accumulate(v.begin(), v.end(), 0);
int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());

```
```
Q: 算法导论中“广度优先搜索”算法的伪代码表示
A:
BFS(G, s)
for each vertex u ∈ G.V - {s}
    u. color = WHITE
    u. d = ∞
    u.π= NIL

s. color = GRAY
s. d = 0
s.π= NIL

Q= ∅
ENQUEUE(Q, s)
while Q != ∅
    u = DEQUEUE(Q)
    for each v ∈ G.Adj[u]
        if v.color == WHITE
            v.color = GRAY
            v.d = u.d + 1
            v.π = u
            ENQUEUE(Q, s)

u.color = BLACK



```
```
Q: 算法导论中，广度优先搜索 BFS 计算出广度优先树之后，打印从s到v结点这条最短路径上的所有结点
A:

PRINT-PATH(G, s, v)
    if v == s
        print s
    elseif v.π == NIL
        print "no path from " s "to" v "exists"
    else
        PRINT-PATH(G, s, v.π)
        print v

```
```
Q: 算法导论中“深度优先搜索”DFS算法的伪代码表示（递归版）
A:
DFS(G, s)

for each vertex u ∈ G.V
    u. color = WHITE
    u.π= NIL

time = 0
for each vertex u ∈ G.V
    if u. color == WHITE
        DFS-VISIT(G, u)

DFS-VISIT(G, u)

time = time + 1

u.d = time
u.color = GRAY
for each v ∈ G.Adj[u]
        if v.color == WHITE
            v.π = u
            DFS-VISIT(G, v)

u.color = BLACK
time = time + 1
u.f = time

```
```
Q: 算法导论中“深度优先搜索”DFS算法的伪代码表示（栈版）
A:
DFS-STACK(G, s)

for each vertex u ∈ G.V
    u. color = WHITE
    u.π= NIL

time = 0
S is an empty stack
while there is a white vertex u in G do
    S.push(u)
    while S is nonempty do
        v = S.pop
        time = time + 1
        v.d = time
        for each w ∈ G.Adj[u]
            if w.color == WHITE
                w.color = GRAY
                w.π = v
                S.push(w)
            end if
        end for
        time = time + 1
        v.f = time
    
    end
end



```
```
Q: 在对无向图G进行深度优先搜索时，每条边要么是___?，要么是___?
A:  在对无向图G进行深度优先搜索时，每条边要么是树边，要么是后向边

```
```
Q: 算法导论中，拓扑排序算法
A:
TOPOLOGICAL-SORT(G)

    List<V> list;
    call DFS(G) to compute finishing times v.f for each vertex  v
        as each vertex is finished, insert it onto the front of a linked list
    
return the linked list of vertices
// 经过拓扑排序后的 结点次序 与 结点的完成时间恰好相反

```
```
Q: 前驱子图
A: 在对图进行搜索时，搜索过的边和结点形成的图。显然，前驱子图的边，只是原图边的一部分

```
```
Q: 有向图无环等价于？
A: DFS 深度优先搜索不产生“后向边”

```
```
Q: 拓扑排序
A: DFS 深度优先搜索完成之后。按照完成时间从大到小的顺序对结点排序。

```
```
Q: 强连通分量
A: 通过把图中有环的结点当作一个大的结点，把有环图变成无环图。每个大结点就是一个强连通分量

```
```
Q: 最小生成树
A: 选择图的一部分边，无环，能连通所有结点，并且各个边的权重和最小。这是一棵树。

```
```
Q: Prim 算法（大白话解释）
A: 
1. 任意选一点，在与它相邻的边中，权值最小的边加入集合Set
2. 遍历集合Set中所有的边的“结点”，选择与这些结点相邻的“边”当中权值最小的，加入集合Set，但是不能构成环
3. 重复2，直到集合Set中已经包含所有的结点

```
```
Q: Kruskal 算法
A: 
1. 把边按权值大小排序
2. 按顺序加入到集合Set中，但是不能构成环
3. 重复2，直到集合Set中已经包含所有的结点

```
```
Q: 数组求和
A:
#include <numeric>
std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int sum = std::accumulate(v.begin(), v.end(), 0);

```
```
Q: 数组求乘积
A:
#include <numeric>
std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
```
