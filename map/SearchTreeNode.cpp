#include <iostream>


template<class T>
struct BSTNode
{
    BSTNode(const T& val = T())
    :_data(val)
    ,_pLeft(nullptr)
    ,_pRight(nullptr)
    {}

    T _data;
    BSTNode<T>* _pLeft;
    BSTNode<T>* _pRight;
};

template<class T>
class BSTree{
public:
    typedef BSTNode<T> Node;
    typedef Node* pNode;


    BSTree(const pNode root = nullptr)
    :_root(root)
    {}

    pNode find(const T& val)
    {
        if(_root == nullptr)
            return nullptr;

        pNode cur = _root;
        while(cur){
            if(cur->_data == val)
                return val;
            else if(cur -> _data > val)
            {
                cur = cur->_pLeft;
            }
            else if(cur->_data < val){
                cur = cur->_pRight;
            }
        }

        return nullptr;
    }

    bool insert(const T& val){
        if(_root == nullptr){
            _root = new Node(val);
            return true;
        }

        pNode cur = _root;
        pNode parent = nullptr;
        while(cur){
            parent = cur;
            if(cur->_data > val){
                cur = cur->_pLeft;
            }else if(cur->_data < val){
                cur = cur->_pRight;
            }else{
                return false;
            }
        }

        pNode newNode = new Node(val);
        if(parent->_data > val){
            parent->_pLeft = newNode;
        }else
        {
            parent->_pRight = newNode;
        }

        return true;
        
    }

    void Inorder()
    {
        _Inorder(_root);
        std :: cout << std :: endl;
    }

    void _Inorder(pNode root){
        if(root){
            _Inorder(root->_pLeft);
            std :: cout << root->_data << " ";
            _Inorder(root-> _pRight);
        }
       
    }

private:
    pNode _root;
};


void test()
{
    BSTree<int> bt;
    bt.insert(5);
    bt.Inorder();
    bt.insert(1);
    bt.Inorder();
    bt.insert(8);
    bt.Inorder();
    bt.insert(9);
    bt.Inorder();
    bt.insert(0);
    bt.Inorder();
    bt.insert(2);
    bt.Inorder();
    bt.insert(6);
    bt.Inorder();
}

int main()
{
    test();
    return 0;
}