// 1991 트리 순회
// https://www.acmicpc.net/problem/1991
// https://bulweria.tistory.com/entry/C언어-백준-1991번-트리-순회 의 코드를 보고 배웠습니다. 트리를 오랜만에 하니 기억이 안 나네요
#include <stdio.h>
#include <stdlib.h>

char input[26][3]; // 입력이 알파벳 순서라고는 안 했음 ㅎㅎ, 0: node_data, 1: left_data, 2: right_data
int visited[26] = {0, }; // 이미 만들었나?

void init(){
	for (int i = 0; i < 26; i++){
		input[i][0] = '!';
	}
	return;
}

typedef struct TreeNode{
	char data;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

TreeNode* MakeTreeNode(char c){
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = c;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void SetTreeNode(TreeNode* node, char data0, char data1, char data2){ // 데이터를 받아 트리를 만듦
	node->data = data0;
	if (data1 != '.'){
		node->left = MakeTreeNode(data1);
	}
	if (data2 != '.'){
		node->right = MakeTreeNode(data2);
	}
	return;
}

TreeNode* SearchTreeNode(TreeNode* node, char data_find){ // 받은 데이터가 어디에 있는지 찾음, 못 찾으면 그 데이터는 루트 노드에 있어야 할 노드
	if (node != NULL){
		if (node->data == data_find){
			return node;
		}
		else {
			TreeNode* node_temp = SearchTreeNode(node->left, data_find);
			if (node_temp != NULL){
				return node_temp; // 왼쪽 자식에서 찾음
			}
			else {
				return SearchTreeNode(node->right, data_find); // 오른쪽 자식에 있을 것으로 추정함
			}
		}
	}
	return NULL; // 없을 경우, 사실상 루트 노드가 아니면 사용되지 않음
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

void preorder_traversal(TreeNode* node){ // 전위 순회
	if (node != NULL){
		printf("%c", node->data);
		preorder_traversal(node->left);
		preorder_traversal(node->right);
	}
	return;
}

void inorder_traversal(TreeNode* node){ // 중위 순회
	if (node != NULL){
		inorder_traversal(node->left);
		printf("%c", node->data);
		inorder_traversal(node->right);
	}
	return;
}

void postorder_traversal(TreeNode* node){ // 후위 순회
	if (node != NULL){
		postorder_traversal(node->left);
		postorder_traversal(node->right);
		printf("%c", node->data);
	}
	return;
}

int main(){
	char node_data, left_data, right_data;
	int Node, i, count = 0; // count는 순서 보장이 없을 때 사용되는 변수
	TreeNode* root = MakeTreeNode('\0'); // root를 아무 데이터 없는 노드로 만들어 둠
	TreeNode* branch;
	scanf("%d", &Node);
	for (i = 0; i < Node; i++){
		scanf(" %c %c %c", &node_data, &left_data, &right_data);
		branch = SearchTreeNode(root, node_data);
		if (branch != NULL){ // 트리 안에 node_data가 있음
			SetTreeNode(branch, node_data, left_data, right_data);
		}
		else {
			SetTreeNode(root, node_data, left_data, right_data);
		}
	}
	/* // 이하의 코드는 순서가 보장되지 않는다는 조건이 있었을 경우에도 작동하는 코드
	for (i = 0; i < Node; i++){
		scanf(" %c %c %c", &node_data, &left_data, &right_data);
		input[node_data - 'A'][0] = node_data;
		input[node_data - 'A'][1] = left_data;
		input[node_data - 'A'][2] = right_data;
	}
	for (i = 0; count < Node; i = (i + 1) % 26){ // 순서대로 입력된다는 보장이 없어서 다 입력될 때까지 무한 반복
		if (input[i][0] == '!' || visited[i] == 1) {continue;} // 없는 노드거나 이미 있는 노드일 경우
		count++;
		node_data = input[i][0];
		left_data = input[i][1];
		right_data = input[i][2];
		branch = SearchTreeNode(root, node_data);
		if (branch != NULL){ // 트리 안에 node_data가 있음
			SetTreeNode(branch, node_data, left_data, right_data);
			visited[i] = 1;
		}
		else if (node_data == 'A'){ // branch가 NULL이긴 하지만, root가 맞나?
			SetTreeNode(root, node_data, left_data, right_data);
			visited[i] = 1;
		}
	}*/
	preorder_traversal(root);	printf("\n");
	inorder_traversal(root);	printf("\n");
	postorder_traversal(root);	printf("\n");
	FreeTreeNode(root);
	return 0;
}