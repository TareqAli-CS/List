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
int main()
{
	list<int>l;
	l.insert(0,5);
	int item;
	l.retrive(0,item);
	cout<<item<<endl;
	return 1;
}