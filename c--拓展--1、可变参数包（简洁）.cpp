#include <stdarg.h>
#include <iostream>
/*
void Log(Priority priority, const char* __file, const char* __func, int __line, const char* fmt, ...)
{
	std::unique_lock<std::mutex> lock(mutex_);

	char buf[2048] = { 0 };
	sprintf(buf, "[%s][%s:%s:%d] ", Priority_To_String[priority], __file, __func, __line);

	va_list args;
	va_start(args, fmt);
	vsprintf(buf + strlen(buf), fmt, args);
	va_end(args);

	this->Write(std::string(buf));
}

现在来逐行解读：
Priority 这是一个RTMP服务器中的枚举类型

1、fmt 是一个字符串常量，，例： "User ID: %d  FIle:%s  Line:%s  Func:%s"，其中的格式化字符，被后面的 ... 可变参数包来填充
	也就是说填充后的 fmt 就是这样的一个字符串

2、利用sprintf() 函数给日志写入缓冲区 buf 先写入标志信息，这和这个知识点没有一点关系

3、va_list 定义了一个指针（或者结构体）---由于 C 的库函数没有一个确定的形式，所以有可能是指针而已，这里就理解指针。
	args

4（X看后面）、使用 va_start(args,fmt) 指向 可变参数列表的第一个参数，不是 fmt ，而是你传进去的第一个参数
	那么问题来了，既然这个函数只是去处理args的，那么传入fmt做什么？

	| fmt              |  <- 固定参数
	| "This is a..."   |  <- 第一个可变参数
	| "Another ..."    |  <- 第二个可变参数
	| "End of log."    |  <- 第三个可变参数
	| nullptr          |  <- 结束标志

这是 fmt 和可变参数列表的一个内存布局，一定是这样的！！！这是一个“标准”，约定俗成的，为的就是通过获取 fmt 的地址（假设：0x1000）
那么第一个可变参数的地址就是 0x1000 + sizeof(fmt),以此类推，就可以获取所有的参数，也就是 args 可以遍历所有的 可变参数了，直到遇到 nullptr

	那么传入 fmt 的作用就是计算第一个参数的地址，便于 args->T ，这就是作用！！！

5、vsprintf()作用和sprintf()基本一致，参数也差不多，唯一的区别就是专门处理 va_list 的函数，写入缓冲区的对象都是 buf

6、va_end(args) 这就类似于 closesocket(socket_fd) 释放该指针，不让后面的东西意外使用，防止出现错误

相对于c++的可变参数包，这个明显更简单，无脑，符合正常思维，但是你可以很明显的看见，如果传入的参数不符合 fmt 的格式化字符，系统貌似提醒的不是太多，也就导致了
没有严格的类型检查机制，需要我们手动添加检查机制，但是c++的，直接使用模版来操作，强制规定了传入的参数和类型必须一致，否则直接退场，这也就是c++的类型安全

7、还有一个函数来着，你自己去查查吧，和 printf() 的内部实现有关

（4）、这里的内存分布正确，但是对于这样的东西是存放在寄存器中的，也就是--高地址--指向--低地址--，反过来的，并且，正确的查找方式应该是：
args先指向 fmt 地址 += sizeof(const char*)，注意，这里的自增 != sizeof(fmt)，而是指向 保存了fmt第一个字符地址的东西，也就是寄存器中放了
const char* 是一个参数所在地址，但并不是所有的参数类型都会保存一个地址，int -- 42，会直接将 42放到寄存器中，因为int的 sizeof(int)在同一个平台是确定
的，然后就往后 += sizeof(类型)就行了，直到读取到 nullptr为止

8、注意，这里的vsprintf()函数不等于 vasprintf() ，这个vas函数功能基本相同，都是给 buffer 中写入用 args填充好的 fmt，但是，
使用的时候， 
	char* buf = nullptr; 
	vasprintf(&buf, fmt, args);
	vsprintf(buf, fmt, args); 
	第一个完全正确，即使，buf本来指向空，但是内部会自动分配足够的内存空间给 buf
	第二个会报错，该函数不会给 buf 分配空间，直接会写入 fmt，所以报错，用这玩意，需要提前给 buf 分配空间。
	但是在 Windows/MSVC 上，是没有vasprintf() 的，只有在 Linux···才有

*/