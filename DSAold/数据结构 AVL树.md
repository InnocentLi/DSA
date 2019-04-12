### 平衡二叉树

当一颗二叉排序树插入时，是由小到大插入的或由大到小插入的，那么二叉排序树会退化成为链表

**|H(left) - H(rigtht)| <= 1**

由于对每个结点的左右子树的高度做了限制，所以**不会退化成链表**



高度为H的BS树，所包含的结点数量在什么范围？	H <= size(H) < 2^H - 1;

高度为H的AVL树，所包含的结点数量在什么范围？low(H - 1) + low(H - 2) + 1 <= 2 ^ H - 1;

由于是AVL树，所以高度为H的根结点的左右子树，一个是low(H - 1),一个是low(H - 2)

高度为1的最小结点数为1

高度为2的最小结点数为2

高度为3的最小结点数为4

高度为H的最小结点数为2^H

low(H - 1) = 2 ^ (H - 1)

low(H - 2) = 2 ^ (H - 2)

再加上根结点，最小结点数为2 ^ (H - 1) + 2 ^ (H - 2) + 1



抓着根结点左旋或者右旋

![屏幕快照 2018-09-21 下午6.53.36](/Users/hanxu/Desktop/blog图片文件/屏幕快照 2018-09-21 下午6.53.36.png)

![屏幕快照 2018-09-21 下午6.53.53](/Users/hanxu/Desktop/blog图片文件/屏幕快照 2018-09-21 下午6.53.53.png)

![屏幕快照 2018-09-21 下午6.54.07](/Users/hanxu/Desktop/blog图片文件/屏幕快照 2018-09-21 下午6.54.07.png)
以LL型为例:以K1为失衡点，左子树的左子树的高度过高导致失衡【k2 比 k3 高 2】   

![屏幕快照 2018-09-21 下午6.57.08](/Users/hanxu/Desktop/blog图片文件/屏幕快照 2018-09-21 下午6.57.08.png)

Ha = Hb + 1															K2 = Ha

Ha = max(Hc, Hd) + 2;													K1 = Hb + 1

Hc >= Hd															K3 = Hc + 2

Ha = Hc + 2

![屏幕快照 2018-09-21 下午7.07.31](/Users/hanxu/Desktop/blog图片文件/屏幕快照 2018-09-21 下午7.07.31.png)

![屏幕快照 2018-09-21 下午7.08.44](/Users/hanxu/Desktop/blog图片文件/屏幕快照 2018-09-21 下午7.08.44.png)

揪着左子树左旋 揪着根右旋 

### SB树 size balance tree

根据结点数量

每个结点所在子树的结点个数不小于其兄弟的两个孩子所在子树的结点个数。

size(left) >= size(right->left);

size(left)>=size(right->right);

size(right) >= size(left->right);

size(right) >= size(left->left);

高度为H的SB树，所包含的结点数量在什么范围？

```c
#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ({\
	__typeof(a) tempa = (a), tempb = (b);\
	tempa > tempb ? tempa : tempb;\
})

typedef struct Node{
	int key;
	struct Node *lchild, *rchild;
	int height;
}Node;


Node __NIL;
#define NIL (&__NIL)

int static_init(){
	NIL->lchild = NIL->rchild = NIL;
	NIL->height = 0;
	return 0;
}

int ______temp = static_init();

Node *init(int key){
	Node *p = (Node *)malloc(sizeof(Node));
	p->lchild = p->rchild = NIL;
	p->key = key;
	p->height = 1;
	return p;
}

void Up(Node *root){
	root->height = max(root->lchild->height, root->rchild->height) + 1;
	return ;
}

Node *left_rotate(Node *root){
	Node *temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	Up(root);
	Up(temp);
	return temp;
}

Node *right_rotate(Node *root){
	Node *temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	Up(root);
	Up(temp);
	return temp;
}

Node *__maintain(Node *root, int flag){
	if(flag){
		if(root->lchild->rchild->height > root->lchild->rchild->height){
			root->lchild = left_rotate(root->lchild);
		}
		root = right_rotate(root);
	}else{
		if(root->rchild->lchild->height > root->rchild->rchild->height){
			root->rchild = right_rotate(root->rchild);
		}
		root = left_rotate(root);
	}
	return root;
}

Node *maintain(Node *root){
	if(abs(root->lchild->height - root->rchild->height) < 2) return root;
	root = __maintain(root, root->lchild->height > root->rchild->height);
	return root;
}
Node *insert(Node *root, int key){
	if(root == NIL) return init(key);
	if(key == root->key){
		return root;
	}else if(key < root->key){
		root->lchild = insert(root->lchild, key);
	}else{
		root->rchild = insert(root->rchild, key);
	}
	Up(root);
	root = maintain(root);
	return root;
}

void clear(Node *root){
	if(root == NIL) return ;
	clear(root->lchild);
	clear(root->rchild);
	free(root);
	return ;
}

void pre_order(Node *root){
	if(root == NIL) return ;
	printf("%d (%d %d)\n", root->key, root->lchild->key, root->rchild->key);
	pre_order(root->lchild);
	pre_order(root->rchild);
	return ;
}

int main(){
	int n, a;
	Node *root = NIL;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a);
		root = insert(root, a);
		printf("Tree info : \n");
		pre_order(root);
		printf("-----------");
	}
	clear(root);
	return 0;
}
```



