#include<iostream>
#include<string.h>
using namespace std;
char ar[40][15];
class shape{
	public:

	    ~shape(){cout<<"*****Thank you****"<<endl;}
		virtual double area(void){ return 0;	}
		virtual double volume(void){ return 0; }
};
void update(char s[15],int l,int p=0){
if(l<30){
strcpy(ar[l],s);
}
else {
    for(int i=0;i<p;i++){
        cout<<ar[i]<<endl;
        cout<<endl;
    }}}
class triangle:public shape{
public:
int h,b;
double area(void){ return 0.5*h*b; }
friend istream& operator>>(istream& in,triangle &a){
	cout<<"triangle"<<endl;
	cout<<"base: ";
	in>>a.b;
	cout<<"height: ";
	in>>a.h;
	return in; }
};
class cube:public shape{
public:
int h,w,d;
double area(void){ return 2*(h*w+w*d+d*h); }
double volume(void){ return h+w+d; }
friend istream& operator>>(istream& in, cube& a){
	cout<<"cube"<<endl;
	cout<<"height: ";
	in>>a.h;
	cout<<"width: ";
	in>>a.w;
	cout<<"depth: ";
	in>>a.d;
	return in; }
};
class square:public shape{
	public:
		int h;
		double area(void){ return h*h; }
		double volume(void){ return h*h*h; }
		friend istream& operator>>(istream& in, square& a){
			cout<<"square"<<endl;
			cout<<"height: ";
			in>>a.h;
			return in;
		}
};
class circle:public shape{
public:
int r;
double area(void){ return 3.14*r*r; }
friend istream& operator>>(istream& in, circle& a){
cout<<"circle: "<<endl;
cout<<"radius: "<<endl;
in>>a.r;
return in;
} };
class sphere:public shape{
public:
    int r;
    double area(void){return 4*3.14*r*r;}
    double volume(void){return (4*3.14*r*r*r)/3;}
    friend istream& operator>>(istream& in,sphere& a){
    cout<<"sphere: "<<endl;
    cout<<"radius: "<<endl;
    in>>a.r;
    return in;
    }
};
class cylinder:public shape{
public:
    int r,h;
    double area(void){return 2*3.14*r*r+2*3.14*r*h;}
    double volume(void){return 3.14*r*r*h;}
    friend istream& operator>>(istream& in,cylinder& a){
    cout<<"cylinder: "<<endl;
    cout<<"radius : "<<endl;
    in>>a.r;
    cout<<"height: "<<endl;
    in>>a.h;
    return in;
    }
};
main(){
	int i,n,choice,count=0;
	double area,volume;
    shape ob;
  	shape * allShape[50];
	triangle *p;
	cube *c;
	square *s;
	circle *cr;
	sphere *sp;
    cylinder *cy;
	cout << "How many shape?";
	cin >>n;
	for(i=0;i<n;i++)
	{
		cout << endl;
		cout << "Shape "<< (i+1) << ":"<< endl;
		cout <<"Shape type (1. Triangle 2. Cube 3. Square 4.circle 5.sphere 6.cylinder) :";
		cin >> choice;
		switch(choice)
		{
			case 1:
			    update("triangle",i);
				p = new triangle;
				cin >> *p;
				allShape[i] = p;
			break;
			case 2:
			    update("cube",i);
				c = new cube;
				cin >> *c;
				allShape[i] = c;
			break;
			case 3:
			    update("square",i);
				s = new square;
				cin >> *s;
				allShape[i] = s;
				break;
            case 4:
                update("circle",i);
                 cr=new circle;
                 cin>>*cr;
                 allShape[i]=cr;
                 break;
            case 5:
                update("sphere",i);
                 sp=new sphere;
                 cin>>*sp;
                 allShape[i]=sp;
                 break;
            case 6:
                update("cylinder",i);
                 cy=new cylinder;
                 cin>>*cy;
                 allShape[i]=cy;
                 break;

                 default:
				cout <<"Invalid choice "<< endl;
				i--;
			break;
		}}
cout<<"Do u want to add more shape?if yes press 1"<<endl;
int more,m=0;
cin>>more;
if(more==1){
cout<<"how many shape u want to add more"<<endl;
cin>>m;
for(int j=0;j<m;j++,i++){
    cout << endl;
		cout << "Shape "<< (i+1) << ":"<< endl;
		cout <<"Shape type (1. Triangle 2. Cube 3. Square 4.circle 5.sphere 6.cylinder) :";
		cin >> choice;
		switch(choice)
		{
			case 1:
			    update("triangle",i);
				p = new triangle;
				cin >> *p;
				allShape[i] = p;
			break;
			case 2:
			    update("cube",i);
				c = new cube;
				cin >> *c;
				allShape[i] = c;
			break;
			case 3:
			    update("square",i);
				s = new square;
				cin >> *s;
				allShape[i] = s;
				break;
            case 4:
                update("circle",i);
                 cr=new circle;
                 cin>>*cr;
                 allShape[i]=cr;
                 break;
            case 5:
                update("sphere",i);
                 sp=new sphere;
                 cin>>*sp;
                 allShape[i]=sp;
                 break;
            case 6:
                update("cylinder",i);
                 cy=new cylinder;
                 cin>>*cy;
                 allShape[i]=cy;
                 break;

                 default:
				cout <<"Invalid choice "<< endl;
				i--;
			break;
		}}}
    cout << endl << endl;
	cout << "Results" << endl;
	cout << "========" << endl;
    area = 0;
	for(i=0;i<n+m;i++)
		area += allShape[i]->area();
    cout <<"Area of all the shape :" << area << endl;
    volume= 0;
	for(i=0;i<n+m;i++)
		volume += allShape[i]->volume();
    cout <<"Volume of all the 3D shape :" << volume << endl;
    cout << endl;
	 for(i=0;i<n+m;i++){
    if(allShape[i]->volume()){
            count++;
        }}
        cout<<"\n***the number of 3D shapes***\n  "<<count<<endl;
    cout<<"\n***** the sequence of input of shape type****\n"<<endl;
    update("a",50,n+m);
	return 0;
}

