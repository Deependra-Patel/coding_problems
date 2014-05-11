#include <iostream>
#include <list>
#include <vector>
using namespace std;
struct Point
{ float x,y;
	bool operator<(Point p2)
	{
		if(x<p2.x)
		return true;
		else
		if(x==p2.x)
		{if(y<p2.y)
			return true;
		  else return false;
		}
		else
		return false;
	}
	list<Point>::iterator iter_in_list;
	bool old;
	bool mark;
	bool above;
};

struct Line
{ float a,b,c;
  bool intersect(Point p1,Point p2)
  {
	  float val1=(a*p1.x+b*p1.y-c);
	  float val2=(a*p2.x+b*p2.y-c);
	  if(val1*val2<0)
	  return true;
	  else return false;
	
	}

Point intersect_point(Point p1,Point p2)
    {
		Point p;
		double 
		diff_x=p2.x-p1.x,diff_y=p2.y-p1.y;
		if(b==0)
		{
			p.x=c/a;
			p.y=p1.y+((diff_y/diff_x)*(p.x-p1.x));
		}
		else
		if(a==0)
		{
			p.y=c/b;
			p.x=p1.x+(p.y-p1.y)/(diff_y/diff_x);
		}
		else
		{
			p.x=((c-b*p1.y)*diff_x+p1.x*b*diff_y)/(a*diff_x+b*diff_y);
			p.y=(c-a*p.x)/b;
		}
        return p;
    }
    bool up(Point p1,Point p2)
    {
		//if(pass1(p2))
		//return !(p2.above);
		if(b==0)
		{
		float diff_x=p2.x-p1.x;
		if(diff_x>=0)
		return false;
		return true;
		}
		else 
		if(a*p1.x+b*p1.y-c>0)
		return false;
		else return true;
	}
	bool calculate_above(Point p1, Point p2)
	{
		if(b==0)
		{
		float diff_x=p2.x-p1.x;
		if(diff_x>=0)
		return true;
		return false;
		}
		else 
		if(p1.y>(c-a*p1.x)/b)
		return true;
		else return false;
	}
	bool pass1(Point p)
	{
		return (a*p.x+b*p.y-c==0);
	}
};

struct polygon
{
	list<Point> points;
	void print_list()
	{
		cout<<points.size()<<endl;
		for(list<Point>::iterator iter=points.begin();iter!=points.end();iter++)
		{
			cout<<(*iter).x<<" "<<(*iter).y<<" ";
			if(!(*iter).old)
			cout<<(*((*iter).iter_in_list)).x<<" "<<(*((*iter).iter_in_list)).y<<"   "<<endl;
			cout<<endl;
			
		}
		cout<<endl;
	}
	bool all_marked()
	{
		for(list<Point>::iterator iter=points.begin();iter!=points.end();iter++)
		{
			if(((*iter).old)&&(!(*iter).mark))
			return false;
		}
		return true;
	}
};

