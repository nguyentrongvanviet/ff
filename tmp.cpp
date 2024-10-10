#include<bits/stdc++.h>
using namespace std ; 
/**
 */
struct ListNode {
      int val;
      ListNode *next;
    ListNode() : val(0), next(0) {}
    ListNode(int x) : val(x), next(0) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==0&&list2==0)return 0 ; 
        ListNode *res ; 
        ListNode *head = res; 
        int it = 0 ; 
        while(list1!=0||list2!=0)
        {
            ++it ; 
            int val1 = (list1==0?101:list1->val) ; 
            int val2 = (list2==0?101:list2->val) ; 
            if(val1<val2)
            {   
                res->val = val1 ;
                list1=list1->next; 
            }
            else
            {
                res->val=val2; 
                list2=list2->next;
            }
            if(list1==0&&list2==0)break;
            res->next= new ListNode() ;
            res=res->next ;
        }
        return head;
    }
};
signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    
}