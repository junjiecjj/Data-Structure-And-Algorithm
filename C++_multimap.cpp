/*************************************************************************
>> File Name: C++_multimap.cpp
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


void show(multimap<char, string> Map)
{
    cout << "打印Map\n";
    for(auto i : Map)
    {
        cout << i.first << ":" << i.second << "  ";
    }
    cout << "\n\n";
}

void show1(multimap<char, string> Map)
{
    cout << "打印Map\n";
    for(auto it = Map.cbegin(); it != Map.cend(); ++it)
    {
        cout << it->first << ":" << it->second << "  ";
    }
    cout << "\n\n";
}
void Insert(pair<multimap<char,string>::iterator,bool> it)
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
    multimap<char,string> mulmap = {{'c',"chen"},{'w',"wang"},{'b',"baotou"},{'b',"yongbao"},{'b',"baoda"},{'l',"li"},{'z',"zhao"},{'s',"sun"},{'q',"qian"},{'z',"zhou"},{'c',"coo"}};
    cout << "mulmap.size() = "<< mulmap.size() << endl;
    show(mulmap);

    auto a = mulmap.insert({'a',"aozi"});
    //Insert(a);
    cout << "因为是multimap,允许重复元素,索引插入成功." << endl;
    cout << "a->first = " << a-> first << ",a -> second = " << a->second << "\n\n";
    cout << "Map.size() = "<< mulmap.size() << endl;
    show1(mulmap);

    auto b = mulmap.insert({'b',"bao"});
    cout << "因为是multimap,允许重复元素,索引插入成功." << endl;
    cout << "b->first = " << b-> first << ",b -> second = " << b->second << "\n\n";
    cout << "Map.size() = "<< mulmap.size() << endl;
    show1(mulmap);

    auto c = mulmap.insert(make_pair('c',"coo"));//插入一个已有元素对容器吧没有任何影响
    //Insert(it1);
    cout << "因为是multimap,允许重复元素,索引插入成功." << endl;
    cout << "c->first = " << c -> first << ",c -> second = " << c -> second << "\n\n";
    cout << "Map.size() = "<< mulmap.size() << endl;
    show1(mulmap);

    //cout << "Map['a'] = " << mulmap['a'] << endl;             //只有map和unorder_map有map.at('a')和map['a']
    //cout << "Map.at('a') = " << mulmap.at('a') << "\n\n";     //multimap和unorder_multimap没有下标操作,因为可能有多个值与一个关键字对应
    
    auto it2 = mulmap.insert({'e',"elicpse"});
    //Insert(it2);    
    cout << "因为是multimap,允许重复元素,索引插入成功." << endl;
    cout << "it2->first = " << it2-> first << ",it2 -> second = " << it2->second << "\n\n";
    cout << "mulmap.size() = "<< mulmap.size() << endl;
    show(mulmap);

    auto it3 = mulmap.find('a');
    cout << "auto it3 = Map.find('a'),it3->first = " << it3->first << ", it3->second = "<< it3->second << endl;
    //auto it1 = Map.find('y');
    //cout << "auto it1 = Map.find('y'),it1->first = " << it1->first << ", it1->second = "<<it1->second << endl;
    
    auto it4 = mulmap.find('c');
    cout << "Map.count('c') = " << mulmap.count('c') << "\n\n";
    int Count = mulmap.count('c');
    while(Count)
    {
        cout << "auto it4 = Map.find('c'),it4->first = " << it4->first << ", it4->second = "<< it4->second << endl;
        ++it4;
        --Count;
    }
    cout << "\n\n";
    for(auto beg = mulmap.lower_bound('b'),end = mulmap.upper_bound('b');
            beg != end; ++beg)
    {
        cout << "Map.find('b'),beg->first = " << beg->first << ", beg -> second = "<< beg->second << endl;
    }
    cout << "删除'a' :" << mulmap.erase('a') << "\n\n";
    show(mulmap);

    cout << "删除'c' :" << mulmap.erase('c') << "\n\n";
    show(mulmap);
    return 0;

}

/*
输出为:

mulmap.size() = 11
打印Map
b:baotou  b:yongbao  b:baoda  c:chen  c:coo  l:li  q:qian  s:sun  w:wang  z:zhao  z:zhou  

因为是multimap,允许重复元素,索引插入成功.
a->first = a,a -> second = aozi

Map.size() = 12
打印Map
a:aozi  b:baotou  b:yongbao  b:baoda  c:chen  c:coo  l:li  q:qian  s:sun  w:wang  z:zhao  z:zhou  

因为是multimap,允许重复元素,索引插入成功.
b->first = b,b -> second = bao

Map.size() = 13
打印Map
a:aozi  b:baotou  b:yongbao  b:baoda  b:bao  c:chen  c:coo  l:li  q:qian  s:sun  w:wang  z:zhao  z:zhou  

因为是multimap,允许重复元素,索引插入成功.
c->first = c,c -> second = coo

Map.size() = 14
打印Map
a:aozi  b:baotou  b:yongbao  b:baoda  b:bao  c:chen  c:coo  c:coo  l:li  q:qian  s:sun  w:wang  z:zhao  z:zhou  

因为是multimap,允许重复元素,索引插入成功.
it2->first = e,it2 -> second = elicpse

mulmap.size() = 15
打印Map
a:aozi  b:baotou  b:yongbao  b:baoda  b:bao  c:chen  c:coo  c:coo  e:elicpse  l:li  q:qian  s:sun  w:wang  z:zhao  z:zhou  

auto it3 = Map.find('a'),it3->first = a, it3->second = aozi
Map.count('c') = 3

auto it4 = Map.find('c'),it4->first = c, it4->second = chen
auto it4 = Map.find('c'),it4->first = c, it4->second = coo
auto it4 = Map.find('c'),it4->first = c, it4->second = coo


Map.find('b'),beg->first = b, beg -> second = baotou
Map.find('b'),beg->first = b, beg -> second = yongbao
Map.find('b'),beg->first = b, beg -> second = baoda
Map.find('b'),beg->first = b, beg -> second = bao
删除'a' :1

打印Map
b:baotou  b:yongbao  b:baoda  b:bao  c:chen  c:coo  c:coo  e:elicpse  l:li  q:qian  s:sun  w:wang  z:zhao  z:zhou  

删除'c' :3

打印Map
b:baotou  b:yongbao  b:baoda  b:bao  e:elicpse  l:li  q:qian  s:sun  w:wang  z:zhao  z:zhou
*/
