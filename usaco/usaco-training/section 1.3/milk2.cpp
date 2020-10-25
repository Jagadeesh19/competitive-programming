/*
	ID:yeturu.1 
	LANG: C++11
	TASK: milk2 
*/




#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ar array



template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}


void solve(){
	fstream cin("milk2.in",std::ios::in),cout("milk2.out",std::ios::out);
	
	int n;
	cin>>n;

	vector<ar<int,2>> a(n);

	for(int i=0;i<n;++i){
		cin>>a[i][0]>>a[i][1];
	}

	sort(a.begin(),a.end());

	int atleast=0;
	int gap=0;
	for(int i=0;i<n;++i){
		int val=a[i][1]-a[i][0];
		int ind=i;
		for(int j=i+1;j<n;++j){
			if (a[ind][1]<a[j][0]) {
				val=a[ind][1]-a[i][0];
				break;
			}
				
			if (a[ind][1]<a[j][1]) {
				ind=j;	
			}
		}
		atleast=max(atleast,val);
	}

	int i=0;
	while(i<n){
		int val=0;
		int ind=i;
		bool over=1;
		for(int j=i+1;j<n;++j){
			if (a[ind][1]<a[j][0]) {
				val=a[j][0]-a[ind][1];
				i=j;
				over=false;
				break;
			}
				
			if (a[ind][1]<a[j][1]) {
				ind=j;	
			}
		}
		gap=max(gap,val);
		if (over) break;
	}

	cout<<atleast<<' ';
	cout<<gap<<endl;
	
}

int32_t main(){
	solve();
}
