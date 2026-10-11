# data-structure

数据结构学习笔记与 C++ 示例，按课程分组整理。

## 目录结构

```text
data-structure/
├── README.md
├── Makefile
├── .gitignore
├── .clang-format
├── main.cpp
├── lesson_01/
│   └── exercises/
│       └── time_complexity_exercises.cpp
├── lesson_02/
│   ├── pass_by_value.cpp
│   ├── sequential_list_definition.cpp
│   ├── sequential_list_insert_delete.cpp
│   ├── sequential_list_search.cpp
│   └── singly_linked_list_definition.cpp
├── templates/
│   └── .gitkeep
└── build/                         # 本地编译产物，不纳入 Git
```

## 文件说明

| 文件 | 内容 |
| --- | --- |
| `main.cpp` | 根目录的值传递演示程序 |
| `lesson_01/exercises/time_complexity_exercises.cpp` | 时间复杂度分析练习片段 |
| `lesson_02/pass_by_value.cpp` | 函数参数的值传递示例 |
| `lesson_02/sequential_list_definition.cpp` | 顺序表定义、初始化与扩容 |
| `lesson_02/sequential_list_insert_delete.cpp` | 顺序表插入与删除 |
| `lesson_02/sequential_list_search.cpp` | 顺序表按位置取值与按值查找 |
| `lesson_02/singly_linked_list_definition.cpp` | 单链表定义、初始化与判空 |
| `templates/` | 预留的代码模板目录，使用 `.gitkeep` 保存空目录 |

部分文件是课堂代码片段，缺少独立编译所需的声明或入口，不适合将所有 `.cpp` 文件直接编译为一个程序。

## 命名规则

- 普通文件和目录使用英文小写字母与下划线（`snake_case`）。
- 课程目录使用两位编号，例如 `lesson_01`、`lesson_02`。
- 源文件使用描述内容的名称和 `.cpp` 扩展名，例如 `sequential_list_search.cpp`。
- `README.md`、`Makefile`、`.gitignore`、`.clang-format` 等标准文件保留惯用名称。
- 编译产物统一放入 `build/` 目录。

## 使用方式

编译并运行根目录的演示程序：

```bash
mkdir -p build
g++ main.cpp -o build/main
./build/main
```

安装 `clang-format` 后，可使用 `make fmt` 格式化项目中的 C/C++ 文件。
