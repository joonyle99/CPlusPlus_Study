#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;

    // 생성자
    Node(int _k)
    {
        key = _k;
        left = nullptr;
        right = nullptr;
    }
};

// 반환값은 항상 자기 자신
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

    if (_root->key < _k)                // 찾으려는 값이 더 크다
        return SearchNode(_root->right, _k);
    else if (_root->key > _k)           // 찾으려는 값이 더 작다
        return SearchNode(_root->left, _k);
    else 							    // 찾았다
        return _root;
}

// 중위 순회 (작은 것 부터 출력)
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
    // 이진 탐색 트리 생성
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

    // 트리 출력
    PrintTree(tree);

    // 이진 탐색 트리에서 노드 탐색
    int searchKey = 40;
    while (true)
    {
        std::cout << "Enter a key to search (-1 to quit): ";
        std::cin >> searchKey;

        if (searchKey == -1)
            break;

        // 탐색 함수 호출
        Node* result = SearchNode(tree, searchKey);

        if (result == nullptr)
            std::cout << "Key " << searchKey << " not found in the binary search tree." << std::endl;
        else
            std::cout << " = Key " << searchKey << " found!" << std::endl;
    }

    return 0;
}