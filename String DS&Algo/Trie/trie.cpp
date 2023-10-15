#include <bits/stdc++.h>
using namespace std;

class Trie
{
    public:
    int EoW;
    Trie* children[26];

    Trie()
    {
        EoW=0;
        for(int i=0;i<26;i++){
            this->children[i]=NULL;
        }
    }
    void insert(Trie* root, string s)
    {
        Trie* tmp = root;
        for(int i=0;i<s.size();i++){
           int ind = s[i]-'A';
           if(tmp->children[ind]==NULL)
                tmp->children[ind]=new Trie();
           tmp=tmp->children[ind];
        }
        tmp->EoW=tmp->EoW+1;
        cout<<tmp->EoW<<endl;
    }
    bool search(Trie* root, string key)
    {
        Trie* pCrawl = root;

        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'A';
            if (!pCrawl->children[index])
                return false;

            pCrawl = pCrawl->children[index];
        }

        return (pCrawl->EoW);
    }
    Trie* searchF(Trie* root, string key)
    {
        Trie* pCrawl = root;

        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'A';
            if (!pCrawl->children[index])
                return NULL;

            pCrawl = pCrawl->children[index];
        }

        return pCrawl;
    }
    void printTrie(Trie* cur,string s="")
    {
        if(cur->EoW) cout<<s<<endl;
        for(int i=0;i<26;i++){
           if(cur->children[i]!=NULL)
           {
               char c=(char)(i+'A');
               //cout<<c<<" ";
               printTrie(cur->children[i], s+c);
           }
        }
    }

    void printTrieBack(Trie* cur,string s="")
    {
        if(cur->EoW) cout<<s<<endl;
        for(int i=25;i>=0;i--){
           if(cur->children[i]!=NULL)
           {
               char c=(char)(i+'A');
               //cout<<c<<" ";
               printTrie(cur->children[i], s+c);
           }
        }
    }
    void printMore(Trie* cur, string s="")
    {
        if(cur->EoW >1) cout<<s<<" is there more than once\n";
        for(int i=0;i<26;i++){
           if(cur->children[i]!=NULL)
           {
               char c=(char)(i+'A');
               //cout<<c<<" ";
               printMore(cur->children[i], s+c);
           }
        }
    }

    bool isEmpty(Trie* root)
    {
        for (int i = 0; i < 26; i++)
            if (root->children[i])
                return false;
        return true;
    }
    Trie* dlt(Trie* root, string s, int d=0)
    {
        if(!root) return NULL;
        if(isEmpty(root)){ delete (root); root=NULL; return NULL;}
        if(d==s.size())
        {
            if(root->EoW) root->EoW=0;
            return root;
        }
        int ind=s[d]-'A';
        root->children[ind]=dlt(root->children[ind],s,++d);
        //if(isEmpty(root) && !root->EoW) {delete (root);root=NULL;}
        return root;
    }
};

int main()
{
    Trie newT, *root=new Trie();
    newT.insert(root,"MIST");
    newT.insert(root,"MIT");
    newT.insert(root,"BUP");
    newT.insert(root,"MIST");
    newT.insert(root,"BUP");
    newT.printTrie(root); cout<<endl;
    //newT.dlt(root,"BUP");
    newT.printTrieBack(root); cout<<endl;
    //newT.search(root, "MIST")?cout<<"Found\n":cout<<"Not Found\n";
    //newT.search(root, "BUP")?cout<<"Found\n":cout<<"Not Found\n";
    string s;
    cout<<"Enter Input: ";cin>>s;
    Trie* NTS=newT.searchF(root,s);
    newT.printTrie(NTS,s);
    newT.printMore(root);
    return 0;
}
