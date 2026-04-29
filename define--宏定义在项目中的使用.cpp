#include <iostream>
#include <string>
/*
* 1、注意，使用该宏定义时，XX（）这个括号内的东西，只需要用2个逗号隔开即可，不要求和g_var···一模一样，
*    也就是给到3个参数即可，但是 XX 必须严格一致
* 
* 2、一旦需要用到 XX（）内的参数，就需要用到 # 号，可以将 prefix 转换为 "before" 字符串，name 也一样
* 
* 3、好像 #prefix " " #name ": " 这好像展开后，是多个“字符串面量”的串行，不符合语法规则？
*    GPT 告诉我，C++标准规定，多个相邻的字符串面量会被合并为一个字符串面量，额，不知道对不对
* 
*    下方的例子：XX(ni, hao);
*    输出：     nihao: 1
*    可以看出，直接将传进来的东西，当成字符串 "" 处理了，也算是合并了吧
* 
* 4、#define HOOK_FUN(XX) \
		XX(sleep) \
		XX(usleep)
*		
*	#define XX(name) name ## _f = (name ## _fun)dlsym(RTLD_NEXT, #name);
* 		HOOK_FUN(XX);
*	#undef XX
* 
* （1）这里的 #undef XX ，表示删除 XX 宏定义的使用，防止污染后续的代码
* （2）这里的宏定义，HOOK_FUN(XX); 最终展开是 给两个 函数指针 赋值，在 hook.h （服务器项目）中，可以去看
* （3）这里的 ## 号，表示将左右两边的 标识符 组成新的 1个标识符，注意，表示符 != 字符串，不一样！！！
* 
*/
void test1(const char* a,const char* b)
{
	std::cout << a << b;
}

#define XX(name, prefix) \
{ \
	std::cout << #name  #prefix ": " << 1; \
}

int main()
{
	//auto v = g_int_vec_value_config->getValue();
	//for (auto& i : v)
	//{
	//	SYLAR_LOG_INFO(SYLAR_LOG_ROOT) << "before int_vec: " << i;
	//}

	XX(ni, hao);

	// 输出：     "ni""hao": 1

	return 0;
}