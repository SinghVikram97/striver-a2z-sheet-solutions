// https://practice.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1
vector < int > findUnion(int a[], int b[], int n, int m) {
  vector < int > ans;
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (a[i] == b[j]) {
      insert(a[i], ans);
      i++;
      j++;
    } else if (a[i] < b[j]) {
      insert(a[i], ans);
      i++;
    } else {
      insert(b[j], ans);
      j++;
    }
  }
  while (i < n) {
    insert(a[i], ans);
    i++;
  }
  while (j < m) {
    insert(b[j], ans);
    j++;
  }
  return ans;
}

void insert(int num, vector < int > & ans) {
  if (ans.empty() || (!ans.empty() && ans.back() != num)) {
    ans.push_back(num);
  }
}