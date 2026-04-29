#include <iostream>
#include <map>

/*
* 1、此处以最近正在学习的项目 -- 服务器为主
*	multimap 相比于  map，同一个键 key 可以不同时指定不同的“值”
*	也就是他其中可能会有这种情况： 
*	<en-0, 12>、<en-0, 13>、<en-0, 500>；
*	那么如果我只要键值为 en-0 的序列呢？如何连续地访问他们？
*	multimap 中提供了 equal_range() 方法
*					成员	类型	含义
*	range.first		iterator	第一个 key == 指定值 的元素
*	range.second	iterator	第一个 key > 指定值 的元素
*	equal_range() 返回的是一个 pair<>，里面装着两个迭代器 -- 
*	一个是 第一个 key 的迭代器，另一个是 第一个 != key 的迭代器
*	当然，上句话这样说的原因是：multimap 本身就是一个有序的容器，
*	所以获取到 key 的序列后，使用 for(; its.first != its.second; ++its.first);
*	一定要注意 循环条件，嗯嗯，没了
*	
*/

int main()
{


	return 0;
}