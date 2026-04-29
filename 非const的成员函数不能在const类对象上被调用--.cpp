#include <iostream>
#include <string>

class Person
{
public:
	bool operator==(const Person& v) const
	{
		return m_name == v.m_name && m_age == v.m_age && m_sex == v.m_sex;
	}

private:
	std::string m_name = "";
	int m_age = 0;
	bool m_sex = false;
};

int main()
{
	Person a, b;
	bool c = (a == (const Person&)b);

	return 0;
}
/*
* 问题：在我的 服务器项目中：setValue()函数中，涉及到一个变更事件，因此去更新ConfigVar的 m_val 成员变量，
*		此时就需要去比较 old_val 和 new_val了，直接用 == ，对于自定义类型直接去重载 == 就行，事实上我也这么做了，
*		setValue() 是：
* 		void setValue(const T& v) 
		{	
			if (v == m_val)
			{
				return;
			}

			for (auto& i : m_cbs)
			{
				i.second(m_val, v);
			}
			m_val = v;
		}
*		很显然，v也就是 == 函数的调用者是一个 const 修饰的，m_val仅仅是一个 T 类型的，没有修饰，但是报错，显示什么么有合适的转化什么的？
*		自定义函数，和上面的这个文件的 函数差不多一致
* 
* 1、非 const 的成员函数不能在 const 对象上被调用。
*    为什么呢？
*    来看一个逻辑昂！
*	（1）常量对象：被const修饰的对象，它的成员变量自带 const 修饰，也就是无法改变，但是在类的定义部分，很有可能在成员函数中有修改成员变量的“行为”
*				那么问：此时const修饰的对象，调用该函数合理吗？很显然不合理，是吧？
*				这就和在服务器项目中遇到的问题一样，const T& v，调用的成员函数必须是 const 修饰的，避免出现这种逻辑上漏洞
*	（2）非常量对象：没有被 const 修饰的，它的成员函数没有这么多限制，const 修饰也好，不修饰也罢，都不会引发“逻辑”上的漏洞
*	所以解决方案很明显了：在函数参数列表后加 const，修饰函数体中的所有对象
* 
* 2、main() 函数中，bool c = a == b；如果写成这样，会报错，显示有歧义，也就是让编译器产生了误会，假设：
*	h(int, double), h(int, int) ，俩重载函数，调用时h(10, 20) ，编译器不知道调用哪一个，所以有“歧义”，简单做法是：
*	h(10, (int)20)，就会很清楚， == 函数报错的原因和这个一模一样，是因为 C++20开始，有时候编译器会自己生成一个 == 重载运算符函数，咱们写的和人家的
*	重载了，所以他不知道调用哪一个，嗯嗯，大概是这样子的
*/