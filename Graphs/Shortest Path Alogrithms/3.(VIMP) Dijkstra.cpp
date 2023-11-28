// Toposort works for - acylic directed graphs ( toposort doesn't exist for undirected graphs/graphs with cycle)
// Dijkstra works for cyclic graphs too (with non negative weights)

// Toposort - O(V+E)
// Dijkstra - O(ElogV)

// Why Dijkstra doesn't work with negative weights?
// It will go into infinite loop, we keep traversing and distance becomes less every time

// 0 ----- 1  [ -2 as edge weight ]

// dist-> [0,INT_MAX]
// priority_queue -> {0,0}

// take out {0,0}, 0+(-2)= -2 <INT_MAX update dist and push into priority_queue
// dist -> [0,-2]
// priority_queue -> {-2,1}

// take out {-2,1}, dist[0] = -2-2 = -4 < 0 update dist and push into priority_queue
// dist [-4,-2]
// priority_queue -> {-4,0}

// goes on forever

// Time complexity using priority_queue
