#include <iostream>
#include <vector>
using namespace std;
/***************************************
 **1并查集算法说明
 **    代码思路：类似构建一个树，只是将结点与根节点绑定在一起，从而证明路径是否存在 
 **     1.1main函数，初始化了一个二维向量，然后实例化一个Disjointset,
 **     1.2Disjointset类，两个成员变量node,deg,
            1.2.1构造函数
                node中第i个元素的值表示第i个点的根节点(体现绑定关系)
                def中第i个元素的值表示第i个点的度，即有多少棵子树
            1.2.2findset()函数
                找点的根节点是谁，每调用一次就会更新对应node的值
            1.2.3unit()函数
                给出两个点，判断两个点的根节点是否是同一个点，
                每调用一次的结果是，若所求的两点的根节点一样，则不变，因为它们之间存在路径
                                   若所求的两点的根节点不同，则将它们融合，最终的结果是与这两点之间存在路径的点(所有根节点和非根结点)都共用一个根节点
 ***************************************/

class Disjointset{
private:
    int* node;
    int* deg;

public:
    Disjointset(int n){
        node = new int[n];
        deg = new int[n];
        for(int i=0; i<n; i++){
            node[i] = i;
            deg[i] = 0;
        }
    }

    int findset(int n){
        return node[n] == n ? n : node[n] = findset(node[n]);
    }

    void unit(int x, int y){
        int xroot = node[x];
        int yroot = node[y];
        if(xroot == yroot)
                ;
        else if(deg[x] <= deg[y]){
            node[x] = y;
            deg[y]++;
        } else {
            node[y] = x;
            deg[x]++;
        }
    }
};

int main(){
    int n = 10;
    vector<vector<int> > edges(3, vector<int> (2,0));//3 lines, 2 int in each line
    edges[0][0] = 0;
    edges[0][1] = 1;
    edges[1][0] = 1;
    edges[1][1] = 2;
    edges[2][0] = 2;
    edges[2][1] = 0;
    int source = 0;
    int destination = 2;
    Disjointset data(n);
    for(vector<int> edge : edges){
        data.unit(edge[0], edge[1]);
    }
    if(data.findset(source) == data.findset(destination))
        cout << "true" << endl;
    else    
        cout << "false" << endl;
    system("pause");
    return 0;
}