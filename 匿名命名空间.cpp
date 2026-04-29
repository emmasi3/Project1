#include <iostream>
#include <memory>
#include <string>

namespace
{
	struct _RequestSizeIniter
	{
		_RequestSizeIniter()
		{
			//s_http_request_buffer_size = g_http_request_buffer_size->getValue();
			//s_http_request_max_body_size = g_http_request_max_body_size->getValue();

			//g_http_request_buffer_size->addListener(
			//	[](const uint64_t& ov, const uint64_t& nv) {
			//		s_http_request_buffer_size = nv;
			//	});

			//g_http_request_max_body_size->addListener(
			//	[](const uint64_t& ov, const uint64_t& nv) {
			//		s_http_request_max_body_size = nv;
			//	});
		}

	};

}
/*
* 1、这里的初始化结构体是用来在 main() 函数执行前，初始化完成配置模块工作的相关结构体
*	很显然，这样的结构体不会被用来在具体的工作方法中，它仅仅用来做结构体或者其他全局变量
*	的初始化工作，所以这样的结构体或者 类，一般要求仅当前文件可见，链接器不可见，也就是
*	要求使用 static 之类的语法修饰它，但是很明显
*	C++ 的 static 关键字，仅仅能修饰 变量、函数，他不能够修饰一个 class 后者 struct
*	这时候就要用到 匿名命名空间
*	也就是 namespace {}
*	将具备这些条件的结构体或者类放入，就可以达到和 static 一样的效果
*	
*	编译器会给这些命名空间添加程序运行时的唯一标识，仅当前文件可见
* 
* 2、 static 和 namespace{} 唯一的区别便是修饰的对象范围有所不同，效果都是等价的
* 
*/



int main()
{

	return 0;
}