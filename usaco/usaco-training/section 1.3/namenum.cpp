/*
	ID:yeturu.1 
	LANG: C++11
	TASK: namenum 
*/




#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ar array



template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}


void solve(){
	fstream cin("namenum.in",std::ios::in),cout("namenum.out",std::ios::out);
	string s;
	cin>>s;

	fstream fid("dict.txt",std::ios::in);
	vector<string> v;
	map<int,int> mp;
	mp['A']=2;
	mp['B']=2;
	mp['C']=2;
	mp['D']=3;
	mp['E']=3;
	mp['F']=3;
	mp['G']=4;
	mp['H']=4;
	mp['I']=4;
	mp['J']=5;
	mp['K']=5;
	mp['L']=5;
	mp['M']=6;
	mp['N']=6;
	mp['O']=6;
	mp['P']=7;
	mp['R']=7;
	mp['S']=7;
	mp['T']=8;
	mp['U']=8;
	mp['V']=8;
	mp['W']=9;
	mp['X']=9;
	mp['Y']=9;

	while(!fid.eof()){
		string line;
		fid>>line;
		v.push_back(line);
	}

	fid.close();
	bool ok=0;
	for(int i=0;i<v.size();++i){
		string cur;
		for(int j=0;j<v[i].size();++j){
			cur+=mp[v[i][j]]+'0';
		}
		if (s==cur) {
			ok=1;
			cout<<v[i]<<endl;
		}
	}

	if (!ok) {
		cout<<"NONE"<<endl;
	}



}

int32_t main(){
	solve();
}
