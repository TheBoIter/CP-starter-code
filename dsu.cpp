// DSU
// O(1) time, O(n) memory
struct dsu {
	vector<int> p; 
	dsu(int n){
		p = vector<int>(n, -1);
	}
	
	int get(int a){
		while(p[a] >= 0){
			a = p[a];
		}
		return a;
	}
	
	int size(int a){
		return -p[get(a)];
	}
	
	void unite(int a, int b){
		a = get(a);
		b = get(b);
		if(a == b) return;
		if(p[a] > p[b]) swap(a, b);
		p[a] += p[b];
		p[b] = a;
	}
	
	void print(){
		for(int i = 0; i < p.size(); i++){
			cout << p[i] << " ";
		}
		cout << "\n";
	}
};
