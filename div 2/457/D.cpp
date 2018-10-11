#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
//---

const int N=100005;
const int mod=1e9+7;

int q,root[N],w,d;
string op,s;

struct Trie {
	static const int N = ::N;
	int son[N][26], _,val[N];
	int ne() { fill_n(son[_], 26, -1); val[_]=-1; return _++; }
	void ini() { _ = 0; ne(); }
	int cpy(int y) {memcpy(son[_],son[y],sizeof(son[_])); val[_]=val[y]; return _++;}
  
  	void insert(const string &s,int u,int w) {
//    int u = 0;
    	rep(i,0,sz(s)){
    		char ch=s[i];
    		int  &v = son[u][ch - 'a'];
    		if (!~v) v = ne();else v=cpy(v);
    		u = v;
    	}
    	val[u]=w;
  	}
	int find(const string &s,int u) {
    	rep(i,0,sz(s)){
    		char ch=s[i];
    		int  &v = son[u][ch - 'a'];
    		if (!~v) v = ne();else v=cpy(v);
    		u = v;
   		}
   		return val[u];		
  	}
} tree;





int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>q;
	//de((-1));
	return 0;
	rep(i,1,q+1) {
		cin>>op;
		if (op=="set") {
			cin>>s>>w;
			//root[i]=tree.ne();
			root[i]=tree.cpy(root[i-1]);
			tree.insert(s,root[i],w);	
		}
		else if (op=="remove") {
			cin>>s;
			root[i]=tree.cpy(root[i-1]);
			tree.insert(s,root[i],-1); 
		}
		else if (op=="undo") {
			cin>>d;
			root[i]=tree.cpy(root[i-1-d]); 
		}
		else {
			cin>>s;
			root[i]=tree.cpy(root[i-1]);
			int x=tree.find(s,root[i]);
			if (x==-1) cout<<-1<<endl;
			else {
				
			}
		}
		
	}
	return 0;
}

