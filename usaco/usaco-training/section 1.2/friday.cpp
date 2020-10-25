/*
	ID:yeturu.1 
	LANG: C++11
	TASK: friday 
*/




#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ar array



template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}


void solve(){
	fstream cin("friday.in",std::ios::in),cout("friday.out",std::ios::out);
	int n;
	cin>>n;

	vector<int> a{ 31,28,31,30,31,30,31,31,30,31,30,31};

	vector<int> ans(7);
	int year=1900;
	int day=2;
	while(n--){
		for(int i=0;i<12;++i){
			int nof=a[i];
			bool leap=0;
			if (year%100!=0){
				leap=year%4==0;
			}
			else{
				leap=year%400==0;
			}
			if (leap && i==1) nof++;
			for(int j=1;j<=nof;++j){
				if (j==13){
					ans[day]++;
				}
				day=(day+1)%7;
			}
		}
		year++;
	}

	for(int i=0;i<6;++i){
		cout<<ans[i]<<' ';
	}
	cout<<ans[6]<<'\n';

}

int32_t main(){
	solve();
}
