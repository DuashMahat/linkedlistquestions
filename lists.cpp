#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode * next;
  ListNode (int _val) : val (_val) , next (NULL) {}
};

// [10]-> [11] -> 
ListNode * createList (int a[]  , int size ) {
  ListNode * head = new ListNode (0);
  ListNode * curr = head;
  for (int i = 0; i < size; ++i ) {
    curr->val = a[i];
    if ( i == size - 1 ) {
      curr->next = NULL;
      break;
    }
    curr->next = new ListNode(0);
    curr = curr->next;
  }
  return head;
}

void displayList ( ListNode * head ) {
   ListNode * temp = head;
   while (temp) {
     cout << temp->val << " -> ";
     temp = temp->next;
   }
   cout << endl;
}

/* sumlist / add too numbers  */ 
ListNode * sumlist ( ListNode * a , ListNode * b ) {
   if (!a  &&  !b ) return NULL;
   ListNode * temp = new ListNode (0);
   ListNode * ptr = temp;
   int carry = 0;
   while ( a != NULL  ||  b != NULL ) {

      if ( a == NULL ) {
        ptr->next = new ListNode ((b->val + carry) % 10);
        carry = (carry + b->val) / 10;
        b = b->next;
      } else if (  b == NULL ) {
        ptr->next = new ListNode ((a->val + carry) % 10);
        carry = (carry + a->val) / 10;
        a = a->next;
      }
      else {
        ptr->next = new ListNode ((b->val + a->val + carry) % 10);
        carry = (carry + b->val + a->val ) / 10;
        a = a->next;
        b = b->next;
      }
      ptr = ptr->next;
   }
   if (carry == 1 ) ptr->next = new ListNode(1);
   return temp->next;
}

/* Remove Nth Node From End of */

 // 1->2->3->4->5
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || head->next == NULL ) return NULL;
        ListNode * curr = new ListNode(0);
        curr->next = head;
        ListNode * first = curr;
        ListNode * sec = curr;
        while (n-- > 0 ) {
            first = first->next;
        }
        while (first->next) {
          first = first->next;
          sec = sec->next;
        }
        
        sec->next = sec->next->next;
        return curr->next;
        
    }

/* swap Nodes in pairs */
ListNode* swapPairs(ListNode* head) {
        if (!head ) return NULL;
        int num = 2;
        ListNode *cur = head;
        for (int i = 0; i < num ; ++i) {
            if (!cur) return head;
            cur = cur->next;
        }
        ListNode *new_head = reverse(head, cur);
        head->next = swapPairs(cur);
        return new_head;
    }
    
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode *pre = tail;
        while (head != tail) {
            ListNode *t = head->next;
            head->next = pre;
            pre = head;
            head = t;
        }
        return pre;
   }

ListNode *  palindromeList ( ListNode * head )  {
  /*
   1  -> 2  -> 3 ->  4 ->  5 

  */
   ListNode * ptr = head , * previous = NULL , *temp;
   while (ptr) {
      temp = ptr->next;
      ptr->next = previous;
      previous = ptr;
      ptr = temp;
   }
//    return NULL;
   head = previous;
   return head;
}

/*merge two sorted lists */
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       if (!l1  && !l2 )  return NULL;
       vector<int> v;
       ListNode * res  = new ListNode(0) , *temp = res; 
       while (l1) {
         v.push_back(l1->val);
         l1 = l1->next;
       }
        while (l2) {
         v.push_back(l2->val);
         l2 = l2->next;
       }
       sort(v.begin() , v.end());
       for (auto value  : v  ) {
         res->next = new ListNode(value);
         res = res->next;
       }
       return temp->next;  
    }

/*merge k  lists */

 ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0 ) return NULL;
        ListNode * temp = new ListNode(0) , *res = temp;
        vector<int> v;
        for (auto node : lists ) {
          while (node ) {
            v.push_back(node->val);
            node = node->next;
          }
        }
        sort (v.begin() , v.end());
        for (auto value : v ) {
          temp->next = new ListNode(value);
          temp = temp->next;
        }
        return res->next;
        
    }

/*reverse nodes in k groups */
ListNode* reverseKGroup(ListNode* head, int k) {
       if (!head ) return NULL;
       ListNode * cur = head;
        for (int i = 0; i < k; ++i) {
            if (!cur) return head;
            cur = cur->next;
        }
        ListNode *new_head = reverse(head, cur);
        head->next = reverseKGroup(cur, k);
        return new_head;
    }
  
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode *pre = tail;
        while (head != tail) {
            ListNode *t = head->next;
            head->next = pre;
            pre = head;
            head = t;
        }
        return pre;
    }

int main() {
  // (7-> 1 -> 6) + (5 -> 9 -> 2).
   int a[] = {7,1,6};
   int b[] = {5,9,2};
   int c[] = {1,2,3,4,5};
   ListNode * aa = createList(a, 3);
   ListNode * bb = createList(b ,3);
   ListNode * test = sumlist (aa , bb);
   ListNode * cc = createList(c , 5);
   cc = palindromeList(cc);
   displayList(test);
   displayList(cc);
}
