#include <iostream>
#include <fstream>
#include <sstream>

uint32_t FileOpen(std::fstream& file)
{
	// 这里的 ios::ate 表示默认文件指针在末尾
	file.open("D:\\3\\Project1\\file\\test.txt", std::ios::binary | std::ios::ate | std::ios::in);

	if (!file.is_open())
	{
		std::cerr << "The file open is failure!" << std::endl;
		return false;
	}

	std::cout << "文件已经打开" << std::endl;

	// 这里使用 tellg() 返回当前文件指针所在位置，加上 ios::ate，就知道具体的字节数了
	return file.tellg();
}


int main()
{
	std::fstream file;
	uint32_t filesize = FileOpen(file);

	file.seekg(0, std::ios::beg); // 该API作用，将文件指针从 开始位置 偏移 x个位置，也就是从开始位置偏移0个位置，也就是移动到开始位置
								  // 换成 std:ios::ate 也一样，会移动到 末尾位置

	filesize = file.tellg();

	std::stringstream ss;
	ss.str("");
	ss <<'\n' << file.rdbuf() << '\n'; // 将这个文件内容都读取进入 stringstream 中，方便后续操作

	std::cout << ss.str();

	file.close();
	std::cout << "文件已关闭" << std::endl;

	return 0;
}