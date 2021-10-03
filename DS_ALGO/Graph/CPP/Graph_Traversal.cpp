// Graph insertion, and BFS and DFS Traversal

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

class Node
{
public:
    int data;
    Node *next;
    Node(int d = (int)NULL)
    {
        this->data = d;
        this->next = NULL;
    }
};

class Graph
{
public:
    int t_edges, t_nodes;
    Node *list;

    Graph(int n, int e)
    {
        this->t_nodes = n, this->t_edges = e;
        this->list = new Node[n + 1];
    }
    void BFS(int);
    void DFS(int);
    void DFSRecv(int, bool[]);

    void addEdge(int src, int des)
    {
        //*****     For src Node     *****//

        Node *c1 = (list + src)->next;
        if (c1 == NULL)
        {
            Node *n_node1 = new Node(src);
            (list + src)->next = n_node1;
            Node *n_node2 = new Node(des);
            n_node1->next = n_node2;
        }
        else
        {
            while (c1->next != NULL)
            {
                c1 = c1->next;
            }
            Node *n_node = new Node(des);
            c1->next = n_node;
        }

        //*****     For des Node     *****//

        c1 = (list + des)->next;

        if (c1 == NULL)
        {
            Node *n_node1 = new Node(des);
            (list + des)->next = n_node1;
            Node *n_node2 = new Node(src);
            n_node1->next = n_node2;
        }
        else
        {
            while (c1->next != NULL)
            {
                c1 = c1->next;
            }
            Node *n_node = new Node(src);
            c1->next = n_node;
        }
    }
};

void Graph::BFS(int sp)
{
    bool *visited = new bool[t_nodes + 1];
    for (int i = 0; i < t_nodes + 1; i++)
        visited[i] = false;

    queue<Node *> que;

    que.push((list + sp)->next);
    visited[sp] = true;

    while (!que.empty())
    {
        Node *tmp1 = que.front();
        que.pop();

        cout << tmp1->data << " ";
        Node *tmp2 = (list + tmp1->data)->next;
        while (tmp2 != NULL)
        {
            if (visited[tmp2->data] == false)
            {
                que.push(tmp2);
                visited[tmp2->data] = true;
            }
            tmp2 = tmp2->next;
        }
    }
}

// void Graph::DFS(int sp)
// {
//     bool *visited = new bool[t_nodes + 1];
//     for (int i = 0; i < t_nodes + 1; i++)
//         visited[i] = false;
//     cout << "dfs" << endl;
//     stack<int> stk;
//     visited[sp] = true;
//     stk.push(sp);

//     Node *it = (list + sp)->next;
//     while (!stk.empty())
//     {
//         sp = stk.top();
//         stk.pop();
//         if (visited[sp])
//             continue;

//         visited[sp] = true;
//         cout << sp << " ";
//         while (it != NULL)
//         {
//             if (!visited[it->data])
//             {
//                 stk.push(it->data);
//             }
//         }
//     }
// }

void Graph::DFSRecv(int sp, bool visited[])
{
    cout << sp << " ";
    visited[sp] = true;
    Node *tmp1 = (list + sp)->next;
    while (tmp1 != NULL)
    {
        if (visited[tmp1->data] == false)
        {
            DFSRecv(tmp1->data, visited);
        }
        tmp1 = tmp1->next;
    }
}

void Graph::DFS(int sp)
{
    bool *visited = new bool[t_nodes + 1];
    for (int i = 0; i < t_nodes + 1; i++)
        visited[i] = false;

    for (int i = 1; i < t_nodes; i++)
    {
        if (visited[sp] == false)
        {
            this->DFSRecv(sp, visited);
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, sp;
    cin >> n >> m;

    Graph gph(n, m);

    for (int i = 1; i <= m; i++)
    {
        int ele1, ele2;
        cin >> ele1 >> ele2;
        gph.addEdge(ele1, ele2);
    }
    cin >> sp;
    gph.BFS(sp);

    cout << endl;

    gph.DFS(sp);

    return 0;
}
