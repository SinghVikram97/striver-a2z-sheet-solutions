// https://practice.geeksforgeeks.org/problems/second-largest3735/1
int print2largest(int arr[], int n) {
  int largest = -1;
  int secondLargest = -1;
  for (int i = 0; i < n; i++) {
    if (arr[i] > largest) {
      secondLargest = largest;
      largest = arr[i];
    } else if (arr[i] < largest && arr[i] > secondLargest) {
      secondLargest = arr[i];
    }
  }
  return secondLargest;
}