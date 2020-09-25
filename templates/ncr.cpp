const int M=1e9+7;


class Mint{
	vector<int> f;
	int mxN;

	public:

	Mint(int sz){
		mxN=sz;
		f.resize(mxN+1);

		f[1]=1;
		f[0]=1;
		for(int i=2;i<=mxN;++i){
			f[i]=(f[i-1]*i)%M;
		}
	}

	int ncr(int n,int r){
		if (n<r) return 0;

		int a=(f[n-r]*f[r])%M;
		a=inverse(a);

		return (f[n]*a)%M;
	}

	int inverse(int a){
		return modpow(a,M-2);
	}

	int modpow(int x,int p){
		if (!p) return 1;
		int val=modpow(x,p/2);

		val=(val*val)%M;
		if (p&1) val=(val*x)%M;
		return val;
	}
	
};
