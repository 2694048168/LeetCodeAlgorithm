# Google Python Style Guide
- [the link to Google Style](https://google.github.io/styleguide/pyguide.html)

### Python Version

- python2.7
- python3.5
- python3.6
- python3.7
- python3.8
- 使用python的版本之前，请考虑可移植性和一些自己常用包的支持性

### Import Packages

- 统一自己的使用风格
- 尽量与广泛社区使用的风格一致

```python
# 常用包的导入形式
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import tensorflow as tf
import cv2 as cv
import sklearn as sk

```

### Comments
- 建议参考 Doxygen 文档生成标准：https://www.doxygen.nl/index.html
- 单行注释风格 # ，多行注释风格 """ """
- 法律声明和作者，开源协议
- 文件内容，则文件级注释应大致描述文件的内容以及抽象之间的关系
- 不要在头文件和源文件中都重复注释，重复的注释应该有所不同
- 项目注释 + 文件注释 + 类注释 + 函数注释 + 结构体注释 + 枚举注释 + 变量注释 + 核心思想注释 + 特别技巧性注释


### Naming
- 命令整体规范：见名知意
- 文件名：全部单词小写，单词间隔使用下划线
- 类型名：首字母表征类型 U表征unsigned
- 普通变量名和结构体成员名：全部单词小写，使用下划线间隔单词
- 类成员数据名：全部单词小写，使用下划线间隔单词，最后使用一个下划线进行表征
- 类名、函数名、结构体名：全部单词首字母大写，不需要下划线间隔
- 常量名：小写 k 开头，其余全部单词首字母大写，不需要下划线间隔
- 对于不需要的变量，常使用 _ 来表示

