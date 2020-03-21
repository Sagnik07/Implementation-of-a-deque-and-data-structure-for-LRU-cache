#include<iostream>
using namespace std;

template <typename T>
class deque	{
	private:
	T* dq;
	int front1,rear1;
	int size1;
	public:
	deque();
	deque(int n,T x);
	void display(); 
	void push_back(T x);
	void pop_back();
	void push_front(T x);
	void pop_front();
	T front();
	T back();
	bool empty();
	int size();
	void resize(int x);
	void clear();
	~deque();
	T operator [](int x);
};
template <typename T>
deque<T>::deque()	{
	dq=new T[0];
	front1=-1;
	rear1=-1;
	size1=1;
}

template <typename T>
deque<T>::deque(int n,T x)	{
	dq=new T[n];
	for(int i=0;i<n;i++)	{
		*(dq+i)=x;
	}
	front1=0;
	rear1=n-1;
	size1=n;
}

template <typename T>
void deque<T>::display()	{
	int i;
	if((front1==rear1) && (rear1==-1))
		cout<<"Deque is empty!\n";
	else	{
		if(front1<=rear1)	{
			for(i=front1;i<=rear1;i++)
				cout<<*(dq+i)<<" ";
		}
		else	{
			int j=0;
			for(i=front1;i<size1;i++)
				cout<<*(dq+i)<<" ";
			for(i=0;i<=rear1;i++)
				cout<<*(dq+i)<<" ";
		}
		cout<<"\n";
	}
}

template <typename T>
void deque<T>::push_back(T x)	{
	int i,j=0;
	/*cout<<"rear1: "<<rear1<<"\n";
	cout<<"front1: "<<front1<<"\n";
	cout<<"size1: "<<size1<<"\n";*/
	if(rear1==front1 && rear1==-1)	{
		*dq=x;
		front1=rear1=0;
		size1=1;
	}
	else	{
		if(((rear1+1)%size1)==front1)	{
			T *dq1=new T[2*size1];
			if(front1<=rear1)	{
				for(i=front1;i<=rear1;i++)	{
					*(dq1+j)=*(dq+i);
					j++;
				}
				*(dq1+i)=x;
				delete[] dq;
				dq=dq1;		
				rear1++;
			}
			else 	{
				for(i=front1;i<size1;i++)	{
					*(dq1+j)=*(dq+i);
					j++;
				}
				for(i=0;i<=rear1;i++)	{
					*(dq1+j)=*(dq+i);
					j++;
				}

				*(dq1+j)=x;
				delete[] dq;
				dq=dq1;
				rear1=j;
			}
			size1=size1*2;
			front1=0;
				
		}
		else	{
			rear1++;
			*(dq+rear1)=x;
			
		}
	}
	/*cout<<"rear1: "<<rear1<<"\n";
	cout<<"front1: "<<front1<<"\n";
	cout<<"size1: "<<size1<<"\n";*/
}

template <typename T>
void deque<T>::pop_back()	{
	if(front1==rear1)	{
 		if(rear1==-1)
			cout<<"Deque is empty. Cannot delete!\n";
		else 	{
			front1=rear1=-1;
			size1=1;
		}
	}
	else if(rear1==0 && front1>rear1)	{
		rear1=size1-1;
		size1--;
	}
	//else if(rear1>front1)	{
	else	{	
		rear1--;
		size1--;
	}
}

template <typename T>
void deque<T>::pop_front()	{
	if(front1==rear1)	{
 		if(rear1==-1)
			cout<<"Deque is empty. Cannot delete!\n";
		else {
			front1=rear1=-1;
			size1=1;
		}
	}
	else if(front1==size1-1)	{
		front1=0;
		size1--;
	}
	else	{
		front1++;
		size1--;
	}
}

