class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ans = new ListNode();
        ListNode *temp = head, *temp1 = head, *ans_temp = ans;
        stack<ListNode*> stack;
        int count=0, size=0;
        while(temp!=NULL){
            if(count<k){
                stack.push(temp); temp1 = temp1->next;
            }
            count++; temp = temp->next;
        }
        int times = (count-k)/k;
        size = stack.size();
        for(int j=0; j<size; j++){
            ans_temp->next = stack.top(); stack.pop();
            ans_temp = ans_temp->next;
        }
        for(int i=0; i<times; i++){
            for(int j=0; j<k; j++){
                stack.push(temp1); 
                if(temp1==NULL){break;}
                temp1 = temp1->next;
            } 
            for(int j=0; j<k; j++){
                ans_temp->next = stack.top(); stack.pop();
                ans_temp = ans_temp->next;
                // cout<<ans_temp->val<<endl;
            }
        }
        ans_temp->next = temp1;
        return ans->next;
    }
};
