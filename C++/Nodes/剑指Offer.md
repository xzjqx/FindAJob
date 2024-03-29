### 二维数组中的查找
- 找到一个足以判断大小的方向，依次查找即可

### 替换空格
- 从后往前替换比较方便

### 从尾到头打印链表
- 也可用递归方法从后向前打印

### 重建二叉树方向
- vector的下标只能获取已存在的数，不能作为数组初始化来使用方向

### 用两个栈实现队列
- C++中栈pop()函数返回void，用top()函数获取栈顶元素

### 旋转数组的最小数字
- 旋转数组的最小数字是第一个小于上一个数字的数

### 变态跳台阶
- 跳n阶的跳法数量等于前面所有跳法之和，通过计算可以发现:a[n]=2a[n-1]

### 矩形覆盖
- 斐波那契数列

### 二进制中1的个数
如果一个整数不为0，那么这个整数至少有一位是1。如果我们把这个整数减1，那么原来处在整数最右边的1就会变为0，原来在1后面的所有的0都会变成1(如果最右边的1后面还有0的话)。其余所有位将不会受到影响。**减1的结果是把最右边的一个1开始的所有位都取反**,这个时候如果我们再把原来的整数和减去1之后的结果做与运算，从原来整数最右边一个1那一位开始所有位都会变成0。把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0,那么一个整数的二进制有多少个1，就可以进行多少次这样的操作。

### 数值的整数次方
- 仔细看题，有可能有负整数次方

### 调整数组顺序使奇数位于偶数前面
- 使用插入排序实现

### 链表中倒数第k个结点
- 先确定链表中结点输了，再确定倒数第k个结点位置
- 别忘了判断是否溢出(k>count)

### 反转链表
- 反转链表要三个结点连着处理，持续推进，直到链表末尾
- 链表中赋值相当于将地址赋值过去，并不代表连接

### 合并两个排序的链表
- 若需要给链表赋值，且不仅仅是指针指向的赋值，则需要在链表初始化时进行内存分配

### 树的子结构
- 沿根节点往下，递归判断两树是否相同

### 二叉树的镜像
- 交换两子树后递归处理即可

### 顺时针打印矩阵
- 四个方向依次输出

### 包含min函数的栈
- 利用辅助数列存放最小值的位置

### 栈的压入、弹出序列
- 使用一个栈模拟，记住第一个for循环结束后，栈中可能还有数字，需要全部出栈

### 从上往下打印二叉树
- 广度优先搜索BFS的思路

### 二叉搜索树的后序遍历序列
- 递归思路，默认为升序排列

### 二叉树中和为某一值的路径
- 深度优先搜索的思路，搜索的过程中维持一个二维数组，用于记录所有路径；维持一个一位数组，用于记录一条路径；维持一个数，用于记录走到当前节点时，目标数字还剩多少
- DFS也能确保先找到最长的路径

### 复杂链表的复制
- 若要处理链表节点，记住一定要新建一个链表节点进行赋值，否则会出现想不到的错误

### 二叉搜索树与双向链表
- 二叉树的中序遍历
- 递归实现，先遍历左子树，找到左子树中最右边的结点，将其与根结点相连，再遍历右子树，将其最左边结点与根节点相连

### 字符串的排列
- next_permutation获取全排列中的下一个排列，记住用这个函数之前先给第一个排列排好序
- 将string转化为char\*后，改char\*的值就是改string

### 数组中出现次数超过一半的数字
- 排序后遍历
- 优化解法1：排序后，如果存在这样一个数，它一定是数组最中间的那个数
- 优化解法2：如果有符合条件的数字，则它出现的次数比其他所有数字出现的次数和还要多