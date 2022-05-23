#include <iostream>
using namespace std;
const int maxsize=100;
template <class T>
class list
{
	T entry[maxsize];
	int count;
	public:
	list()
	{
		count=0;
	}
	bool empty()
	{
		return count==0;
	}
	bool insert(int pos,T item)
	{
		if(pos<0||pos>count)return 0;//Invalid Position
		if(count>=maxsize)return 0;//List is full
		for(int i=count-1;i>=pos;i++)
			entry[i+1]=entry[i];
		entry[pos]=item;
		count++;
		return 1;
	}
	bool remove(int pos)
	{
		if(pos<0|| pos>=count)return 0;
		for(int i=pos;i<count-1;i++)
			entry[i]=entry[i+1];
		count--;
		return 1;
	}
	bool retrive(int pos,T &item)
	{
		if(pos<0||pos>=count)return 0;
		item=entry[pos];
		return 1;
	}
	bool replace(int pos,T item)
	{
		if(pos<0|| pos>=count)return 0;
			entry[pos]=item;
			return 1;
	}
	int size()
	{
		return count;
	}
};
void fill(list<int>&l,int n);
void print(list<int>l);
void destroy(list<int>&l);
bool search(list<int>l,int number);
void replace(list<int>&l,int x); // replace x with its double
int main()
{
	list<int>l;
	fill(l,7);
	print(l);
	cout<<search(l,6)<<endl;
	replace(l,5);
	print(l);
	
	
	
	
	return 1;
}
void fill(list<int>&l,int n)
{
	
	for(int i=0;i<n;i++)
	l.insert(l.size(),i);
}
void print(list<int>l)
{
	if(l.empty())
	return ;
	int item;
	for(int i=0;i<l.size();i++)
	{
		l.retrive(i,item);
		cout<<item<<" ";
	}
	cout<<endl;
}
void destroy(list<int>&l)
{
	while(!l.empty())
	l.remove(l.size()-1);
}
bool search(list<int>l,int number)
{
	int item;
	for(int i=0;i<l.size();i++)
	{
		l.retrive(i,item);
		if(item==number)
			return 1;	
		
	}
	return 0;
}
void replace(list<int>&l,int x) 
{
	int item;
	for(int i=0;i<l.size();i++)
	{
		l.retrive(i,item);
		if(item==x)
		l.replace(i,x*2);
	}
}
void odd(list<int>&l)
{
	int item;
	for(int i=0;i<l.size();i++)
	{
		l.retrieve(i,item);
		if(item%2==0)
		{
			l.remove(i);
			i--;
		}
	}
}
void order(list<int>&l)
{
	
	int item;
	for(int i=0;i<l.size();i++)
	{
		l.retrieve(i,item);
		if(item%2==0)
		{
			l.remove(i);
			l.insert(0,item);
		}
	}
}
