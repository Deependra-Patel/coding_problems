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
		if(b==0)
		{
		float diff_x=p2.x-p1.x;
		if(diff_x>=0)
		return false;
		return true;
		}
		else 
		if(p1.y>(c-a*p1.x)/b)
		return false;
		else return true;
	}
	bool pass1(Point p)
	{
		return (a*p.x+b*p.y-c==0);
	}
};

struct polygon
{
	list<Point> points;
/*
void arrange(){
		list<Point>::iterator itr,temp;
		itr=points.begin();
		temp=itr;
		itr++;
		list<Point>second;
		while(!(*temp<*itr)){
			second.push_back(*temp);
			points.erase(temp);
			temp=itr;
			itr++;
		}
		points.merge(second);
	} 
	* */
	void print_list()
	{   
		//this->arrange();
		cout<<points.size()<<endl;
		for(list<Point>::iterator iter=points.begin();iter!=points.end();iter++)
		{
		cout<<(*iter).x<<" "<<(*iter).y<<" ";
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
			if(l.pass1(*old))
			{
				intersection.pop_back();
				poly.points.erase(iter2);
				iter2--;
				(*iter2).mark=false;
			}
			(*i).mark=true;
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
			iter2=i;
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
			(*iter0).mark=true;
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
	intersection.sort();

	
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
	temp.points.push_back(old_p);
	bool got_new=true;
	int size=intersection.size();
	if(size==1 || size==0)
	poly.print_list;
	else{
while(true)
	{
		if(first==poly.points.end())
		first=poly.points.begin();
		if(initial_point==first)
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
		if(!new_p.mark)
		{
			if(!new_p.old)
			{
				bool up=l.up(old_p,new_p);
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

		old_p=new_p;
		
	}
	cout<<ans_all.size()<<endl;
	for(int i=0;i<ans_all.size();i++)
	{
		ans_all[i].print_list();
	}}
}

