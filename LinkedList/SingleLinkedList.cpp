#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
   
using namespace std;
   
typedef long long ll;
typedef long double ld;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forn1(i,e) for(ll i = 1; i <= e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
   
  
struct LinkedList
{
		int data;
		LinkedList* next;
	// public:
	// 	LinkedList(int x)
	// 	{
	// 		this->data = x;
	// 		this->next = NULL;
	// 	}
};	
LinkedList* head = new LinkedList();
void insert(int x, int n=1)
{
	LinkedList* tmp = new LinkedList();
	tmp->data = x;
	if(n==1)
	{
		tmp->next = head;	//set current head's pos as the next node
		head = tmp; 	//make the new node the head
		return;
	}
	LinkedList* tmp1 = new LinkedList();
	LinkedList* tmp2 = new LinkedList();

	//traverse to assign tmp1 to n-th node (n-1 iterations to get to n-1th node and get it's *next)
	tmp1 = head; // assign tmp1 to head to traverse all nodes
	forn(i,n-2) //since there's n-1 iteration and we're already at head, so n-2 iterations needed 
	{
		tmp1 = tmp1->next; //go to the next node of tmp1
	}
	tmp->next = tmp1->next;
	tmp1->next = tmp;
}	
void del(int n)
{
	LinkedList* tmp;
	tmp = head;
	if(n==1)
	{
		head = tmp->next;
		delete tmp;
		return;
	}
for(int i = 0; i < n-2;++i)
		tmp = tmp->next; //prev
LinkedList* tmp1 = new LinkedList();
tmp1 = tmp->next; //n-th node
tmp->next = tmp1->next; //point (n-1)th node to (n+1)th node
delete tmp1;
}
//iterative:
void print(LinkedList* tmp)
{
	cout << "The List: ";
	while(tmp != NULL)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << ln;
}
void print1(LinkedList* tmp)
{
	if(tmp==NULL){cout <<"\n";return;}
	cout << tmp->data << " ";
	print1(tmp->next);
}
void printReverse(LinkedList* tmp)
{
	if(tmp==NULL){cout <<"\n";return;}
	printReverse(tmp->next);
	cout << tmp->data << " ";
}
//iterative
void Reverse(LinkedList* &head)
{
	LinkedList *prev,*current,*nxt;
	current = head; prev=NULL;
	while(current!=NULL)
	{
		nxt = current->next; //next node of current
		current->next = prev; //set current's next to be *prev, as we're reversing
		prev = current; //now update prev to move on for iteration
		current = nxt; //also update current
	}
	head = prev; //as node's are reversed, last node becomes the head
}

int main()
{
    fastio
    head = NULL;	//to prevent it from having a garbage value
    LinkedList* tmp = new LinkedList();

    insert(2,1);
    insert(4,2);
    insert(5,3);
    insert(6,1);
    insert(6,3);
    del(1);
    print1(head);
    Reverse(head);
    print1(head);
    return 0;
}