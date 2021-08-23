#### 给定单链表的头结点head，返回反转后链表头指针

* `input: 1->2->3->4->5->nullptr`

* `output: 5->4->3->2->1->nullptr`


* 思路
  * **依次遍历**链表节点，每遍历一个节点就**逆置**一个节点
    * ![image-20210807193912993](链表逆序-a.assets/image-20210807193912993.png)
    * ![image-20210807193922841](链表逆序-a.assets/image-20210807193922841.png)
    * ![image-20210807193930026](链表逆序-a.assets/image-20210807193930026.png)
    * ![image-20210807193936383](链表逆序-a.assets/image-20210807193936383.png)
  * ![image-20210807194247693](链表逆序-a.assets/image-20210807194247693.png)

* 代码实现

  * ```c++
    ListNode* reverseList(ListNode* head){
        ListNode *new_head = NULL;
        while(head) {
            ListNode *next = head->next;
            head->next = new_head;
            new_head = head;
            head = next;
        }
        return new_head;
    }
    ```

  * ![image-20210807194856643](链表逆序-a.assets/image-20210807194856643.png)



