/*
	ID:yeturu.1 
	LANG: C++11
	TASK: gift1 
*/




#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ar array



template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}


void solve(){
	fstream cin("gift1.in",std::ios::in),cout("gift1.out",std::ios::out);
	int n;
	cin>>n;
	map<string,int> mp;
	vector<string> v(n);

	for(int i=0;i<n;++i){
		cin>>v[i];
		mp[v[i]]=0;
	}

	for(int i=0;i<n;++i){
		string s;
		cin>>s;

		int amt,m;
		cin>>amt>>m;

		for(int j=0;j<m;++j){
			string t;
			cin>>t;
			
			mp[t]+=amt/m;
		}

		if (m)
			mp[s]-=m*(amt/m);
	}

	for(int i=0;i<n;++i){
		cout<<v[i]<<' '<<mp[v[i]]<<'\n';
	}
}

int32_t main(){
	solve();
}
