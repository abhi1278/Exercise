/*
    Sample queue program
    Level order traversal of 
    binary tree
*/
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

// traverse
vector<vector<int>> level_order(Node *root)
{
    queue<Node *> qu;
    qu.push(root);
    vector<vector<int>> res;

    // traverse
    while (!qu.empty())
    {
        int level_size = qu.size();
        vector<int> temp;

        for (int i = 0; i < level_size; i++)
        {
            Node *cur = qu.front();
            qu.pop();
            temp.push_back(cur->data);

            if (cur->left)
                qu.push(cur->left);
            if (cur->right)
                qu.push(cur->right);
        }

        res.push_back(temp);
    }

    return res;
}

// Driver code
int main()
{

    Node *root = new Node(40);
    root->left = new Node(20);
    root->right = new Node(60);
    root->left->left = new Node(10);
    root->left->right = new Node(30);
    root->right->left = new Node(50);
    root->right->right = new Node(70);

    // fn call
    vector<vector<int>> res = level_order(root);

    for (auto vec : res)
    {
        for (auto val : vec)
        {
            cout << val << " ";
        }
        cout << "\n";
    }
}
