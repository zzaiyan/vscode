#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct ListNode{
	T val;
	ListNode* next;
	ListNode(T x):val(x),next(nullptr){}
};

class Card{
    int num=0;
    string name,phone;
    double points=0;
public:
    Card()=default;
    Card(int a,string b,string c):num(a),name(b),phone(c){}
    void bill(double x){
        cout<<"姓名："<<name<<" ，本次消费："<<x<<" 元。\n";        
    }
    void rePoints(double x){
        points=x;
        cout<<"积分更新为："<<x<<" 分。\n";
    }
};

int main(){
    cout<<"请输入会员个数：";
    int n;cin>>n;
    int a;string b,c;
    cout<<"请输入 编号、姓名、手机号：\n";
    cin>>a>>b>>c;
    auto head=new ListNode<Card>(Card(a,b,c));
    auto tail=head;
    while(--n){
        cout<<"请输入 编号、姓名、手机号：\n";
        cin>>a>>b>>c;
        tail->next=new ListNode<Card>(Card(a,b,c));
        tail=tail->next;
    }
    for(auto p=head;p!=nullptr;p=p->next){
        p->val.bill((rand()%1000+1)/10.0);
        p->val.rePoints((rand()%1000+1)/10.0);
    }
    return 0;
}