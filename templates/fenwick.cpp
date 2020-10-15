struct Fenwick{
	vector<int> bit;
	int n;

	Fenwick(int n){
		this->n=n;
		bit=vector<int>(n+1);
	}

	int sum(int r){
		//return sum(0,r-1)
		
		int ret=0;
		while(r>=1){
			ret+=bit[r];
			r-=r&-r;
		}
		return ret;
	}

		
	void add(int pos,int x){
		pos++;
		while(pos<=n){
			bit[pos]+=x;
			pos+=pos&-pos;
		}
	}
};
