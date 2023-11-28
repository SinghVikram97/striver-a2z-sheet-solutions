// https://www.codingninjas.com/studio/problems/floor-from-bst_625868
void floorHelper(BinaryTreeNode<int> *node, int x, int &floor){
    if(node==NULL){
        return;
    }
    if(node->data<=x){
		floor=max(floor,node->data);
		floorHelper(node->right,x,floor);
	}
	else{
		floorHelper(node->left,x,floor);
	}

}
int Floor(BinaryTreeNode<int> *node, int input)
{
	int floor=INT_MIN+5;
	floorHelper(node, input, floor);
	if(floor==INT_MIN+5){
		floor=-1;
	}
	return floor;
}