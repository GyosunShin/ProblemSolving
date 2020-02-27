// ������ ����
int V;

//�׷����� ���� ����Ʈ (����� ���� ��ȣ, ���� ����ġ) ���� ��´�.
vector<pair<int, int> >  adj[MAX_V];

vector<int> dijkstra(int src){
	vector<int> dist(V, INF);
	dist[src] = 0;
	
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src));
	while(!pq.empty()){
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		
		// ���� ���� ���� �ͺ��� �� ª�� ��θ� �˰� �ִٸ� ���� ���� ���� �����Ѵ�.
		if(dist[here] < cost)	continue;
		
		// ������ �������� ��� �˻��Ѵ�.
		for(int i = 0 ; i < adj[here].size() ; ++i) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			// �� ª�� ��θ� �߰��ϸ�, dist[]�� �����ϰ� �켱���� ť�� �ִ´�.
			if(dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;
}