int main()
{
	
	polygon poly;
	Line l;
	int no_of_points;
	list<Point>::iterator iter0,iter2,old;
	cin>>no_of_points;
	for(int i=0;i<no_of_points;i++)
	{
		Point p;
		cin>>p.x;
		cin>>p.y;
		p.old=true;
		p.mark=false;
		poly.points.push_back(p);
	}
	iter0=poly.points.begin();
	old=iter0;
	iter0++;
	cin>>l.a>>l.b>>l.c;
	
	//updating list
	list<Point>intersection;
	
	for(list<Point>::iterator i=iter0;i!=poly.points.end();i++)
	{
		if(l.intersect(*i,*old))
		{
			Point temp1=l.intersect_point(*i,*old);
			temp1.old=false;
			temp1.mark=false;
			Point temp2=temp1;
			poly.points.insert(i,temp1);
			temp2.iter_in_list=i;
			temp2.iter_in_list--;
			intersection.push_back(temp2);
			list<Point>::iterator temp_iter=intersection.end();
			temp_iter--;
			i--;
			(*i).iter_in_list=temp_iter;
			i++;
		}
		else if(l.pass1(*i))
		{
			//(*i).above=l.calculate_above(*old,*i);
			Point temp1=*i;
			temp1.old=false;
			temp1.mark=false;
			Point temp2=temp1;
			poly.points.insert(i,temp1);
			temp2.iter_in_list=i;
			temp2.iter_in_list--;
			intersection.push_back(temp2);
			list<Point>::iterator temp_iter=intersection.end();
			temp_iter--;
			i--;
			(*i).iter_in_list=temp_iter;
			i++;
		}
		old=i;
	}
	iter0=poly.points.begin();
	old=poly.points.end();
	old--;
	if(l.intersect(*iter0,*old))
	{
			Point temp1=l.intersect_point(*iter0,*old);
			temp1.old=false;
			temp1.mark=false;
			Point temp2=temp1;
			poly.points.push_back(temp2);
			temp2.iter_in_list=poly.points.end();
			temp2.iter_in_list--;
			intersection.push_back(temp2);
			list<Point>::iterator temp_iter=intersection.end();
			temp_iter--;
			list<Point>::iterator temp_iter2=poly.points.end();
			temp_iter2--;
			(*temp_iter2).iter_in_list=temp_iter;
	}
	else if(l.pass1(*iter0))
	{
			//(*iter0).above=l.calculate_above(*old,*iter0);
			Point temp1=*iter0;
			temp1.old=false;
			temp1.mark=false;
			Point temp2=temp1;
			poly.points.push_back(temp2);
			temp2.iter_in_list=poly.points.end();
			temp2.iter_in_list--;
			intersection.push_back(temp2);
			list<Point>::iterator temp_iter=intersection.end();
			temp_iter--;
			list<Point>::iterator temp_iter2=poly.points.end();
			temp_iter2--;
			(*temp_iter2).iter_in_list=temp_iter;
		}
	poly.print_list();
	cout<<endl;
	
	intersection.sort();
	for(list<Point>::iterator i=intersection.begin();i!=intersection.end();i++)
	{
		Point other=*((*i).iter_in_list);
		cout<<(*i).x<<"  "<<(*i).y<<"Point:"<<other.x<<" "<<other.y<<endl;
	}
		cout<<"Printed all intersect";
	
	vector<polygon> ans_all;
	polygon temp;
	
	list<Point>::iterator first=poly.points.begin();
	list<Point>::iterator second;
	list<Point>::iterator initial_point=first;
	if(l.pass1(*first))
	first++;
	Point old_p=*first;
	(*first).mark=true;
	first++;
	cout<<"done";
	temp.points.push_back(old_p);
	bool got_new=true;
	
while(true)
	{
		if(first==poly.points.end())
		first=poly.points.begin();

		
		if(first==initial_point)
		{
			got_new=false;
			ans_all.push_back(temp);
			if(poly.all_marked())
			break;
			temp.points.clear();
			first++;
		}
		if(!got_new)
		{
			if(first==poly.points.end())
			first=poly.points.begin();
			
			if((*first).mark||(!(*first).old))
			{
			first++;
			continue;
			}
			initial_point=first;
			old_p=*first;
			(*first).mark=true;
			temp.points.push_back(old_p);
			first++;
			if(first==poly.points.end())
			first=poly.points.begin();
			got_new=true;
		}
		
		
		Point new_p=*first;
		cout<<new_p.x<<"  "<<new_p.y<<endl;
		cout<<old_p.x<<"  "<<old_p.y<<endl;
		cout<<"list";
		temp.print_list();
		if(!new_p.mark)
		{
			if(!new_p.old)
			{
				bool up;
				//if(l.pass1(new_p))
				//up=l.calculate_above(old_p,new_p);
				//else 
				up=l.up(old_p,new_p);
				second=new_p.iter_in_list;
				temp.points.push_back(new_p);
				if(up)
				{
				second++;
				temp.points.push_back(*second);
				first=(*second).iter_in_list;
				first++;
				}
				else
				{	second--;
					temp.points.push_back(*second);
					first=(*second).iter_in_list;
					first++;
				}
			}
			else
			{
				temp.points.push_back(new_p);
				(*first).mark=true;
				first++;
			}
		}
		else
		{
		first++;
		initial_point=first;
		}
		cout<<"list2:";
		temp.print_list();

		old_p=new_p;
		
	}
	cout<<"calculated";
	cout<<ans_all.size()<<endl;
	for(int i=0;i<ans_all.size();i++)
	{
		ans_all[i].print_list();
	}
}