template <typename T>
void deque<T>::push_front(T x)	{
	int i,j=0;
	/*cout<<"rear1: "<<rear1<<"\n";
	cout<<"front1: "<<front1<<"\n";
	cout<<"size1: "<<size1<<"\n";*/
	if(rear1==front1 && rear1==-1)	{
		*dq=x;
		front1=rear1=0;
		size1=1;
	}
	else	{
		if(((rear1+1)%size1)==front1)	{
			T *dq1=new T[2*size1];
			*(dq1+j)=x;
			j++;
			if(front1<=rear1)	{
				for(i=front1;i<=rear1;i++)	{
					*(dq1+j)=*(dq+i);
					j++;
				}
				delete[] dq;
				dq=dq1;		
				rear1++;
			}
			else 	{
				for(i=front1;i<size1;i++)	{
					*(dq1+j)=*(dq+i);
					j++;
				}
				for(i=0;i<=rear1;i++)	{
					*(dq1+j)=*(dq+i);
					j++;
				}
				delete[] dq;
				dq=dq1;
				rear1=j;
			}
			size1=size1*2;
			front1=0;
				
		}
		else	{
			if(front1==0)	{
				front1=size1-1;
				//*(dq+front1)=x;
			}
			else
				front1--;

			*(dq+front1)=x;
			/*cout<<"rear1: "<<rear1<<"\n";
			cout<<"front1: "<<front1<<"\n";
			cout<<"size1: "<<size1<<"\n";*/
		}
	}
		
}

template <typename T>
T deque<T>::front()	{
	if(front1==rear1 && rear1==-1)	{
		cout<<"Deque is empty! ";
		static T defaultval;
		return defaultval;
	}
	return *(dq+front1);
}

template <typename T>
T deque<T>::back()	{
	if(front1==rear1 && rear1==-1)	{
		cout<<"Deque is empty! ";
		static T defaultval;
		return defaultval;
	}
	return *(dq+rear1);
}

template <typename T>
bool deque<T>::empty()	{
	if((front1==rear1) && (rear1==-1))
		return true;
	else
		return false;
}


template <typename T>
int deque<T>::size()	{
	if((front1==rear1) && (rear1==-1))
		return 0;
	else if(front1<=rear1)
		return (rear1-front1+1);
	else	
		return ((size1-front1)+rear1+1);
}

template <typename T>
void deque<T>::resize(int x)	{
	T *dq1=new T[x];
	int i,j=0,length,k;
	/*if(front1<=rear1)
		length=(rear1-front1+1);
	else	
		length=((size1-front1+1)+rear1+1);*/
	
	if(front1<=rear1)	{
		length=(rear1-front1+1);
		j=0;
		if(x>length)	{
			for(i=front1;i<=rear1;i++)	{
				*(dq1+j)=*(dq+i);
				j++;
			}
			for(i=j;i<x;i++)	{
				static T defaultval;
				*(dq1+i)=defaultval;
			}
			delete[] dq;
			dq=dq1;
			rear1=i-1;
			size1=x;
			front1=0;
		}
		else if(x<length)	{
			j=0;k=front1;
			while(j<x)	{
				*(dq1+j)=*(dq+k);
				j++;
				k++;
			}
			delete[] dq;
			dq=dq1;
			rear1=k-1;
			size1=x;
			front1=0;
			

		}
	}
	else	{
		length=((size1-front1+1)+rear1+1);
		if(x>length)	{
			j=0;
			for(i=front1;i<size1;i++)	{
				*(dq1+j)=*(dq+i);
				j++;
			}
			for(i=0;i<=rear1;i++)	{
				*(dq1+j)=*(dq+i);
				j++;
			}
			for(i=j;i<x;i++)	{
				static T defaultval;
				*(dq1+i)=defaultval;
			}
			delete[] dq;
			dq=dq1;
			rear1=i-1;
			size1=x;
			front1=0;
		}
		else if(x<length)	{
			j=0;k=front1;
			while(j<x)	{
				*(dq1+j)=*(dq+k);
				j++;
				k++;
			}
			delete[] dq;
			dq=dq1;
			rear1=k-1;
			size1=x;
			front1=0;

		}

	}
		
}
template <typename T>
void deque<T>::clear()	{
	T *dq1=new T[size1];
	delete[] dq;
	dq=dq1;
	size1=1;
	rear1=-1;
	front1=-1;
}

template <typename T>
T deque<T>::operator [](int x)	{
	int length;
	if(front1<=rear1)	{
		length=(rear1-front1+1);
		if(x>=length)	{
			cout<<"Element not present! ";
			static T defaultval;
			return defaultval;
		}
		else
			return *(dq+front1+x);
	}
	else	{
		length=((size1-front1+1)+rear1+1);
		if(x>=length)	{
			cout<<"Element not present! ";
			static T defaultval;
			return defaultval;
		}
		else
			return *(dq+((front1+x)%size1));
	}
}
			

template <typename T>
deque<T>::~deque()	{
	delete[] dq;
}
