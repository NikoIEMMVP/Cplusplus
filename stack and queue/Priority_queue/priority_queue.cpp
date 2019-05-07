#include <iostream>
#include <queue>
using namespace std;


int main()
{
    priority_queue<int> pq;
    pq.push(100);
    pq.push(7);
    pq.push(1);
    pq.push(999);

    while(!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}
