### 快速排序的介绍
快速排序(quick sort)的采用了分治的策略。

- 分治策略指的是：
将原问题分解为若干个规模更小但结构与原问题相似的子问题。递归地解这些子问题，然后将这些子问题的解组合为原问题的解。
- 快排的基本思想是：
  在序列中找一个划分值，通过一趟排序将未排序的序列排序成 独立的两个部分，其中左边部分序列都比划分值小，右边部分的序列比划分值大，此时划分值的位置已确认，然后再对这两个序列按照同样的方法进行排序，从而达到整个序列都有序的目的。


参考链接：https://www.jianshu.com/p/2b2f1f79984e


```
def quick_sort(L):
    return q_sort(L, 0, len(L)-1)

def q_sort(L, left, right):
    if left < right:
        privot = partition(L, left, right)

        q_sort(L, left, privot-1)
        q_sort(L, privot+1, right)

def partition(L, left, right):
    privot = L[left]

    while left < right:
        while left < right and L[right] >= privot:
            right -= 1
        L[left] = L[right]

        while left < right and L[left] <= privot:
            left += 1
        L[right] = L[left]

        L[left]=privot
    return left
```
