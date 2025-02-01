// * There will be minimum of one node whose indegree will be zero

vector < int > bfs(vector < int > & indegree, int V, vector < int > adj[]) {

	  queue < int > mq;
	  vector < int > toposort;

	  // push all nodes with 0 indegree into queue
	  for (int i = 0; i < V; i++) {
	    if (indegree[i] == 0) {
	      mq.push(i);
	      toposort.push_back(i);
	    }
	  }

	  while (!mq.empty()) {

	    int front = mq.front();
	    mq.pop();

	    for (int i = 0; i < adj[front].size(); i++) {
	      int child = adj[front][i];
	      // front -> child
	      // reduce indegree of child by one
	      indegree[child]--;

	      // if indegree becomes zero push into queue
	      if (indegree[child] == 0) {
	        mq.push(child);
	        toposort.push_back(child);
	      }
	    }

	  }

	  return toposort;

}

vector < int > topoSort(int V, vector < int > adj[]) {
	vector < int > indegree(V);

	for (int i = 0; i < V; i++) {
	    for (int j = 0; j < adj[i].size(); j++) {
	      indegree[adj[i][j]]++;
	    }
	  }

	  return bfs(indegree, V, adj);

}