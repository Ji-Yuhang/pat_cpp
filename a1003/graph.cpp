#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

void fake_input(int& city_count, int& road_count, int& current_city_id, int& target_city_id, map<int, int> &teams, map<pair<int, int>, int> &citys)
{
    city_count = 5;
    road_count = 6;
    current_city_id = 0;
    target_city_id = 2;
    teams[0] = 1;
    teams[1] = 2;
    teams[2] = 1;
    teams[3] = 5;
    teams[4] = 3;
    citys.insert(make_pair(make_pair(0, 1), 1));
    citys.insert(make_pair(make_pair(0, 2), 2));
    citys.insert(make_pair(make_pair(0, 3), 1));
    citys.insert(make_pair(make_pair(1, 2), 1));
    citys.insert(make_pair(make_pair(2, 4), 1));
    citys.insert(make_pair(make_pair(3, 4), 1));

}

void cin_input(int& city_count, int& road_count, int& current_city_id, int& target_city_id, map<int, int> &teams, map<pair<int, int>, int> &citys)
{
    cin >> city_count >> road_count >> current_city_id >> target_city_id;

    for (int i = 0; i < city_count; ++i) {
        int city_id = i;
        int city_team_member_count = 0;
        cin >> city_team_member_count;
        teams[city_id] = city_team_member_count;
    }
    // <int, map<int, int> >
    // <city_a, map<city_b, length> >
    //map<int, map<int, int> > citys;
    for (int i = 0; i < road_count; ++i) {
        int city_a = 0;
        int city_b = 0;
        int length_between_city_a_b = 0;

        cin >> city_a >> city_b >> length_between_city_a_b;

        pair<int, int> city_pair = make_pair(city_a, city_b);
        citys.insert(make_pair(city_pair, length_between_city_a_b));

        //pair<int, int> same_pair = make_pair(city_b, city_a);
        //citys.insert(make_pair(same_pair, length_between_city_a_b));
    }
}

class Node
{
public:
    Node();
    Node(int id, int member_count);
    ~Node();
    bool operator==(const Node& other);
    bool operator<(const Node& other);
    int id() const { return id_; }
    int member_count() const { return member_count_; }
    bool is_valid() const { return id_ != -1; }
private:
    int member_count_;
    int id_;
};

Node::Node()
    :id_(-1)
    , member_count_(-1)
{
}

Node::Node(int id, int member_count)
    : id_(id)
    , member_count_(member_count)
{
}

Node::~Node()
{
}

bool Node::operator==(const Node& other)
{
    return this->id_ == other.id_;
}
bool Node::operator<(const Node & other)
{
    return this->id_ < other.id_;
}
class Edge
{
public:
    Edge();
    Edge(int a_id, int b_id, int length);
    Edge(const Node& a, const Node& b, int length);
    ~Edge();
    int length() const { return length_; }
    bool is_include_node(const Node& node);
    Node other_node(const Node& node);

private:
    Node a_;
    Node b_;
    int a_id_;
    int b_id_;
    int length_;
};

Edge::Edge()
    :a_id_(-1)
    , b_id_(-1)
{
}

Edge::Edge(int a_id, int b_id, int length)
    : a_id_(a_id)
    , b_id_(b_id)
    , length_(length)
{
}

Edge::Edge(const Node & a, const Node & b, int length)
    :a_(a)
    , b_(b)
    , length_(length)
{
    a_id_ = a.id();
    b_id_ = b.id();
}

Edge::~Edge()
{
}

bool Edge::is_include_node(const Node & node)
{
    if (a_id_ == node.id() || b_id_ == node.id()) return true;
    return false;
}

Node Edge::other_node(const Node& node)
{
    if (is_include_node(node)) {

        if (a_ == node) return b_;
        if (b_ == node) return a_;

    }

    return Node(-1, -1);
}


class Graph
{
public:
    Graph(int city_count, int road_count, int current_city_id, int target_city_id, const map<int, int> &teams, const map<pair<int, int>, int> &citys);
    ~Graph();
    vector<Node> nearby_nodes(const Node& node);
    Node find_node(int id);
    vector<vector<Node> > find_path();
    Edge find_edge(const Node& a, const Node& b);
    //bool is_edge_have_node(const Node& node);
private:
    vector<Node> nodes_;
    vector<Edge> edges_;
    int source_id_;
    int target_id_;

};

Graph::Graph(int city_count, int road_count, int current_city_id, int target_city_id, const map<int, int> &teams, const map<pair<int, int>, int> &citys)
    :source_id_(current_city_id)
    , target_id_(target_city_id)
{
    map<int, int>::const_iterator it = teams.begin();
    for (; it != teams.end(); it++) {
        Node node(it->first, it->second);
        nodes_.push_back(node);
    }
    map<pair<int, int>, int>::const_iterator city_it = citys.begin();
    for (; city_it != citys.end(); city_it++) {
        Node a = find_node(city_it->first.first);
        Node b = find_node(city_it->first.second);
        //Edge edge(city_it->first.first, city_it->first.second, city_it->second);
        Edge edge(a, b, city_it->second);
        edges_.push_back(edge);
    }
}

Graph::~Graph()
{
}

vector<Node> Graph::nearby_nodes(const Node& node)
{
    vector<Node> result;
    for (size_t i = 0; i < edges_.size(); ++i) {
        Edge& edge = edges_[i];
        if (edge.is_include_node(node)) {
            Node other_node = edge.other_node(node);
            result.push_back(other_node);
        }
    }
    return result;
}

