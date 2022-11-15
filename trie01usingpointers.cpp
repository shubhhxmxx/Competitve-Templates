typedef struct node{
    int cnt;
    node* bit[2];
    node(){
        cnt=0;
        bit[0]=bit[1]=NULL;
    }
} Trie;
Trie * root;


void insert(int x){
   // error(1,x);
    Trie* temp=root;
    for(int i=30;i>=0;i--){
        int bt=(x>>i)&1;
        if(!temp->bit[bt]){
            temp->bit[bt]=new Trie();
        }
        temp=temp->bit[bt];
        temp->cnt++;
    }
}
void remove(int x){
    //error(2,x);
    Trie *temp=root;
    for(int i=30;i>=0;i--){
        int bt=(x>>i)&1;
        temp=temp->bit[bt];
        temp->cnt--;
    }
}
int maxxor(int x){
   // error(3,x);
    int ans=0;
    Trie* temp=root;
    for(int i=30;i>=0;i--){
        int bt=(x>>i)&1;
        if(temp->bit[!bt] && temp->bit[!bt]->cnt){
            ans=ans|(1<<i);
            temp=temp->bit[!bt];
        }
        else temp=temp->bit[bt];
    }
    return ans;
}
int main(){
    root=new Trie();
    insert(0);
}
