#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

// 1004 Counting Leaves

struct Node{
    int id;
    int parent_id;
    int layer;
    vector<int> children_ids;
    Node():layer(-1),parent_id(-1){}
};

int main()
{
    int count(0);
    int non_leaf_count(0);
    int root_id = 1;

    cin >> count >> non_leaf_count;

    map<int, Node*> nodes;

    {

        Node* root = new Node;
        root->id = root_id;
        nodes[root_id] = root;
    }

    if (non_leaf_count == 0){

    }


    for(int i = 0; i < non_leaf_count; ++i){
        int id;
        int children_count(0);
        Node* node(nullptr);

        cin >> id >> children_count;

        auto it = nodes.find(id);
        if (it != nodes.end()){
            node = it->second;
        } else {
            // where is this node's parent?
            //assert(0);
            node = new Node;
            node->id = id;
            nodes[id] = node;
        }


        for(int j = 0; j < children_count; ++j){
            int child_id;
            cin >> child_id;
            Node* child = new Node;
            child->id = child_id;
            child->parent_id = id;
            node->children_ids.push_back(child_id);

            nodes[child_id] = child;
        }
    }

    auto it = nodes.find(root_id);
//    if (it == nodes.end()){
//        cout << "0";
//        return 0;
//    }

    vector<Node*> zero_level_nodes;

    Node* root = it->second;
    zero_level_nodes.push_back(root);

    int level = 0;
    map<int, vector<Node*> > level_nodes;
    map<int, int> result;


    level_nodes[level] = zero_level_nodes;

    while(level_nodes.find(level) != level_nodes.end() && !level_nodes[level].empty()){
        vector<Node*> current_level = level_nodes[level];
        vector<Node*> next_level;

        result[level] = 0;

        for(auto node: current_level){
             if (node->children_ids.empty()){
                result[level] += 1;

            } else {
                for(auto child_id: node->children_ids){
                    Node* child = nodes[child_id];
                    next_level.push_back(child);

                }
            }

        }

        level++;
        if (!next_level.empty()){
            level_nodes[level] = next_level;
        }
    }


    cout << result[0];
    for ( int i = 1; i < level; ++i){
        cout << " " <<result[i];
    }

    if (false)
    {
        cout <<"\n";
        for(auto pair: result){
            cout << pair.first<<" : "<< pair.second;
            cout <<"\n";
        }

        for(auto pair: level_nodes){
            cout << pair.first<<" : ";
            for (auto node: pair.second){
                cout << " "<< node->id;
            }
            cout <<"\n";
        }
    }


    for(auto& node: nodes){
        delete node.second;
        node.second = nullptr;
    }


    return 0;
}
