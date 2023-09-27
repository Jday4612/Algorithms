#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

void insert(struct node** root, int data);
void preOrder(struct node* root);
void inOrder(struct node* root);
void postOrder(struct node* root);
int size(struct node* root);
int height(struct node* root);
int sumOfWeight(struct node* root);
int maxPathWeight(struct node* root);
void mirror(struct node** root);
void destruct(struct node** root);

int main()
{
	int numTestCases;
	scanf("%d", &numTestCases);

	while (numTestCases--) {
		int num, i;
		struct node* root = NULL;
		
		scanf("%d", &num);
		
		for (i = 0; i < num; i++) {
			int data;
			scanf("%d", &data);
			insert(&root, data);
		}

		printf("%d\n", size(root));
		printf("%d\n", height(root));
		printf("%d\n", sumOfWeight(root));
		printf("%d\n", maxPathWeight(root));
		mirror(&root);
		preOrder(root); printf("\n");
		inOrder(root); printf("\n");
		postOrder(root); printf("\n");
		destruct(&root); // BST의 모든 노드의 동적 메모리 해제

		if (root == NULL)
			printf("0\n");
		else
			printf("1\n");
	}

	return 0;
}

void insert(struct node** root, int data) {
	if (*root == NULL) {
		*root = (struct node*)malloc(sizeof(struct node));
		(*root)->data = data;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else {
		if (data <= (*root)->data)
			insert(&((*root)->left), data);
		else
			insert(&((*root)->right), data);
	}
}

void preOrder(struct node* root) {
	if (root == NULL)
		return;
	else {
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(struct node* root) {
	if (root == NULL)
		return;
	else {
		inOrder(root->left);
		printf("%d ", root->data);
		inOrder(root->right);
	}
}

void postOrder(struct node* root) {
	if (root == NULL)
		return;
	else {
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->data);
	}
}

int size(struct node* root) {
	if (root == NULL)
		return 0;
	else
		return 1 + size(root->left) + size(root->right);
}

int height(struct node* root) {
	if (root == NULL)
		return -1;
	else {
		int leftHeight = height(root->left);
		int rightHeight = height(root->right);

		if (leftHeight < rightHeight)
			return 1 + rightHeight;
		else
			return 1 + leftHeight;
	}
}

int sumOfWeight(struct node* root) {
	if (root == NULL)
		return 0;
	else
		return root->data + sumOfWeight(root->left) + sumOfWeight(root->right);
}

int maxPathWeight(struct node* root) {
	if (root == NULL)
		return 0;
	else {
		int leftWeight = maxPathWeight(root->left);
		int rightWeight = maxPathWeight(root->right);
		return root->data + (leftWeight >= rightWeight ? leftWeight : rightWeight);
	}
}

void mirror(struct node** root) {
	if (*root == NULL)
		return;
	else {
		struct node* m = (struct node*)malloc(sizeof(struct node));

		m = (*root)->left;
		(*root)->left = (*root)->right;
		(*root)->right = m;

		mirror(&(*root)->left);
		mirror(&(*root)->right);
	}
}

void destruct(struct node** root) {
	if (*root == NULL)
		return;
	else {
		destruct(&(*root)->left);
		destruct(&(*root)->right);
		*root = NULL;
	}
}
