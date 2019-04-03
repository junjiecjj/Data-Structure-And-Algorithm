/*************************************************************************
>> File Name: C++_map.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.04.03
************************************************************************/

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

void show(map<char, string> Map)
{
    cout << "打印Map\n";
    for(auto i : Map)
    {
        cout << i.first << ":" << i.second << "  ";
    }
    cout << "\n\n";
}

void show1(map<char, string> Map)
{
    cout << "打印Map\n";
    for(auto it = Map.cbegin(); it != Map.cend(); ++it)
    {
        cout << it->first << ":" << it->second << "  ";
    }
    cout << "\n\n";
}
void Insert(pair<map<char,string>::iterator,bool> it)
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

int main(int argc, char *argv[])
{
    map<char, string> Map = {{'c',"chen"},{'w',"wang"},{'l',"li"},{'z',"zhao"},{'s',"sun"},{'q',"qian"},{'z',"zhou"}};
    cout << "Map.size() = "<< Map.size() << endl;
    show(Map);
    auto a = Map.insert({'a',"aozi"});
    Insert(a);

    auto b = Map.insert({'b',"bao"});
    Insert(b);

    auto it1 = Map.insert(make_pair('c',"cao"));//插入一个已有元素对容器吧没有任何影响
    Insert(it1);

    cout << "Map.size() = "<< Map.size() << endl;
    show(Map);

    cout << "Map['a'] = " << Map['a'] << endl;
    cout << "Map['x'] = " << Map['x'] << endl;//如果查找的关键字不在Map中,怎返回空

    Map['x'] = "xiao";
    cout << "Map['x'] = " << Map['x'] << "\n\n";

    cout << "Map.at('a') = " << Map.at('a') << "\n\n";
    //cout << "Map.at('m') = " << Map.at('m') << "\n\n";如果查找的关键字不在Map中,抛出out_of_range的错误
    
    auto it2 = Map.insert({'e',"elicpse"});
    Insert(it2);

    auto it3 = Map.find('a');
    cout << "auto it3 = Map.find('a'),it3->first = " << it3->first << ", it3->second = "<< it3->second << endl;
    //auto it1 = Map.find('y');
    //cout << "auto it1 = Map.find('y'),it1->first = " << it1->first << ", it1->second = "<<it1->second << endl;
    
    cout << "Map.count('a') = " << Map.count('a') << "\n\n";

    cout << "删除'a' :" << Map.erase('a') << "\n\n";
    return 0;
}

/*

Map.size() = 6
打印Map
c:chen  l:li  q:qian  s:sun  w:wang  z:zhao  

插入成功,it.second = 1
it.first->first = a,it.first -> second = aozi


插入成功,it.second = 1
it.first->first = b,it.first -> second = bao


插入失败,Map中已有该元素,it.second = 0
it.first->first = c,it.first -> second = chen


Map.size() = 8
打印Map
a:aozi  b:bao  c:chen  l:li  q:qian  s:sun  w:wang  z:zhao  

Map['a'] = aozi
Map['x'] = 
Map['x'] = xiao

Map.at('a') = aozi

插入成功,it.second = 1
it.first->first = e,it.first -> second = elicpse


auto it3 = Map.find('a'),it3->first = a, it3->second = aozi
Map.count('a') = 1

删除'a' :1
*/
