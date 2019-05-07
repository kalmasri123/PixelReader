using namespace std;
#include <unistd.h>
#include "linkedlist.hpp"
#include "compressedDefs.hpp"
struct bst
{
	bst *left;
	bst *right;
	int key;
	CompressedColor value;
};
struct bst *newNode(int item, CompressedColor value)
{
	struct bst *temp = (struct bst *)malloc(sizeof(struct bst));
	temp->key = item;
	temp->left = temp->right = NULL;
	temp->value = value;
	return temp;
}
int totalFreq = 0;
int trees = 0;
void printInorder(bst *node)
{

	if (node == NULL)
		return;
	trees++;
	totalFreq += node->value.count;
	printInorder(node->left);
	printInorder(node->right);
}

struct bst *search(struct bst *root, int key)
{
	// Base Cases: root is null or key is present at root
	if (root == NULL || root->key == key)
		return root;

	// Key is greater than root's key
	if (root->key < key)
		return search(root->right, key);

	// Key is smaller than root's key
	return search(root->left, key);
}
struct bst *insert(struct bst *node, int key, CompressedColor cc)
{
	if (node == NULL)
		return newNode(key, cc);

	if (key < node->key)
		node->left = insert(node->left, key, cc);
	else if (key > node->key)
		node->right = insert(node->right, key, cc);

	return node;
}
void getRowFreqs(ColorMap map)
{
	Row total;
	for (size_t i = 0, size = map.size(); i < size; i++)
	{
		for (size_t j = 0, rowSize = map[i].size(); j < rowSize; j++)
		{
			total.push_back(map[i][j]);
		}
	}

	bst *root = NULL;
	for (size_t j = 0, size = total.size(); j < size; j++)
	{

		ImgColor c = {total[j].red, total[j].green, total[j].blue};
		CompressedColor cc = {c, 1};

		if (j == 0)
		{
			root = insert(root, (total[j].red * 256) + (total[j].green * 16) + (total[j].blue), cc);
		}
		else
		{
			bst *exists = search(root, (total[j].red * 256) + (total[j].green * 16) + (total[j].blue));
			if (exists != NULL)
			{
				exists->value.count++;
			}
			else
			{
				insert(root, (total[j].red * 256) + (total[j].green * 16) + (total[j].blue), cc);
			}
		}
	}

	printInorder(root);
	cout << "Frequency Total: " << totalFreq << endl;
}