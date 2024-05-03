// Dijkstra's algorithm for single source shortest paths
// O(VlgV+ElgV) time, O(V^2+E) memory
ll src = 1;
ll n, m; cin >> n >> m;
vector<pair<ll,ll> > adj_list[n+1];
for(ll i = 0; i < m; i++){
  ll a, b, c; cin >> a >> b >> c;
  adj_list[a].push_back({b, c});
}
ll dist[n+1];
bool out[n+1];
for(ll i = 1; i <= n; i++){
  dist[i] = inf;
  out[i] = 0;
}
dist[src] = 0;

priority_queue<pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq;
pq.push({0, src});
while(!pq.empty()){
  ll curr = pq.top().second; pq.pop();
  if(out[curr]) continue;
  out[curr] = 1;
  for(ll i = 0; i < adj_list[curr].size(); i++){
    if(dist[curr]+adj_list[curr][i].second < dist[adj_list[curr][i].first]){
      dist[adj_list[curr][i].first] = dist[curr]+adj_list[curr][i].second;
      pq.push({dist[adj_list[curr][i].first], adj_list[curr][i].first});
    }
  }
}
