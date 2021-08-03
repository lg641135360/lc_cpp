#### 给定单链表的头结点head，返回反转后链表头指针

* input: 1->2->3->4->5->nullptr

* output: 5->4->3->2->1->nullptr

  

##### 应掌握递归和非递归写法

* 递归写法

  * ```c++
    // 添加一个默认参数prev指向当前节点的前驱
    ListNode* reverseList(ListNode* head,ListNode *prev=nullptr) {
        // base case
        if(!head) return prev;
        // prev指向末尾，这里逆转了当前指针指向，然后将更小规模的问题交给下一次递归
        ListNode *next = head->next;
        head->next = prev;
        return reverseList(next,head);
    }
    ```

* 非递归写法

  * ```c++
    ListNode* reverseList(ListNode* head){
        // 需要前驱与后继
        ListNode *prev = nullptr,*next;
        while(head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    ```

    

