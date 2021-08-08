// 5639 이진 검색 트리
// https://www.acmicpc.net/problem/5639
// https://imnotabear.tistory.com/224의 코드를 보고 배웠습니다. 배울수록 힘들군요.
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

TreeNode* MakeTreeNode(TreeNode* node, int Data){
	if (node == NULL){
		node = (TreeNode*)malloc(sizeof(TreeNode));
		node->data = Data;
		node->left = NULL;
		node->right = NULL;
	}
	else if (Data <= node->data){
		node->left = MakeTreeNode(node->left, Data);
	}
	else if (Data > node->data){
		node->right = MakeTreeNode(node->right, Data);
	}
	return node;
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

void postorder_traversal(TreeNode* node){ // 후위 순회
	if (node != NULL){
		postorder_traversal(node->left);
		postorder_traversal(node->right);
		printf("%d\n", node->data);
	}
	return;
}

int main(){
	int node_data;
	TreeNode* root = NULL;
	while (scanf("%d", &node_data) != EOF){
		root = MakeTreeNode(root, node_data);
	}
	postorder_traversal(root);
	FreeTreeNode(root);
	return 0;
}