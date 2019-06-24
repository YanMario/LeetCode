//url : https://www.nowcoder.com/practice/0596b6232ce74b18b60ba0367d7f2492?tpId=90&&tqId=30931&rp=1&ru=/activity/oj&qru=/ta/2018test/question-ranking
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main()
{
    vector<pair<int, int>> vec;     //vector中存放pair对象
    int num1;
    int num2;
    char str;                       //输入"," 
    while(cin >> num1 >> str >> num2)
    {
        vec.push_back(make_pair(num1, num2));     //将输入的字符存放在vec中
    }
    sort(vec.begin(), vec.end());  //对vector进行排序，默认按照pair的first进行从小到大排序
    vector<pair<int, int>> vec1;   //vec1存放整合后的pair
    vec1.push_back(vec[0]);               //先将vec中的首元素先存放在vec1容器中
    auto len = vec.size();    //vec的长度
    auto i = 1;
    while(i < len)        //循环遍历
    {
        if(vec1.back().second < vec[i].first)     //如果首个pair的第二个元素比要加入队列pair的firt的要小
        {
            vec1.push_back(vec[i]);        //将该pair加入到vec1容器中
        }
        else            //反之将要加入的元素与vec1中的尾元素的second进行比较选择最大的进行更改
        {
            vec1.back().second = max(vec1.back().second, vec[i].second);
        }
        i++;
    }
    for(auto &i: vec1)           //输出打印
    {
        cout << i.first << "," << i.second << " ";
    }
    return 0;
}
