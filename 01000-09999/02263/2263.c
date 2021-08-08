// 2263 트리의 순회
// https://www.acmicpc.net/problem/2263
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int NODE;
int inorder_arr[100001]; // 중위 순회
int postorder_arr[100001]; // 후위 순회
int inorder_arr_idx[100001]; // 범위를 적절히 조절하기 위해 설정
int visited[100001] = {0, };

typedef struct TreeNode{
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

TreeNode* MakeTreeNode(){
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = -1;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void Making_Tree(TreeNode* node, int inorder_start, int inorder_end, int postorder_start, int postorder_end){
	if (inorder_start > inorder_end || postorder_start > postorder_end) {return;} // 모순될 경우
	node->data = postorder_arr[postorder_end];
	visited[node->data] = 1;
	node->left = MakeTreeNode(); // 일단 노드를 만들어 줍시다
	node->right = MakeTreeNode(); // 일단 노드를 만들어 줍시다2
	Making_Tree(node->left, inorder_start, inorder_arr_idx[node->data] - 1, postorder_start, postorder_start + (inorder_arr_idx[node->data] - inorder_start) - 1); // 왼쪽으로
	Making_Tree(node->right, inorder_arr_idx[node->data] + 1, inorder_end, postorder_start + (inorder_arr_idx[node->data] - inorder_start), postorder_end - 1); // 오른쪽으로
	return;
}

void preorder_traversal(TreeNode* node){ // 전위 순회
	if (node != NULL && node-> data != -1){
		printf("%d ", node->data);
		preorder_traversal(node->left);
		preorder_traversal(node->right);
	}
	return;
}

void FreeTreeNode(TreeNode* node){
	if (node == NULL){ // 노드가 없네?
		return;
	}
	else { // 이 노드는 존재함
		FreeTreeNode(node->left);
		FreeTreeNode(node->right);
		free(node);
		return;
	}
}

int main(){
	TreeNode* root = MakeTreeNode();
	scanf("%d", &NODE);
	for (int k = 0; k < NODE; k++){
		scanf("%d", &inorder_arr[k]);
		inorder_arr_idx[inorder_arr[k]] = k;
	}
	for (int k = 0; k < NODE; k++){
		scanf("%d", &postorder_arr[k]);
	}
	Making_Tree(root, 0, NODE - 1, 0, NODE - 1);
	preorder_traversal(root);
	FreeTreeNode(root);
}