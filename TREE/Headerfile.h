#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <process.h>
#include <iomanip>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <fstream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
    ~Node();
};

void printvector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}