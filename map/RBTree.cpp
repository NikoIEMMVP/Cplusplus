#include <iostream>

using namespace std;


enum Color{
    Red,
    Black
};



template <class Key, class Value>
struct RBTreeNode{
    pair<Key, Value> _kv;
    Color _color;

    RBTreeNode<Key,Value>* _pLeft = nullptr;
    RBTreeNode<Key,Value>* _pRight = nullptr;
    RBTreeNode<Key,Value>* _pParent = nullptr;
};



template<class Key, class Value>
class RBTree{
public:
    typedef RBTreeNode<Key, Value> Node;
    typedef Node* pNode;

    RBTree()
    :_header(new Node)
    {
        _header->_pLeft = _header;
        _header->_pRight = _header;
    }

    bool insert(pair<Key, Value>& kv){
        //二叉搜索树的插入

        // 判断是否是空树
        if(_header->_pParent == nullptr){
            // 空树，插入根节点
            pNode root = new Node;
            root->_kv = kv;
            root->_color = Black;
            _header->_pParent = root;
            root->_pParent = _header;
            _header->_pLeft = root;
            _header->_pRight = root;
        }

        pNode cur = _header->_pParent;
        pNode parent = nullptr;

        // 找叶子节点
        while(cur){
            if(cur->_kv.first > kv.first){
                parent = cur;
                cur = cur->_pLeft;
            }
            else if(cur->_kv.first < kv.first){
                parent = cur;
                cur = cur->_pRight;
            }
            else{
                return false;
            }
            
        }

            cur = new Node;
            cur->_kv = kv;
            if(parent->_kv.first > cur->_kv.first){
                parent->_pLeft = cur;
            }
            else{
                parent->_pRight = cur;
            }
            cur->_pParent = parent;


            //调整，变色
            while(cur != _header->_pParent && cur->_pParent->_color == Red){
                pNode Parent = cur->_pParent;
                pNode gParent = parent->_pParent;
                if(gParent->_pLeft == Parent){
                    pNode uncle = gParent->_pRight;
                    // uncle 存在且为红
                    if(uncle && uncle->_color == Red){
                        Parent->_color = uncle->_color =Black;
                        gParent->_color = Red;
                        cur = gParent;
                    }
                    else{
                        // ucnle 不存在 （右旋）/ uncle 存在且为黑（右旋转）
                        // 检查是否有双旋的场景 ：左右双旋
                        // 首先 左单旋，swap(cur,p)
                        if(Parent->_pRight == cur){
                            RotateL(Parent);
                            swap(Parent,cur);
                        }
                        
                        RotateR(gParent);
                        Parent->_color = Black;
                        gParent->_color = Red;
                        break;
                    }
                }
                else{
                    pNode uncle = gParent->_pLeft;
                }
            }

    }


    // 左右旋转
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
        if(parent != _header->_pParent){
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
            _header->_pParent = subR;
        }

        //链接subR 和 parent
        parent->_pParent = subR;

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
        if(parent != _header->_pParent){
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
            _header->_pParent = subL;
        }

        // 4. 向上链接 parent，subL
        parent->_pParent = subL;
    }

private:
    pNode _header;
};