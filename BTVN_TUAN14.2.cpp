#include <iostream>
#include <queue>
using namespace std;

#define MAX 11

string city[MAX] = {
    "Ha Noi",
    "Hai Duong",
    "Phu Ly",
    "Hoa Binh",
    "Son Tay",
    "Thai Nguyen",
    "Bac Ninh",
    "Hung Yen",
    "Hai Phong",
    "Bac Giang",
    "Uong Bi"
};

int a[MAX][MAX] = {0};
void addEdge(int u, int v)
{
    a[u][v] = 1;
    a[v][u] = 1;
}

void BFS(int start)
{
    bool visited[MAX] = {false};
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << city[u] << endl;
        for(int v = 0; v < MAX; v++)
        {
            if(a[u][v] == 1 && !visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    addEdge(0,1);
    addEdge(0,2);
    addEdge(0,3);
    addEdge(0,4);
    addEdge(0,5);
    addEdge(0,6);
    addEdge(1,7);
    addEdge(1,8);
    addEdge(2,7);
    addEdge(6,9);
    addEdge(6,10);
    addEdge(9,10);
    addEdge(8,10);
    cout << "BFS tu Ha Noi:\n\n";
    BFS(0);
    return 0;
}
