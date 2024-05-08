#include <bits/stdc++.h>
using namespace std;
   
typedef long long ll;
typedef long double ld;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i <= e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"

struct AVL
{
	AVL *left,*right;
	int height,element;
	AVL(){}
	AVL(int x, AVL *l, AVL *r){element=x;left=l;right-r;}
};
AVL* root = new AVL();

int height(AVL *u)
{
	return (u==NULL)? -1 : u->height;
}

void LeftRotation(AVL *u)
{
	AVL* v = u->right;
	u->right = v->left;
	v->left = u;
	u->height = max(height(u->right)+1, height(u->right));
	v->height = max(height(v->right)+1, height(v->right));
	u=v;
}
void RightRotation(AVL *u)
{
	AVL* v = u->left;
	u->left = v->right;
	v->right = u;
	u->height = max(height(u->left)+1, height(u->left));
	v->height = max(height(v->left)+1, height(v->left));
	u=v;
}
void RLRotation(AVL *u)
{
	RightRotation(u->right);
	LeftRotation(u);
}
void LRRotation(AVL *u)
{
	LeftRotation(u->left);
	LeftRotation(u);
}

void balance(AVL* u) //LR, RL is possible for both sides, while LL,RR is only possible on specific sides
{
	if((u->left==NULL && u->right==NULL) || u==NULL) return;
	else if(height(u->left)-height(u->right)>1)
	{
		if(height(u->left->right)> height(u->left->left)) RLRotation(u->left);
		else RightRotation(u);
	}
	else if(height(u->right)-height(u->left)>1)
	{
		if(height(u->right->left)> height(u->right->right)) LRRotation(u->right);
		else LeftRotation(u);
	}
	else max(height(u->left),height(u->right))+1;
}
void insert(int x, AVL *u=root)
{
	if(u==NULL) u = new AVL(x,NULL,NULL);
	if(x>= u->element) insert(x, u->right);
	if(x < u->element) insert(x, u->left);
	balance(u);
}


int main()
{
    fastio
    
    return 0;
}