Node Graph::find_node(int id)
{
    //find(nodes_.begin(), nodes_.end(), id);
    for (size_t i = 0; i < nodes_.size(); i++)
    {
        const Node& node = nodes_[i];
        if (node.id() == id) return Node(node);
    }
    return Node(-1, -1);
}

vector<vector<Node> > Graph::find_path()
{
    //vector<Node>
    Node source_node = find_node(source_id_);
    Node target_node = find_node(target_id_);
    stack<Node> stack_nodes;

    vector<Node> path;
    vector<vector<Node> > paths;
    path.push_back(source_node);
    if (source_node == target_node) {
        paths.push_back(path);
        return paths;
    }
    // initialize stack;
    {
        stack_nodes.push(Node());
        vector<Node> nodes = nearby_nodes(source_node);
        for (size_t i = 0; i < nodes.size(); i++)
        {
            stack_nodes.push(nodes[i]);
        }
    }

    while (!stack_nodes.empty())
    {
        // show path
        if (false) {
            cout << "path: ";
            for (size_t j = 0; j < path.size(); j++)
            {
                cout << path[j].id() << " ";

            }
            cout << endl;
        }

        // show stack
        if (false) {
            stack<Node> copy = stack_nodes;
            vector<Node> temp;
            while (!copy.empty()) {
                Node node = copy.top();
                temp.insert(temp.begin(), node);
                copy.pop();
            }
            cout << "stack: ";
            for (size_t i = 0; i < temp.size(); i++)
            {
                cout << temp[i].id() << " ";
            }
            cout << endl;

        }

        const Node node = stack_nodes.top();
        stack_nodes.pop();
        if (!node.is_valid()) {
            path.pop_back();
            continue;
        }
        vector<Node>::iterator path_it = find(path.begin(), path.end(), node);
        if (path_it != path.end()) {
            path.erase(path_it, path.end());
        }
        path.push_back(node);

        if (path.back() == target_node) {
            paths.push_back(path);

            path.pop_back();
        }
        else {
            stack_nodes.push(Node());
            vector<Node> near_nodes = nearby_nodes(node);
            for (size_t i = 0; i < near_nodes.size(); i++)
            {
                vector<Node>::iterator path_it = find(path.begin(), path.end(), near_nodes[i]);
                // avoid loop
                if (path_it == path.end()) {
                    stack_nodes.push(near_nodes[i]);
                }

            }
            //vector<Node>::iterator path_it = find(path.begin(), path.end(), node);
            //if (path_it != path.end()) {
            //    path.erase(path_it, path.end());
            //}
            //path.push_back(node);
        }

    }
    // show path
    if (false) {
        for (size_t i = 0; i < paths.size(); i++)
        {
            vector<Node> path = paths[i];
            for (size_t j = 0; j < path.size(); j++)
            {
                cout << path[j].id() << "-";

            }
            cout << endl;
        }

    }
    // show stack
    if (false) {
        stack<Node> copy = stack_nodes;
        vector<Node> temp;
        while (!copy.empty()) {
            Node node = copy.top();
            temp.insert(temp.begin(), node);
            copy.pop();
        }
        for (size_t i = 0; i < temp.size(); i++)
        {
            cout << temp[i].id() << "-";
        }
        cout << endl;

    }
    return paths;
}

Edge Graph::find_edge(const Node & a, const Node & b)
{
    for (size_t i = 0; i < edges_.size(); ++i) {
        Edge& edge = edges_[i];

        if (edge.is_include_node(a) && edge.is_include_node(b)) {
            return edges_[i];
        }
    }
    return Edge();
}

int main()
{
    int city_count = 0;
    int road_count = 0;
    int current_city_id = 0;
    int target_city_id = 0;
    map<int, int> teams;
    map<pair<int, int>, int> citys;

    bool fake = false;
    if (fake) {
        fake_input(city_count, road_count, current_city_id, target_city_id, teams, citys);
    }
    else {
        cin_input(city_count, road_count, current_city_id, target_city_id, teams, citys);
    }
    Graph graph(city_count, road_count, current_city_id, target_city_id, teams, citys);
    {
        vector<vector<Node> > paths = graph.find_path();
        multimap<int, vector<Node> > length_of_paths;
        int min_length = 0;
        for (size_t i = 0; i < paths.size(); i++)
        {
            int length = 0;
            vector<Node>& path = paths[i];
            for (size_t j = 0; j < path.size() - 1; j++)
            {
                Edge edge = graph.find_edge(path[j], path[j + 1]);
                length += edge.length();
            }

            length_of_paths.insert(make_pair(length, paths[i]));

            if (min_length == 0) {
                min_length = length;
            }
            else {
                min_length = min(min_length, length);
            }
        }
        int count = 0;
        int max_member = 0;
        multimap<int, vector<Node> >::iterator it = length_of_paths.begin();
        for (; it != length_of_paths.end(); it++) {
            if (it->first == min_length) {
                count++;
                int member = 0;
                for (size_t i = 0; i < it->second.size(); i++)
                {
                    const Node& node = it->second.at(i);
                    member += node.member_count();
                }

                max_member = max(max_member, member);

            }

        }

        cout << count << " " << max_member;



    }
    //system("pause");

    return 0;
}
