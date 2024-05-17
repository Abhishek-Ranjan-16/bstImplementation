#include <bits/stdc++.h>
#define nn "\n"
#define ll long long
#define pb push_back
#define pll pair<ll, ll>
#define vll vector<ll>
#define all(_obj) _obj.begin(), _obj.end()
#define fr(x, y) for (ll x = 0; x < y; x++)
#define nach_basanti                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define inp(x) \
    ll x;      \
    cin >> x;
#define inpv(v, n) \
    vll v(n);    \
    fr(i, n) cin >> v[i];
#define printv(v) fr(i, v.size()) cout << v[i] << " ";
#define yes cout << "YES"
#define no cout << "NO"
#define home return;
const ll mod = 1e9 + 7;
using namespace std;
struct node{
    ll val;
    node*left=nullptr;
    node*right=nullptr; 

    node(ll data){
        val=data;
        left=right=nullptr;
    }
};  
struct node* inorderSuccessor(struct node* node){
    struct node* curr=node;

    while(curr && curr->left)
    curr=curr->left;

    return curr;
}
struct node*deleteNode(struct node*node,ll val){
    if(!node)return node;
    if(val<node->val){
        node->left=deleteNode(node->left,val);

    }
    else if(val>node->val){
        node->right=deleteNode(node->right,val);
    }
    else{
        if(node->left==nullptr){
            struct node*temp=node->right;
            free(node);
            return temp;
        }
        else if(node->right==nullptr){
            struct node*temp=node->left;
            free(node);
            return temp;
        }

        struct node*temp=inorderSuccessor(node->right);
        node->val=temp->val;
        node->right=deleteNode(node->right,temp->val);
    } 
    return node;
}
struct node* insert(struct node*node,ll val){
    if(!node)
    return new struct node(val);

    if(node->val>val){
        node->left=insert(node->left,val);
    }
    else{
        node->right=insert(node->right,val);
    }
    return node;
}
void inorder(struct node*node){
    if(!node)return;
    inorder(node->left);
    cout<<node->val<<" ";
    inorder(node->right);
}
void solve()
{
    inp(n);
    inpv(vec,n);
    struct node* root=nullptr;

    for(auto &it:vec){
        root=insert(root,it);
    }
    inorder(root); 
    root=deleteNode(root,19);
    root=deleteNode(root,10240);
    root=deleteNode(root,32764);
    cout<<endl;
    inorder(root);  
}
int32_t main()
{
    nach_basanti;
    ll t=1;
    fr(i, t)
    {
        solve();
        cout << nn;
    }
    return 0;
}