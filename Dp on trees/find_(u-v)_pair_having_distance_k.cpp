#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define for0(i,n) for(long long int i=0;i<n;i++)
#define vi vector<long long int>
#define pb push_back
#define sz(x) sizeof(x)
#define vec(n,x) vector<long long int>v(n,x)
const ll INF = 1e18;
const ll MOD = 1000000007;
#define hi  ll tests; cin>>tests; while(tests--)
#define all(x) x.begin(),x.end()
#define readv(vec) for(auto &x:vec){cin>>x;}
#define PHI M_PI
#define graph long long int V;cin>>V;vector<long long int>adj[V];long long int e;for(long long int i=0;i<e;i++){long long int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);}
#define printv(vec) for(auto x:vec){cout<<x<<' ';}cout<<endl;
#define sortasc(vec) sort(all(vec));
#define sortdes(vec) sort(vec.rbegin(),vec.rend());
#define  setpre(x)   cout<<fixed<<setprecision(10)<<x<<endl
#define kick cout <<'C'<<'a'<<'s'<<'e'<<' '<<'#'<< k << ':'<<' '
vector<ll> sieve(long long int n) {long long int*arr = new long long int[n + 1](); vector<ll> vect; for (long long int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (long long int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
bool pal(string s){long long int i = 0;long long int j = s.size() - 1;while (i < j){if (s[i] != s[j]){return false;}i++;j--;}return true;}
ll op1(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll op2(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll op3(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
long long int powerexpo(long long int x,long long int y,long long int p){long long int res = 1;x = x % p; if (x == 0) return 0;while (y > 0){if (y & 1){res = (res*x) % p;}y = y>>1;x = (x*x) % p;}return res;}
ll C(ll a , ll b) { return (a+b-1)/b ;}
struct unionfind{
long long int n;
vector<long long int>rank;
vector<long long int>parent;
unionfind(long long int n){
rank.resize(n);
fill(rank.begin(),rank.end(),0);
parent.resize(n);
for(long long int i=0;i<n;i++){
parent[i]=i;
}}
long long int find(long long int node){if(node==parent[node]){return node;}else{return parent[node] = find(parent[node]);}}
bool Union(long long int u,long long int v){u = find(u);v = find(v);if(u==v){return false;}if(rank[u]<rank[v]){parent[u] = v;}else if(rank[u]>rank[v]){parent[v]=u;}else{parent[v]=u;rank[u]++;}return true;}};
//code by CasioFx-69
long long int dp1[50001][501];
long long int dp2[50001][501];
void dfs1(vector<long long int>adj[],long long int src,long long int parent,long long int k){
    for(auto &i:adj[src]){
        if(i!=parent){
            dfs1(adj,i,src,k);
        }
    }
    dp1[src][0]=1;
    for(long long int i=1;i<=k;i++){
        for(auto &it:adj[src]){
            if(it!=parent){
                dp1[src][i]+=dp1[it][i-1];
            }
        }
    }
}
void dfs2(vector<long long int>adj[],long long int src,long long int parent,long long int k){
    for(long long int i=0;i<=k;i++){
        dp2[src][i] = dp1[src][i];
    }
    if(parent!=-1){
        dp2[src][1]+=dp1[parent][0];
        for(long long int i=2;i<=k;i++){
            dp2[src][i]+=dp2[parent][i-1];
            dp2[src][i]-=dp1[src][i-2];
        }
    }
    for(auto &i:adj[src]){
        if(i!=parent)
        dfs2(adj,i,src,k);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n;
    cin>>n;
    long long int k;
    cin>>k;
    vector<long long int>adj[n];
    for(long long int i=0;i<n-1;i++){
        long long int x,y;
        cin>>x>>y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));
    dfs1(adj,0,-1,k);
    dfs2(adj,0,-1,k);
    long long int ans=0;
    for(long long int i=0;i<n;i++){
        ans+=dp2[i][k];
    }
    cout<<ans/2<<endl;
     return 0;
}
