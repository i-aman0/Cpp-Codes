void removeDuplicate(Node* head){
    if(head==NULL){
        return;
    }

    Node* curr=head;
    while(curr!=NULL){
        if((curr->next!=NULL) && curr->data==curr->next->data){
            Node* next_next=curr->next->next;
            Node* nodeToDelete=curr->next;
            delete nodeToDelete;
            curr->next=next_next;
        }
        else if(curr->next!=NULL){
            curr=curr->next;
        }
    }
}