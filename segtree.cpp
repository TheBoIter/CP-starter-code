// Segment Tree without mass-change ops
// O(lg n) time, O(n) memory
struct segtree {
	vector<ll> v;
	ll w;
	segtree(ll n, vector<ll> inp){
		ll sz = 1;
		while(sz < n) sz *= 2;
		v = vector<ll>(sz*2, 0);
		w = sz;
		ll i = 0;
		while(i < inp.size()){
			v[w+i] = inp[i];
			i++;
		}
		for(ll j = w-1; j > 0; j--){
			v[j] = v[j*2]+v[j*2+1];
		}
	}
	
	void set(ll ind, ll a){
		ind += w;
		v[ind] = a;
		while(ind > 0){
			ind /= 2;
			v[ind] = v[ind*2]+v[ind*2+1];
		}
	}
	// sum: finds sum on [l,r)
	ll sum(ll l, ll r){
		ll ans = 0;
		queue<ll> q;
		q.push(1);
		while(!q.empty()){
			ll curr = q.front(); q.pop();
			ll ind = curr;
			ll sz = 1;
			while(curr < w){
				curr *= 2;
				sz *= 2;
			}
			if(curr-w >= r) continue;
			if(curr+sz-w <= l) continue;
			if(curr-w >= l && curr+sz-w <= r){
				ans += v[ind];
				continue;
			}
			q.push(ind*2);
			q.push(ind*2+1);
		}
		return ans;
	}
	
	void print(){
		for(ll i = 1; i < w*2; i++){
			cout << v[i] << "\n";
		}
	}
};
