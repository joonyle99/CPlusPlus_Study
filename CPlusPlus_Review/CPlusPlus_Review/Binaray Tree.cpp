#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;

    // ������
    Node(int _k)
    {
        key = _k;
        left = nullptr;
        right = nullptr;
    }
};

// ��ȯ���� �׻� �ڱ� �ڽ�
Node* InsertNode(Node* _root, int _k)
{
    if (_root == nullptr)
        return new Node(_k);

    if (_root->key < _k)
        _root->right = InsertNode(_root->right, _k);
    else
		_root->left = InsertNode(_root->left, _k);

    return _root;
}

Node* SearchNode(Node* _root, int _k)
{
    if (_root == nullptr)
        return nullptr;

    if (_root->key < _k)                // ã������ ���� �� ũ��
        return SearchNode(_root->right, _k);
    else if (_root->key > _k)           // ã������ ���� �� �۴�
        return SearchNode(_root->left, _k);
    else 							    // ã�Ҵ�
        return _root;
}

// ���� ��ȸ (���� �� ���� ���)
void PrintTree(Node* _root)
{
	if (_root == nullptr)
		return;

	PrintTree(_root->left);
	cout << _root->key << endl;
	PrintTree(_root->right);
}

int main()
{
    // ���� Ž�� Ʈ�� ����
    Node* tree = nullptr;
    while (true)
    {
        int key;
        cout << "Enter a key to insert (-1 to quit): ";
        cin >> key;

        if (key == -1)
            break;

        tree = InsertNode(tree, key);
    }

    // Ʈ�� ���
    PrintTree(tree);

    // ���� Ž�� Ʈ������ ��� Ž��
    int searchKey = 40;
    while (true)
    {
        std::cout << "Enter a key to search (-1 to quit): ";
        std::cin >> searchKey;

        if (searchKey == -1)
            break;

        // Ž�� �Լ� ȣ��
        Node* result = SearchNode(tree, searchKey);

        if (result == nullptr)
            std::cout << "Key " << searchKey << " not found in the binary search tree." << std::endl;
        else
            std::cout << " = Key " << searchKey << " found!" << std::endl;
    }

    return 0;
}