// Segtree with mass change op (addition)
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

  void set(ll l, ll r, ll num){
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
        v[ind] += num;
        continue;
      }
      q.push(ind*2);
      q.push(ind*2+1);
    }
  }

  ll get(ll n){
    n += w;
    ll ans = 0;
    while(n > 0){
      ans += v[n];
      n /= 2;
    }
    return ans;
  }

  void print(){
    for(ll i = 1; i < w*2; i++){
      cout << v[i] << "\n";
    }
  }
};
