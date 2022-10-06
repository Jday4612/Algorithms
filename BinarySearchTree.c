#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct node
{
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

int main() {
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
		destruct(&root); // BST�� ��� ����� ���� �޸� ����
		if (root == NULL)
			printf("0\n");
		else
			printf("1\n");
	}

	return 0;
}

// ������ ����(recursion)
void insert(struct node** root, int data)
{
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

// ����(preorder)Ž��(recursion)
void preOrder(struct node* root)
{
	if (root == NULL)
		return;
	else {
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

// ����(inorder)Ž��(recursion)
void inOrder(struct node* root)
{
	if (root == NULL)
		return;
	else {
		inOrder(root->left);
		printf("%d ", root->data);
		inOrder(root->right);
	}
}

// ����(postorder)Ž��(recursion)
void postOrder(struct node* root)
{
	if (root == NULL)
		return;
	else {
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->data);
	}
}

// ����� ����(recursion)
int size(struct node* root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + size(root->left) + size(root->right);
}

// ����(recursion)
int height(struct node* root)
{
	if (root == NULL)
		return -1;
	else {
		int leftHeight = height(root->left);
		int rightHeight = height(root->right);

		if (leftHeight >= rightHeight)
			return 1 + leftHeight;
		else
			return 1 + rightHeight;
	}
}

// �̷� �̹����� ��ȯ�ϱ�(recursion)
void mirror(struct node** root)
{
	if (*root == NULL)
		return;
	else {
		struct node* tmp = (struct node*)malloc(sizeof(struct node));

		tmp = (*root)->left;
		(*root)->left = (*root)->right;
		(*root)->right = tmp;

		mirror(&(*root)->left);
		mirror(&(*root)->right);
	}
}

// ��忡 ����� �������� ���� �� ���ϱ�(recursion)
int sumOfWeight(struct node* root)
{
	if (root == NULL)
		return 0;
	else
		return root->data + sumOfWeight(root->left) + sumOfWeight(root->right);
}

// ��Ʈ������ �ܸ��������� ��� ���� �������� �ִ���(recusrion)
int maxPathWeight(struct node* root)
{
	if (root == NULL)
		return 0;
	else {
		int leftHeight = maxPathWeight(root->left);
		int rightHeight = maxPathWeight(root->right);

		if (leftHeight >= rightHeight)
			return root->data + leftHeight;
		else
			return root->data + rightHeight;
	}
}

// Ʈ������� ���� �޸� �����ϱ�(recursion)
void destruct(struct node** root)
{
	if (*root == NULL)
		return;
	else {
		destruct(&(*root)->left);
		destruct(&(*root)->right);
		*root = NULL;
	}
}