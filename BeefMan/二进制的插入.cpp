// 32位的整数 n 和 m，将 m 的二进制位插入到 n 的第j位到第i位中
// 保证 n 的第i位到第j位 皆为零



class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        // write code here
        return n | (m << j);
    }
};