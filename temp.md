## 我的首次解法
思路:
space complexity is
time complexity is

```c++

```


## 19. Remove Nth Node From End of List
```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * p1 = head;
        ListNode * p2 = head;
        int checked = 0;  // 即为size
        while (p2->next) {
            p2 = p2->next;
            ++checked;
            if (checked >= n - 1) {
                p1 = p1->next;                                                                           
            }
        }
        checked++;
        if (checked == n) {
            return p1->next;
        } else {
            // 此时p2指向最后一个节点.
            p1->next = p1->next->next; 
            return head;
        }    
    }
};

```




## 27. Remove Element 还需要再看下

