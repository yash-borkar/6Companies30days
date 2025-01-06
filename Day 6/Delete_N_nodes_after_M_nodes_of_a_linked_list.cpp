// https://www.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1

class Solution
{
    public:
    
    int getLength(struct Node  *head){
        int size = 0;
        Node *temp = head;
        while(temp){
            size++;
            temp = temp->next;
        }
        return size;
    }
    
    void linkdelete(struct Node  *head, int M, int N)
    {
        int size = getLength(head);
        Node *temp = head;
        
        int pos = 1;
        while(temp){
            if(pos%M == 0){
                int count = N;
                Node *nextNode = temp->next;
                while(count--){
                    if(nextNode) nextNode = nextNode->next;
                }
                temp->next = nextNode;
            }
            temp = temp->next;
            pos++;
        }
        
        
    }
};
