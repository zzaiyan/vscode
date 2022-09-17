#include<bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define pi 3

//抽象基类
class Shape{
	int value;//价值
	string name="基类";
public:
	Shape(int a,string b):value(a),name(b){}
	virtual ~Shape(){}
	virtual int getArea()=0;
	int getValue(){return value;}
	string getName(){return name;}
	bool operator<(Shape& a){return getArea()<a.getArea();}
};
//圆柱类
class Cylinder:public Shape{
protected:
	double r,h;//半径，高
public:
	Cylinder(int v,double a,double b,string c="圆柱体"):Shape(v,c),r(a),h(b){}
	int getArea(){return pi*r*r*h+0.5;}
};
//长方体类
class Cuboid:public Shape{
	double x,y,z;//长，宽，高
public:
	Cuboid(int v,double a,double b,double c):Shape(v,"长方体"),x(a),y(b),z(c){}
	int getArea(){return x*y*z+0.5;}
};
//圆锥类
class Circular:public Cylinder{
public:
	Circular(int v,double a,double b):Cylinder(v,a,b,"圆锥体"){}
	int getArea(){return pi/3*r*r*h+0.5;}
};
//体积比较函数
bool cmp(Shape* a,Shape* b){
	return a->getArea() < b->getArea();
}
//容器类
class Container{
	int size;
	vector<Shape*> vec;
public:
	Container(int a):size(a){}
	//释放动态资源
	~Container(){for(Shape* i:vec)delete i;}
	//显示内容
	void show(){
		cout<<"--以下为容器内容--\n";
		for(Shape* i:vec)cout<<"形状 "<<i->getName()<<" , 体积 "
			<<i->getArea()<<" , 价值 "<<i->getValue()<<endl;
	}
	//信息输出接口
	int getSize(){return size;}
	int getVecSize(){return vec.size();}
	
	int getArea(int x){return vec[x]->getArea();}
	int getValue(int x){return vec[x]->getValue();}
	//自排序函数
	void doSort(){
		sort(vec.begin(),vec.end(),cmp);
	}
	//动态尾插元素
	void pushCylinder(int v,double x,double y){
		vec.push_back(new Cylinder(v,x,y));
	}
	void pushCuboid(int v,double x,double y,double z){
		vec.push_back(new Cuboid(v,x,y,z));
	}
	void pushCircular(int v,double x,double y){
		vec.push_back(new Circular(v,x,y));
	}
};

int solve(Container& ct){
    //物品数量，容器容积
	int N=ct.getVecSize(),V=ct.getSize();
    //dp数组，体积数组，价值数组
	int dp[MAXN]{0},w[MAXN]{0},v[MAXN]{0};
	//读入数据
	for(int i=1;i<=N;++i){
		w[i]=ct.getArea(i-1);
		v[i]=ct.getValue(i-1);
	}
	//动态规划求解
	for (int i=1;i<=N;++i)
		for (int j=V;j>=w[i];--j)
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
	return dp[V];
}

int main(){
	//初始化容器，设置容积
	Container ct(104);
	//输入数据
	ct.pushCircular(350,1,25);
	ct.pushCylinder(400,1,11.7);
	ct.pushCuboid(450,3,3,5);
	ct.pushCylinder(20,1,1.7);
	ct.pushCircular(70,1,25);
	ct.pushCuboid(8,1,2,3);
	ct.pushCircular(5,1,2);
	ct.pushCuboid(5,1,2,1);
	//展示内容并排序
	ct.show();
	cout<<"----排序成功----\n";
	ct.doSort();
	ct.show();
	//调用函数dp求解
	cout<<"\n可容纳物品的最大价值为 "<<solve(ct)<<endl;
	
	return 0;
}