### Google C++ Style Guide
- [the link to Google Style](https://google.github.io/styleguide/cppguide.html#C++_Version)

### Background

每个C++程序员都知道，该语言具有许多强大的功能，同时这种强大带来了复杂性，使得代码更易于出错，难以阅读和维护。
一套完整有效的编程风格或者注意事项就是用来管理这种复杂性，这些规则的存在是为了使代码库易于管理，同时仍然允许编码人员有效地使用C++语言功能。这些约定不仅涵盖源文件格式，还涉及更多内容。

### Goals of the Style Guide

本指南的核心目标，这些是构成所有单独规则的根本原因。清楚为何制定了规则以及为何做出了特定的决定。如果了解每条规则的目的是什么，则可以免除某条规则，从而便于源代码更好的阅读和管理维护。
本文档旨在提供具有合理限制的最大指导,与往常一样，编程常识和良好风格应占上风。通过这种方式，特别引用了整个Google C++社区的既定惯例，而不仅仅是个人喜好或团队的个人喜好。

**The goals of the style guide as follows:**

- Style rules should pull their weight(每一条风格规则应发挥其作用)
- Optimize for the reader, not the writer(针对读者而非专家进行优化)
- Be consistent with existing code(与现有的代码保持一致)
- Be consistent with the broader C++ community when appropriate(尽量与广泛的社区保持一致)
- Avoid surprising or dangerous constructs(避免令人惊讶或者危险结构)
- Avoid constructs that our average C++ programmer would find tricky or hard to maintain(避免使用普通C++程序员难以维护的结构)
- Be mindful of our scale(注意程序源代码的规模)
- Concede to optimization when necessary(必要时考虑进行优化)

### C++ Version

- [C++ standard](https://isocpp.org/std/status)
- C++ 98
- C++ 11
- C++ 14
- C++ 17
- C++ 20
- 使用C ++ 14和C ++ 17的功能之前，请考虑可移植到其他环境的问题

### Header Files

- 自己的习惯用法，用于区别 C 和 C++ 代码文件
- .c and .h , just for C , just for me
- .cpp and .hpp , just for C++ , just for me
- 所有头文件都应具有 #define 防护措施，以防止多次包含
- 符号名称的格式应为 <PROJECT>_<PATH>_<FILE>_H_
- 为了保证唯一性，它们应基于项目源代码树中的完整路径
- 这个预处理宏名，全部大写，标准格式如下代码所示
- 尽量将变量前向声明添加到一个头文件中，进行包含使用
- 尽量只包含需要使用的变量的头文件
- 内联函数定义和声明都在头文件中，10源代码或者更少时才定义内联函数
- 头文件包括的顺序，顺序：相关头文件，C系统头文件，C++标准库头文件，第三方库的头文件，本项目的头文件
- 每一类别头文件顺序后，使用一个空行来进行表征
- 头文件包括的名称，名称：项目的所有头文件都应列为项目的源目录的后代，而不使用UNIX目录别名
- 除了C和C++的库文件使用 <> 进行包含外，自定义和第三方库头文件使用 " " 进行包含


```C++
#ifndef PROJECT_PATH_FILE_H_
#define PROJECT_PATH_FILE_H_

#endif // PROJECT_PATH_FILE_H_
```

```C++
// Related header
#include "foo/server/fooserver.h"

// C system headers
#include <sys/types.h>
#include <unistd.h>

// C++ standard library headers
#include <string>
#include <vector>

// other 3rd libraries' headers
#include "base/basictypes.h"
#include "base/commandlineflags.h"

// your project's headers
#include "foo/server/bar.h"

// 条件包含头文件，解决不同C++ 标准版本支持的头文件
#ifdef LANG_CXX11
#include <initializer_list>
#endif  // LANG_CXX11
```

### Comments
- 建议参考 Doxygen 文档生成标准：https://www.doxygen.nl/index.html
- 单行注释风格 // ，多行注释风格 /* */
- 法律声明和作者，开源协议
- 文件内容，则文件级注释应大致描述文件的内容以及抽象之间的关系
- 不要在头文件和源文件中都重复注释，重复的注释应该有所不同
- 项目注释 + 文件注释 + 类注释 + 函数注释 + 结构体注释 + 枚举注释 + 变量注释 + 核心思想注释 + 特别技巧性注释

```C++
/**
 * @mainpage  智能井盖固件程序
 * <table>
 * <tr><th>Project  <td>ble_app_smc 
 * <tr><th>Author   <td>wanghuan 
 * <tr><th>Source   <td>E:\keil_workspace\NORDIC\nRF52832_htwh_sdk15.0\examples\ble_peripheral\ble_app_smc_freertos-doxygen
 * </table>
 * @section   项目详细描述
 * 通过智能井盖管理系统的部署，管理人员通过手机APP与管理平台就能对辖区内井盖的安装、开闭、状态进行管理，出现异常情况及时通知维护人员进行检修，保障排水正常，保障市民安全。
 *
 * @section   功能描述  
 * -# 本工程基于蓝牙新品nRF52832开发
 * -# 本工程基于蓝牙协议栈开发，协议栈版本 SDK-15.0
 * -# 智能井盖采用NB-IoT模组为ME3616
 * 
 * @section   用法描述 
 * -# 智能井盖检测器安装指导
 * -# 智能井盖检测器使用前需配置使能
 * 
 * @section   固件更新 
 * <table>
 * <tr><th>Date        <th>H_Version  <th>S_Version  <th>Author    <th>Description  </tr>
 * <tr><td>2018/08/17  <td>1.0    <td>S02010041808171   <td>wanghuan  <td>创建初始版本 </tr>
 * <tr><td>2019/06/24  <td>1.3    <td>S02010041906241   <td>wanghuan  <td>
 * -# 电信平台增加上报需应答，应答超时时间默认40s；\n 
 *       代码宏：ME3616_NOTIFY_NEED_RPLY_EN
 * -# 新增PSM进入超时处理，默认超时处理模组关机，超时时间默认200s；\n
 *       代码宏：ME3616_PSM_TIMEOUT_HANDLE_EN
 * -# 信号强度获取接口函数修改，增加可靠性，详见 me3616_getSignal()； 
 * -# 调试指令新增周期上报测试指令，710A-0D
 * </tr>
 * </table>
 */
```

```C++
/**
 * @copyright Copyright (C) 2000-2008, Intel Corporation, all rights reserved.
 * @author weili
 * @file main.cpp
 * @brief 文件简要描述
 * @details 文件内容以及抽象关系详细描述
 * @date 2020-10-01
 * @version V1.0
 * @attention
 */
```

```C++
/**
 * @brief NB模组向云平台上报数据
 * @param[in]  handle              NB模组驱动句柄
 * @param[in]  *data                上报数据指针
 * @param[in]  len                上报数据长度
 * @param[in]  rcc_enabled          上报时是否主动释放RCC链接
 * @param[in]  update_enabled    上报时是否更新注册(只适用于onenet)
 * @param[in]  report_fail_try_type    上报失败重新注册类型 \n
 * @ref NB_REPFAIL_REG_TRY 出错立即重试    \n
 * @ref NB_REPFAIL_REG_DELAY_TRY 出错延缓重试，在延迟期间如果正常则重新延缓，适用于高频率上报（上报失败重新注册超时15min） \n
 * @ref NB_REPFAIL_REG_NO_TRY 出错不重试
 * @return  函数执行结果
 * - NB_NOTIFY_SUCCESS      上报成功
 * - NB_NOTIFY_FAIL        上报失败
 * - NB_IOT_REGIST_FAILED 注册失败返回
 * - Others  其他错误
 * @par 示例:
 * @code
 *    移动平台发送数据 AT+MIPLNOTIFY=0,122553,3308,0,5900,4,4,50,0,0
 *    电信平台发送数据 AT+M2MCLISEND=000101
 * @endcode
 * @see :: ME3616_FxnTable
 */
```

```C++
/**
 * @enum NB_msg_types_t
 * @brief 定义驱动上报应用消息类型
 */

/**
 * @struct ME3616_info_t
 * @brief ME3616信息结构体 \n
 * 定义存储ME3616的信息
 */
typedef struct 结构体名字
{
   成员1, ///< 简要说明文字 */ 如果不加<，则会认为是成员2的注释
   成员2, ///< 简要说明文字 
   成员3, ///< 简要说明文字 
}结构体别名；
```

### Naming
- 命令整体规范：见名知意
- 文件名：全部单词小写，单词间隔使用下划线
- 类型名：首字母表征类型 U表征unsigned
- 普通变量名和结构体成员名：全部单词小写，使用下划线间隔单词
- 类成员数据名：全部单词小写，使用下划线间隔单词，最后使用一个下划线进行表征
- 类名、函数名、结构体名：全部单词首字母大写，不需要下划线间隔
- 常量名：小写 k 开头，其余全部单词首字母大写，不需要下划线间隔

```C++
// 文件名
cpp_code_style.cpp
cpp_code_style.hpp

// 类型名
using uInt = unsigned int;
using iVec = vector<int>; 

// 普通变量名
int a_integer_number = 0;

// 常量名
const int kIteration = 10000;

// 函数名
void PrintScore()
{

   return 0;
}

// 结构体
typedef struct Student
{
   std::string name;
   int age;
   int grade;
   double score;
}

// 类
class StudentPrintScore
{
public:
    void PrintScore();
private:
    std::string student_name_;
}
```

