#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
 class trie{
public:     
    trie* ary[26];
    bool eow;
    int count;
    trie(){
        for(int i=0;i<26;i++){
            ary[i]=NULL;
        }
        eow=false;
        count =0;
    }
} ;
bool insert(string str,trie* root){
    trie * temp = root;
    for(int i=0;i<str.size();i++){
        temp->count++;
        if(temp->ary[str[i]-'a']==NULL){
            temp->ary[str[i]-'a'] = new trie();
            temp = temp->ary[str[i]-'a'];
            if(i==str.size()-1){
                temp->eow=true;
            }
        }else{
           temp = temp->ary[str[i]-'a'];
            if(i==str.size()-1){
                temp->eow=true;
            } 
        }
    }
    return true;
}
int find(string str, trie* root){
    trie * temp = root;
    int count = 0;
    for(int i=0;i<str.size();i++){
        if(temp->ary[str[i]-'a']==NULL){
           return 0;
        }else{
            
            //cout << str[i]<<endl;
            
            temp = temp->ary[str[i]-'a'];
            if(i==str.size()-1){
                count +=temp->count;
                if(temp->eow) count+=1;
            }
        }
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    trie* root = new trie();
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        if(op == "add"){
            insert(contact,root);
        }else{
            cout << find(contact,root)<<endl;
        }
    }
    return 0;
}

