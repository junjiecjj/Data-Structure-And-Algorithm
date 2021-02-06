/**************************************************
>> File Name: C++_unordermap.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.04.03
***************************************************/

#include<iostream>
using namespace std;
#include<list>
#include<forward_list>
#include<deque>
#include<string>
#include<array>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<utility>

void show(unordered_map<char, string> unordermap)
{
    cout << "打印Map\n";
    for(auto i : unordermap)
    {
        cout << i.first << ":" << i.second << "  ";
    }
    cout << "\n\n";
}

void show1(unordered_map<char, string> unordermap)
{
    cout << "打印Map\n";
    for(auto it = unordermap.cbegin(); it != unordermap.cend(); ++it)
    {
        cout << it->first << ":" << it->second << "  ";
    }
    cout << "\n\n";
}

void Insert(pair<unordered_map<char,string>::iterator,bool> it)
{
    if(it.second)
    {
        cout << "插入成功,it.second = " << it.second << endl;
        cout << "it.first->first = " << it.first-> first << ",it.first -> second = " << it.first->second << endl;
    }
    else
    {
        cout << "插入失败,Map中已有该元素,it.second = " << it.second << endl;
        cout << "it.first->first = " << it.first-> first << ",it.first -> second = " << it.first->second << endl;
    }
    cout << "\n\n";
}

int main(int argc,char *argv[])
{
    unordered_map<char, string> unordermap = {{'c',"chen"},{'w',"wang"},{'b',"baotou"},{'b',"yongbao"},{'l',"li"},{'z',"zhao"},{'s',"sun"},{'q',"qian"},{'z',"zhou"},{'c',"coo"},{'b',"baoda"}};
    cout << "unordermap.size() = "<< unordermap.size() << endl;
    show(unordermap);
    auto a = unordermap.insert({'a',"aozi"});
    Insert(a);

    auto b = unordermap.insert({'b',"bao"});
    Insert(b);

    auto it1 = unordermap.insert(make_pair('c',"cao"));//插入一个已有元素对容器吧没有任何影响
    Insert(it1);

    cout << "Map.size() = "<< unordermap.size() << endl;
    show(unordermap);

    cout << "Map['a'] = " << unordermap['a'] << endl;
    cout << "Map['x'] = " << unordermap['x'] << endl;//如果查找的关键字不在Map中,怎返回空

    unordermap['x'] = "xiao";
    cout << "unorderap['x'] = " << unordermap['x'] << "\n\n";

    cout << "unorderap.at('a') = " << unordermap.at('a') << "\n\n";
    //cout << "unorderap.at('m') = " << unorderap.at('m') << "\n\n";如果查找的关键字不在Map中,抛出out_of_range的错误
    
    auto it2 = unordermap.insert({'e',"elicpse"});
    Insert(it2);

    auto it3 = unordermap.find('a');
    cout << "auto it3 = Map.find('a'),it3->first = " << it3->first << ", it3->second = "<< it3->second << endl;
    //auto it1 = Map.find('y');
    //cout << "auto it1 = Map.find('y'),it1->first = " << it1->first << ", it1->second = "<<it1->second << endl;
    
    cout << "Map.count('a') = " << unordermap.count('a') << "\n\n";

    cout << "删除'a' :" << unordermap.erase('a') << "\n\n";

    return 0;
}

/*
 
unordermap.size() = 7
打印Map
q:qian  s:sun  z:zhao  l:li  b:baotou  w:wang  c:chen  

插入成功,it.second = 1
it.first->first = a,it.first -> second = aozi


插入失败,Map中已有该元素,it.second = 0
it.first->first = b,it.first -> second = baotou


插入失败,Map中已有该元素,it.second = 0
it.first->first = c,it.first -> second = chen


Map.size() = 8
打印Map
a:aozi  q:qian  s:sun  z:zhao  l:li  b:baotou  w:wang  c:chen  

Map['a'] = aozi
Map['x'] = 
unorderap['x'] = xiao

unorderap.at('a') = aozi

插入成功,it.second = 1
it.first->first = e,it.first -> second = elicpse


auto it3 = Map.find('a'),it3->first = a, it3->second = aozi
Map.count('a') = 1

删除'a' :1
*/
