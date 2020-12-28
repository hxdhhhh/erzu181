#include <iostream>
using namespace std;

struct Node
{
    int n;
    Node *next;
};
int fun(int N,int K,int M){
	int c;
    Node *head, *node, *p;
    head = new Node;
    head->next = NULL;
    p = head;
    int num = N, count = 0;
    for (size_t i = 0; i < N; i++)
    {
        node = new Node;
        node->n = K;
        p->next = node;
        p = node;
        K++;
        K = (K - 1) % N + 1;
    }
    p->next = head->next;
    delete head;
    while (num)
    {
        if (++count == M)
        {
            count = 0;
            Node *t = p->next->next;
            c=p->next->n ;
            delete p->next;
            p->next = t;
            num--;
        }
        else
            p = p->next;
    }
    return c;
}
int main()
{
    int N,K,M,kingnum;
    cin >> N >> K >> M;
    kingnum = fun(N,K,M);
	cout<<"ºïÍõµÄ±àºÅÎª"<<kingnum<<endl;
    return 0;
}
