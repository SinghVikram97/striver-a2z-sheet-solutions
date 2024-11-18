// https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

/*
Max window length with 2 fruit types
*/

// remove a fruit from the window
// which fruit to remove
// can;t check for set size since we may have added same fruit type multiple times
// 2 2 2 2 2 1 1 3
// at 3 we have to remove 2
// but it can also be like
// 2 1 2 1 2 1 2 3

// So we can't keep a set
// Instead we can keep the last position of both the fruits
// We have to move to last position + 1 of the fruit which is more to the left
