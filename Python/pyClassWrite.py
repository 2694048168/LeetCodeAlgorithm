# python 中一切皆对象，故此有 类对象和通过类创建的实例对象，也就是说类本身就是一个对象
# 对象都有 属性 和 方法，故此类对象有 类属性 和 类方法，实例属性和实例方法
# 在类的内部同时在所有方法之外的变量都是类属性，在实例方法中的变量是实例属性
# 只需要访问类属性，不需要访问实例属性，则定义类方法 @classmethod，第一个参数为 cls，代表类对象本身
# 不需要访问实例属性，也不需要访问类属性，则定义静态方法 @staticmethod
# 需要同时访问类属性和实例属性，则定义实例方法，第一个参数为 self，代表实例对象本身
#
# python class create
#
# 类的组成
# 1、类属性：类中方法之外的变量称之为类属性，被该类的所有对象所共享
# 2、实例方法：普通函数方法
# 3、静态方法：使用 @staticmethod 修饰的方法，使用类名直接访问的方法
# 4、类方法：使用 @classmethod 修饰的方法，使用类名直接访问的方法
#
# 普通实例方法，第一个参数需要是self，它表示一个具体的实例本身。
# 如果用了 @staticmethod，那么就可以无视这个 self，而将这个方法当成一个普通的函数使用。
# 而对于 @classmethod，它的第一个参数不是 self，是 cls，它表示这个类本身。
class Solution:
    # 类属性
    native_place = "guizhou"

    # name, age 为实例属性
    def __init__(self, name, age):
        self.name =  name
        self.age = age

    # 实例方法
    def info(self):
        print("My name is ", self.name)
        print("My age is ", self.age)

    # 类方法
    @classmethod
    def class_method(cls):
        print("这是类方法！")
    
    # 静态方法
    @staticmethod
    def static_method():
        print("这是静态方法！")


# Python 继承
#
# python 中所有继承的父类从 object 开始
class Person(object):
    def __init__(self, name, age):
        self.name =  name
        self.age = age

    def info(self):
        print("My name is {}， age is {} ".format(self.name, self.age)

# 定义子类进行继承
class Student(Person):
    def __init__(self, name, age, score):
        super().__init__(name, age)
        self.score = score

    
