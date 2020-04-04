#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>
using namespace std;
#define int long long
#define double long double
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 998244353
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> new_data_set;
bool isprime(int n)
	{
    	if(n==1) return true;
    	for(int i = 2;i*i<=n;i++){
    		if(n%i==0) return false;
		}
		return true;
	}
int lcm(int a,int b){
	return (a*b)/__gcd(a,b);
}
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
unsigned int factorial(unsigned int n) 
{ 
    if (n == 0) 
    return 1; 
    return n * factorial(n - 1); 
} 
//const int inf=1e17+7;
vector<int>graph[200006];
//int ans=0,child=0;
bool visited[200006]={false};
int dfs(int x){
	visited[x]=true;
	int child = 1;
	for(int i=0;i<graph[x].size();i++){
		if(!visited[graph[x][i]]){
			child+=dfs(graph[x][i]);
		}
	}
	return child;
}
int dsu[100005],s[100005];
int root(int x){
	while(dsu[x]!=x){
		x = dsu[x];
	}
	return x;
}
void uni(int x,int y){
	int p = root(x);
	int q = root(y);
	if(p==q){
		return;
	}
	else{
		if(s[p]<s[q]){
			s[q]+=s[p];
			dsu[p] = q;
		}
		else{
			s[p]+=s[q];
			dsu[q] = p;
		}
	}
}
signed main(){
	FAST
	int t;
	cin>>t;
	int temp = t;
	while(t--){
		cout<<"Case #"<<temp-t<<": ";
		int n;
		cin>>n;
		vector<pair<int,int>>v,vi;
		map<pair<int,int>,int>mp;
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			v.push_back({x,y});
			vi.push_back({x,y});
			mp[{x,y}] = i;
		}
		sort(v.begin(),v.end());
		char arr[n];
		for(int i=0;i<n;i++){
			arr[i]='J';
		}
		arr[mp[{v[0].first,v[0].second}]]='J';
		int jmx=v[0].second,cmx=0,flag=0,f=0;
		for(int i=1;i<n;i++){
			if(v[i].first>=jmx){
				arr[mp[{v[i].first,v[i].second}]]='J';
				jmx = v[i].second;
			}
			else if(f==0){
				arr[mp[{v[i].first,v[i].second}]]='C';
				cmx = v[i].second;
				f++;
			}
			else if(v[i].first>=cmx){
				arr[mp[{v[i].first,v[i].second}]]='C';
				cmx = v[i].second;
			}
			else{
				flag++;
				break;
			}
		}
		if(flag!=0){
			cout<<"IMPOSSIBLE"<<endl;
		}
		else{
			for(int i=0;i<n;i++)cout<<arr[i];
			cout<<endl;
		}
	}
}