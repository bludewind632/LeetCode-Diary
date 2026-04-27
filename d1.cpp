//lt 3912 数组中的有效元素
/*
题目描述：
对于数组中的元素:(1)它大于其左侧的所有元素
(2)它大于其右侧的所有元素
两个条件满足其一即为有效元素
注：特别的，首位元素和末位元素永远为有效元素
返回数组中的所有有效元素，不改变原顺序
*/

/*
测试样例：
输入:{1,2,4,2,3,2}  输出:{1,2,4,3,2}
输入:{5,5,5,5}      输出:{5,5}
输入:{1}            输出:{1}
*/

#include<iostream>
#include<vector>

using namespace std;

//参悟灵神题解
vector<int> findValidElements(vector<int>& nums){
    int n = nums.size();
    //创建一个从后往前的条件(2)判断数组并维护
    vector<int8_t> isvalid(n,0);  //int8_t  一个字节的整数类型，既方便判断(1,0,-1),又节省空间(bool类型也是一个字节)
    int mx = 0;
    for(int i = n - 1;i >= 0;i--){
        if(nums[i] > mx){ //判断是否满足条件(2)
            isvalid[i] = 1;
        }
        mx = max(mx,nums[i]); //更新mx
    }
    vector<int> res;
    mx = 0;
    for(int i = 0;i < n;i++){
        if(nums[i] > mx || isvalid[i]){  //两个条件满足其一即可
            res.push_back(nums[i]);
        }
        mx = max(mx,nums[i]); //更新mx
    }
    return res;
}
//时间复杂度:O(n)
//空间复杂度:O(n)
/*
1.为什么条件(2)的判断要用一个从后往前的数组存储，条件(1)和条件(2)的判断方式能否交换?
因为要求不改变数组原顺序,条件(1)恰好满足原数组顺序,如果先正序后倒序那么我们的结果数组res顺序就是反的
2.首位和末位元素没有进行边界判断？
因为数据范围：1 <= nums[i] <= 100;所以首尾的元素一定大于mx的初始值(0),不用额外考虑两个端点
*/
int main(){
    vector<int> nums = {1,2,4,2,3,2};
    vector<int> ans = findValidElements(nums);
    for(int& x : ans){
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}


//2026/4/26
