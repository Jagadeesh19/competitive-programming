/*
	ID:yeturu.1 
	LANG: C++11
	TASK: beads 
*/




#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ar array



template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}


void solve(){
	fstream cin("beads.in",std::ios::in),cout("beads.out",std::ios::out);
	
	int n;
	cin>>n;
	
	string s;
	cin>>s;

	int ans=0;

	for(int i=0;i<n;++i){
		
		int cnt=0;
		int j=i;

		int a=0;
		int b=0;
		while(1){
			if (s[j]=='r') a++;
			else if (s[j]=='b') b++;
			

			if(a && b) break;
			cnt++;
			if (cnt>n) break;
			j=(j-1+n)%n;

		}


		j=(i+1)%n;
		a=0;
		b=0;

		while(1){
			if (s[j]=='r') a++;
			else if (s[j]=='b') b++;
			

			if(a && b) break;
			cnt++;
			if (cnt>n) break;
			j=(j+1+n)%n;
		}


		if (cnt>n) cnt=n;
		ans=max(cnt,ans);


	}

	cout<<ans<<'\n';
	
}

int32_t main(){
	solve();
}
