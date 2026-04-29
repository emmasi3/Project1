#include <iostream>
#include <fstream>
#include "yaml-cpp/yaml.h"

int main() {
    // 1、写入文件 data.yaml
    YAML::Node node;
    node["name"] = "Sakura";
    node["age"] = 20;

    YAML::Node hobbies;
    hobbies.push_back("Whale!");
    hobbies.push_back("e.what()");
    hobbies.push_back("你好世界！");

    node["hobbies"] = hobbies;


    std::fstream fs_out;
    fs_out.open("D:\\3\\Project1\\yaml_test文件\\data.yaml", std::ios::out);

    if (!fs_out.is_open())
    {
        std::cout << "Error to fs_out.open()!" << std::endl;
        return 0;
    }

    // 这里直接流式写入 node YAML节点
    fs_out << node;

    if (fs_out.is_open())
    {
        fs_out.close();
    }

    std::cout << "----------- 1、实验结束！----------" << std::endl;

    // 2、读文件
    // （1）从文件中加载YAML数据
    YAML::Node data = YAML::LoadFile("D:\\3\\Project1\\yaml_test文件\\data.yaml");
    
    // （2）读取数据
    std::string name = data["name"].as<std::string>();
    int age = data["age"].as<int>();
    const YAML::Node& hobbies_2 = data["hobbies"]; 
    // 不要疑惑，这里的data["hobbies"]临时变量的周期被延长了，因为有const，编译器就将这一句代码识别为两句
    // 上面这句话是有误的！！！，因为data["hobbies"]本身就是一直存在的，所有不算是临时对象，我之所以会有上面这句话，
    // 是因为 const int& a = (int)10; 这句代码完美符合我的第一句话，回忆一下

    std::vector<std::string> hobbiesList;

    // 1）这里完全可以用 [pos] 的方式来简便访问
    // 2）这里的 YAML::const_iterator 是因为 hobbies_2 被 const 修饰了，用 YAML::iterator 会出错
    for (YAML::const_iterator it = hobbies_2.begin(); it != hobbies_2.end(); it++)
    {
        hobbiesList.push_back(it->as<std::string>());
    }

    std::cout << "name: " << name << std::endl;
    std::cout << "age: " << age << std::endl;
    std::cout << "hobbies: ";

    for (const auto& it : hobbiesList)
    {
        std::cout << it << " ";
    }

    return 0;
}
/*
* 1、yaml的基本格式 ----   键值对，    关键字: 值
*
* 2、纯量、序列、映射
*
* 3、基本格式展示
* string: hello
*
* name:
*   - Jon
*   - Alex
*   - Bob
*   - KalaOk
*
* Person:
*   - name: Jon
*     age: 21
*   - name: Bob
*     age: 15
*   - name: Alex
*     age: 18
*
*
* 4、# 是注释，和python差不多
*
* 5、 name: 'ijk_player\n' ，这样的单引号，对于 \n没有什么作用，只是字符作用，和没加一样
*     name: "ijk_player\n" ，这里的 \n 直接就是换行符了
* 
* 6、formatter: "%d\t%m\n"   # \t 和 \n 会被解析成制表符与换行符
*    formatter: '%d\t%m\n'   # 原样保留 \t 和 \n 四个字符
* 
* 7、formatter: %d%t%m%n       这样的方式，是错误的，因为 % 是 yaml-cpp 的保留字符，需要加 "" || '' 才会被解析为纯文本
*
* 8、YAML::LoadFIle("log.yaml");  这里的log.yaml编码格式，必须为 utf-8，不能为 GB18030，解析库不认，会报错
* 
* 9、yaml 使用的时候，需要注意：
* 
*           node["level"] = (int)v.level;
* 
*   这段代码会报错：convert<T> 失败，无法转化的类型，这是因为 node["level"] 接收的只能是 c++ 的基础类型，而v.level是一个自定义的枚举(enum)类型
*   强转即可，以后遇到类似的报错，需要格外注意
* 
* 10、问题：来自 服务器项目 -- log.cpp -- LexicalCast<std::string, LogDefine>{} and
*   LexicalCast<std::string, LogAppenderDefine>{} 
*   （1）执行到 node["appenders"]的循环部分时，也就是将 node["appenders"]这个序列中的输出器
*       拿出来，i.as<std::string>()，也就是转换时，出现错误，显示转换失败？
*   （2）在 LogAppenderDefine的转换模块中，v.formatter = node["formatter"];
*       最终导致和（1）一模一样的错误，都是出在转换上
*   解决方案：
*   （1）因为 取出来的 appenderdefine 是一个map，不是一个纯量，所以 as<std::string>() 转换失败
*       直接用 stringstream ss << appenderdefine接收即可，然后使用 ss.str() 给到相应的转换模块
*       构建新的 LogAppenderDefine 结构体就好
*   （2）使用了（1）的解决方案后依然报错的原因：
*       在得到相应的 ss.str() 之后，转到 LexicalCast<std::string, LogAppenderDefine> 模块中
*       在里面有：lad.formatter = node["formatter"].as<std::string>(); 
*       但是，node["formatter"] 这个“键”一定存在吗？从我的test.yaml中来看，我就没有写啊
*       appenders:
*           - type: FileLogAppender
*             file: log.txt
*           - type: StdoutLogAppender
*       我的yaml文件是这样的，很明显 node["formatter"]就找不到嘛，那么
*       node["formatter"].as一定会报错的，所以
*       使用之前，一定要使用 node["formatter"].IsDefined() 判断是否存在，然后才能使用，否则报错
* 10 -（1）使用as<>() 时，一定要清楚，使用的对象，人家原本是什么东西，起码要能强制转换是吧？
*       但是从 map --> string 就有点为难人家了，当然，
*       appenderdefine.as<std::map<std::string, std::string>>();
*       这样的写法也是可以的，只不过还是要转换才能够达到为我们的目的，直接用 ss 很方便的
* 10 -（2）使用 node["formatter"] 给别的东西“赋值”之前，一定要判断这玩意是否存在，不存在
*       还要强制使用的话，就会报错
* 
*/
