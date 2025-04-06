#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class node{
    private:
        int freq;
        char c;
        node*left;
        node*right;
        int time;
    public:
        node(int f=0,char ch='~',node*l=NULL,node*r=NULL,int t=0){
            freq=f;
            c=ch;
            left=l;
            right=r;
            time=t;
        }
        char getC(){return c;}
        int getFreq(){return freq;}
        int getTime(){return time;}
        node* getleft(){return left;}
        node* getright(){return right;}
        void setLeft(node*l){left=l;}
        void setRight(node*r){right=r;}
};
class cmp{
    public:
        bool operator()(node*n1,node*n2){
            if(n1->getFreq()!=n2->getFreq())return (n1->getFreq())>(n2->getFreq());
            if(n1->getC()!=n2->getC())return (n1->getC())>(n2->getC());
            return (n1->getTime())>(n2->getTime());
        }
};
void printTree(node*root){
    if(root->getleft()==NULL&&root->getright()==NULL){cout<<(char)(root->getC());return;}
    cout<<'(';
    printTree(root->getleft());
    cout<<',';
    printTree(root->getright());
    cout<<')';
}
class CodeBook{
    protected:
        vector<int>freq_table;
        //0-9 will indicate digits 0-9
        //10-35 will indicate upper case alphabets
        //36 will indicate '_'
        //37-62 will indicate lower case alphabets
    public:
        CodeBook(string s=""){
            freq_table.assign(63,0);
            for(char c:s){
                if(c>='0'&&c<='9')freq_table[c-'0']++;
                else if(c>='A'&&c<='Z')freq_table[c-'A'+10]++;
                else if (c=='_')freq_table[36]++;
                else freq_table[62+c-'z']++;
            }
        }
        CodeBook(vector<int>&arr){
            freq_table=arr;
        }
        void print_book(){
            for(int i=0;i<63;i++){
                if(freq_table[i]!=0){
                    if(i<10)cout<<i;
                    else if(i<=35)cout<<(char)('A'+i-10);
                    else if(i==36)cout<<'_';
                    else cout<<(char)('a'+i-37);
                    cout<<" "<<freq_table[i]<<'\n';
                }
            }
        }
};
class huffman_tree: public CodeBook{
    private:
        node*root;
        void construct_tree(){
            int t=0;
            priority_queue<node*,vector<node*>,cmp>pq;
            for(int i=0;i<63;i++){
                if(freq_table[i]==0)continue;
                char c;
                if(i<10)c=i+'0';
                else if(i<=35)c=(char)('A'+i-10);
                else if(i==36)c='_';
                else c=(char)('a'+i-37);
                node*n=new node(freq_table[i],c,NULL,NULL,t);
                t++;
                pq.push(n);
            }
            //now the pq contains all nodes
            while(!pq.empty()){
                node*upar1=pq.top();
                pq.pop();
                if(pq.empty()){root=upar1;break;}
                node*upar2=pq.top();
                pq.pop();
                node*nxt=new node(upar1->getFreq()+upar2->getFreq(),'~',upar1,upar2,t);t++;
                pq.push(nxt);
                if(pq.empty()){root=nxt;break;}
            }
        }
    public:
        huffman_tree(vector<int>&fre):CodeBook(fre){
            root=NULL;
            construct_tree();
        }
        void print_tree(){
            printTree(root);
            cout<<';'<<'\n';
        }
};
int main(){
    string command;
    cin>>command;
    while(command!="Quit"){
        if(command=="BuildFrequencyTable"){
            string s;
            cin>>s;
            CodeBook c(s);
            c.print_book();
        }else if(command=="BuildTreeFromFrequencyTable"){
            int n;
            cin>>n;
            vector<int>freq_table(63);
            for(int i=0;i<n;i++){
                char c;
                cin>>c;
                int f;
                cin>>f;
                if(c>='0'&&c<='9')freq_table[c-'0']=f;
                else if(c>='A'&&c<='Z')freq_table[c-'A'+10]=f;
                else if (c=='_')freq_table[36]=f;
                else freq_table[62+c-'z']=f;
            }
            huffman_tree hf(freq_table);
            hf.print_tree();
        }cin>>command;
    }
}