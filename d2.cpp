//lt 1391 检查网格中是否存在有效路径
//题目描述
/*
现有一网格图grid(m * n)
每个grid[i][j] 代表一个街道
1 表示连接左单元格和右单元格的街道
2 表示连接上单元格和下单元格的街道
3 表示连接左单元格和下单元格的街道
4 表示连接右单元格和下单元格的街道
5 表示连接左单元格和上单元格的街道
6 表示连接右单元格和上单元格的街道
判断是否能从grid[0][0] 走到 grid[m - 1][n - 1]
*/

//本蒟蒻参考了灵神的题解^_^,属于是交作业了
//灵神原题解指路
//https://leetcode.cn/problems/check-if-there-is-a-valid-path-in-a-grid/solutions/3950394/li-yong-fang-xiang-xiang-liang-jian-hua-nzn2m/

//解题核心思路
//1.采用方向向量简化连接逻辑
//2.深度优先搜索(DFS)

#include<iostream>
#include<vector>
#include<functional>

using namespace std;


//创建方向向量数组
/*
其中每个街道分为上下和左右两个状态
右,下为1;左,上为-1
*/
static constexpr int DIRS[7][2][2] = {
    {},   //空出DIRS[0]便于与grid[i][j](1~6)匹配 
    {{0,1},{0,-1}},
    {{1,0},{-1,0}},
    {{1,0},{0,-1}},
    {{1,0},{0,1}},
    {{-1,0},{0,-1}},
    {{-1,0},{0,1}}
};
class Solution{
private:
    //判断是否可以连通的函数
    bool isvalid(int street,int dx,int dy){
        auto& p = DIRS[street];
        return (p[0][0] == dx && p[0][1] == dy)||
        (p[1][0] == dx && p[1][1] == dy);
    }
public:
    bool hasValidPath(vector<vector<int>>& grid){
        int m = grid.size(),n = grid[0].size();
        vector vis(m,vector<int8_t>(n,0)); //创建布尔数组判断是否已访问过
        //function<bool(int,int)> dfs = [&](int x,int y) -> bool{};
        auto dfs = [&](this auto&& dfs,int x,int y){  //this auto&& dfs 实现自调用
            if(x == m - 1 && y == n - 1) return true;
            vis[x][y] = true;  //标记已访问过的单元格
            for(auto& [dx,dy] : DIRS[grid[x][y]]){
                int nx = x + dx,ny = y + dy; //访问next单元格
                //边界判断和访问判断
                if(nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny]) continue;
                //连通判断和递归
                if(isvalid(grid[nx][ny],-dx,-dy) && dfs(nx,ny)) return true;
            }
            return false;
        };
        return dfs(0,0);
    }
};
int main(){
    vector<vector<int>> grid = {
        {2,4,3},
        {6,5,2}
    };
    Solution sol;
    bool flag = sol.hasValidPath(grid);
    if(flag) cout << "True" << endl;
    else cout << "False" << endl;
    return 0;
}


//测试样例：
/*
{{2,4,3},{6,5,2}};  输出:true
{{1,2,1},{1,2,1}};  输出:false
{1,1,2};            输出:false
*/

//2026/4/27
