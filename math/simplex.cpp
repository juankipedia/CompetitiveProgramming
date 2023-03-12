const double EPS = 1e-7;
namespace Simplex {
	vector<int> X,Y;
	vector<vector<double> > A;
	vector<double> b,c;
	double z;
	int n,m;
	void pivot(int x,int y){
		swap(X[y],Y[x]);
		b[x]/=A[x][y];
		for (int i = 0; i < m; i++) {
			if(i!=y)A[x][i]/=A[x][y];
		}
		A[x][y]=1/A[x][y];
		for (int i = 0; i < n; i++) {
			if(i!=x&&abs(A[i][y])>EPS){
				b[i]-=A[i][y]*b[x];
				for (int j = 0; j < m; j++) if(j!=y)A[i][j]-=A[i][y]*A[x][j];
				A[i][y]=-A[i][y]*A[x][y];
			}
		}
		z+=c[y]*b[x];
		for (int i = 0; i < m; i++) {
			if(i!=y)c[i]-=c[y]*A[x][i];
		}
		c[y]=-c[y]*A[x][y];
	}
	pair<double,vector<double> > simplex( // maximize c^T x s.t. Ax<=b, x>=0
		vector<vector<double> > _A, vector<double> _b, vector<double> _c){
		// returns pair (maximum value, solution vector)
		A=_A;b=_b;c=_c;
		n=b.size();m=c.size();z=0.;
		X=vector<int>(m);Y=vector<int>(n);
		for (int i = 0; i < m; i++) X[i] = i;
		for (int i = 0; i < n; i++) Y[i]=i+m;
		while(1){
			int x=-1,y=-1;
			double mn=-EPS;
			for (int i = 0; i < n; i++) if(b[i]<mn)mn=b[i],x=i;
			if(x<0)break;
			for (int i = 0; i < m; i++) if(A[x][i]<-EPS){y=i;break;}
			assert(y>=0); // no solution to Ax<=b
			pivot(x,y);
		}
		while(1){
			double mx=EPS;
			int x=-1,y=-1;
			for (int i = 0; i < m; i++) if(c[i]>mx)mx=c[i],y=i;
			if(y<0)break;
			double mn=1e200;
			for (int i = 0; i < n; i++) if(A[i][y]>EPS&&b[i]/A[i][y]<mn)mn=b[i]/A[i][y],x=i;
			assert(x>=0); // c^T x is unbounded
			pivot(x,y);
		}
		vector<double> r(m);
		for (int i = 0; i < n; i++) if(Y[i]<m)r[Y[i]]=b[i];
		return {z,r};
	}
}
