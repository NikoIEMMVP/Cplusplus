// 无穷大满二叉树，根节点编号为1，
// 将节点从左到右一层一层的编号
// 寻找公公祖先

class LCA {
public:
    int getLCA(int a, int b) {
        while(a != b){
            if(a > b){
                a /= 2;
            }else{
                b /= 2;
            }
        }
        return a;
    }
};