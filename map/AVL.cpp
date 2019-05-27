#include <iostream>

template <class T>
struct AVLNode{
    AVLNode(const T& val = T())
    :_data(val)
    ,_pLeft(nullptr)
    ,_pRight(nullptr)
    ,_pParent(nullptr)
    ,_bf(0)
    {}

    T _data;
    AVLNode<T>* _pLeft;
    AVLNode<T>* _pRight;
    AVLNode<T>* _pParent;
    //平衡因子
    int _bf;

};

template <class T>
class AVLTree{
    typedef AVLNode<T> Node;
    typedef AVLNode<T>* pNode;

public:
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

        newNode->_pParent = parent;
        cur = newNode;
        //调整，保证平衡
        while(parent){
            //更新当前的平衡因子
            if(parent->_data > val)
                --parent->_bf;
            else
            {
                ++parent->_bf;
            }
            //检查平衡因子，_bf == 0，高度没有发生变化，停止更新
            if(parent->_bf == 0)
                break;
            if(parent->_bf == 1 || parent->_bf == -1)
                parent = parent->_pParent;
            else if(parent->_bf == 2 || parent->_bf == -2){
                if(parent->_bf == 2 && parent->_pRight->_bf == 1){
                    RotateL(parent);
                }else if(parent->_bf == -2 && cur->_bf == -1){
                    RotateR(parent);

                }else if(parent-> _bf == -2 && cur->_bf == 1){
                    // 左右双旋
                    RotateL(cur);
                    RotateR(parent);
                }else if(parent->_bf == 2 && cur->bf == -1){
                    // 右左双旋
                    RotateR(cur);
                    RotateL(parent);
                }
            }




            
        }

    }

    void RotateL(pNode parent){
        pNode subR = parent->_pRight;
        pNode subRL = subR->_pLeft;

        //旋转
        subR->_pLeft = parent;
        parent->_pRight = subRL;

        //更新三叉链
        //链接subRL 和 parent
        if(subRL)
            subRL->_pParent = parent;

        //链接subR 和 parent->_pParent 
        if(parent != _root){
            pNode gParent = parent->_pParent;
            //判断parent之前是parent->_pParent的那一边的节点
            //把sunR链接到对应的边
            if(gParent->_pLeft == parent)
                gParent->_pLeft = subR;
            else 
                gParent->_pRight = subR;
            //更新subR的pParent
            subR->_pParent = gParent;
        }else{
            //如果parent是根，subR变成新的根
            subR->_pParent = nullptr;
            _root = subR;
        }

        //链接subR 和 parent
        parent->_pParent = subR;
        //更新平衡因子
        subR->_bf = parent->_bf = 0;

    }
    

    void RotateR(pNode parent){
        pNode subL = parent ->_pLeft;
        pNode subLR = subL -> _pRight;
        // 1. 单向链接 subL， subLR

        subL -> _pRight = parent;
        parent->_pLeft = subLR;

        // 2 . 向上链接 subLR, parent
        if(subLR){
            subLR->_pParent = parent;
        }

        // 3. 双向链接subL 与 parent -> parent
        if(parent != _root){
            pNode gParent = parent ->_pParent;
            if(gParent->_pLeft == parent)
                gParent->_pLeft = subL;
            else
            {
                gParent->_pRight = subL;
            }
            subL->_pParent = gParent;
            
        }
        else
        {
            subL->_pParent = nullptr;
            _root = subL;
        }

        // 4. 向上链接 parent，subL
        parent->_pParent = subL;

    }

private:
    pNode _root = nullptr;
};