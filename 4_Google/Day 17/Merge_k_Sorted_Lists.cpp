// https://leetcode.com/problems/merge-k-sorted-lists/

class compare{
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        //process first k elements
        
        for(int i=0; i<lists.size(); i++){
            ListNode* listHead = lists[i]; 
            if(listHead != NULL) pq.push(listHead);
        }
        
        ListNode* head = NULL; 
        ListNode* tail = NULL; 
        ListNode* listtailHead = NULL;

        while(!pq.empty()){
            ListNode* topNode = pq.top();
            pq.pop();

            //first Node
            if(head == NULL){
                head = topNode;
                tail = topNode;
                if(tail->next != NULL) pq.push(tail->next);
            }
            else{
                tail->next = topNode;
                tail = topNode;
                if(tail->next != NULL) pq.push(tail->next);
            }
        }
        return head;
    }
};