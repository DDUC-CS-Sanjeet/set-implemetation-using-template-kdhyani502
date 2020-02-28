#include<iostream>
#include<cmath>
using namespace std;
template <typename T>
class Myset
{
    private:
    	int row;
        T *Array;
    public:
    Myset()
    {
    	row=0;
     	Array=new T[0];
	}
    Myset(int num)
    {
     	row=num;
        Array=new T[num];
    }
    Myset(const Myset &m)
    {
    	row=m.row;
    	Array=m.Array;
	}
	void Cardinality()
	{
		cout<<row;
	}
	void remove_duplicate(T *array,int &row)
	{
		for(int i=0; i<row; i++)
	    {
	        for(int j=i+1; j<row; j++)
	        {
	            if(array[i] == array[j])
	            {
	                for(int k=j; k<row; k++)
	                 array[k] = array[k + 1];
	                row--;
	                j--;
	            }
	        }
	    }
	}
    Myset operator+(const Myset  s)
    {
    	int i=0,j=0;
    	Myset temp(s.row+row);
       	for(;i<row;i++)
    	temp.Array[i]=Array[i];
    	for(;j<s.row;j++,i++)                                                                                                                                                                                                                                                                                                                  
    	temp.Array[i]=s.Array[j];
   		remove_duplicate(temp.Array,temp.row);
    	return temp;
	}
	Myset operator*(const Myset  s)
    {
    	int i=0,j=0,k=0;
    	Myset temp;
    	if(s.row>=row)
    	temp=row;
    	else
    	temp=s.row;
    	for(int i=0; i<s.row; i++)
	    {
	        for(int j=0; j<row; j++)
	        {
	            if(s.Array[i]==Array[j])
	            {
	                 temp.Array[k++] = Array[j];
	            }
	        }
	    }
	    temp.row=k;
	   	remove_duplicate(temp.Array,temp.row);
    	return temp;
    }
    Myset operator^(const Myset  s)
    {
    	int i=0,j=0,k=0;
    	Myset temp;
    	for(int i=0; i<row; i++)
	    {
	        for(int j=0; j<s.row; j++)
	        {
	            if(Array[i] != s.Array[j])
	            {
	            	if(j==s.row-1)
	                 temp.Array[k++] = Array[i];
	            }
	            else
	            break;
	        } 
	    }
		for(int i=0; i<s.row; i++)
	    {
	        for(int j=0; j<row; j++)
	        {
	            if(s.Array[i] != Array[j])
	            {
	            	if(j==row-1)
	                temp.Array[k++] = s.Array[i];
	            }
	            else
	            break;
	        }                     
	    }                    
	    temp.row=k;
	    remove_duplicate(temp.Array,temp.row);
	    return temp;
	}
	Myset operator-(const Myset  s)
	{
		int l=0,k=0;
    	Myset temp;
    	for(int i=0; i<row; i++)
	    {
	        for(int j=0; j<s.row; j++)
	        {
	            if(Array[i] != s.Array[j])
	            {
	            	if(j==s.row-1)
	                 temp.Array[k++] = Array[i];
	            }
	            else
	            break;
	        }                     
	    }	
		temp.row=k;
	  	remove_duplicate(temp.Array,temp.row);
		return temp;	
	}
	int operator==(const Myset s)
    {
        if(row != s.row)
            return 0;
        else
        {
            int flag = 0;
            for(int i = 0; i < row; i++)
            for(int j = 0; j <s.row;j++)
                if(Array[i] ==s.Array[j])
                    flag++;
                if(flag == row)
                    return 1;
                else
                    return 0;
        }
    } 
    void input ()
    {
     	for(int i=0;i<row;i++)
     	cin>>Array[i];
 		remove_duplicate(Array,row);
	}
	void display()
	{
	 	int i=0;
	 	if(row==0)
	 	cout<<"{0}";
	 	else
	 	{
			cout<<"{";
		 	for(;i<row;i++)
		 	if(i==row-1)
	     	cout<<Array[i]<<"}";
	     	else
	     	cout<<Array[i]<<",";
	    }
	}
};
template <typename T>
void printSets(Myset <T> set1, Myset <T> set2, Myset <T> set3, Myset <T> set4, Myset <T> set5, Myset <T> set6,Myset <T> set7, int result)
{
    cout<<"SET A: ";
    set1.display();
    cout<<"\nSET B: ";
    set2.display();
    cout<<"\nUNION: ";
    set3.display();
    cout<<"\nINTERSECTION: ";
    set4.display();
    cout<<"\nDIFFERENCE: ";
    set5.display();
    cout<<"\nSYMMETRIC DIFFERENCE: ";
    set6.display();
    cout<<"\nCardinality of Set A: ";
    set1.Cardinality();
    cout<<"\nCardinality of Set B: ";
    set2.Cardinality();
    if(result==1)
    cout<<"\nSETS A AND B ARE EQUAL";
    else
    cout<<"\nSETS A AND B ARE NOT EQUAL";
    cout<<"\nAfter copying set A to set C "<<endl;
    cout<<"SET C:";
    set7.display();
}
int main()
{
	char ch;
	int c;
	do
	{
	int num1,num2;
	cout<<"Enter number of elements of Set A \n";
	cin>>num1;
	cout<<"Enter number of elements of Set B \n";
	cin>>num2;	
	cout<<"\n            MENU              ";
	cout<<"\n 1) INTEGER ";
	cout<<"\n 2) CHARACTER ";
	cout<<"\n 3) FLOATING-POINT ";
	cout<<"\n Enter your choice... ";
	cin>>c;
	switch(c)
	{
		case 1:{
					Myset <int> set1(num1);
                    cout<<"Enter elements of Set A \n";
                    set1.input();
                    Myset <int> set2(num2);
                    cout<<"Enter elements of Set B \n";
                    set2.input();
                    Myset <int> set3 = set1 + set2;                                   
                    Myset <int> set4 = set1 * set2;       
                    Myset <int> set5 = set1 - set2;;       
                    Myset <int> set6 = set1^set2;
                    int result = set1 == set2;
                    Myset <int> set7=set1;
					printSets(set1, set2, set3, set4, set5, set6,set7, result);	
					break;
				}
		case 2: {
					Myset <char> set1(num1);
                    cout<<"Enter elements of Set A \n";
                    set1.input();
                    Myset <char> set2(num2);
                    cout<<"Enter elements of Set B \n";
                    set2.input();
                    Myset <char> set3 = set1 + set2;                                   
                    Myset <char> set4 = set1 * set2;       
                    Myset <char> set5 = set1 - set2;;       
                    Myset <char> set6 = set1^set2;
                    int result = set1 == set2;
                    Myset <char> set7=set1;
					printSets(set1, set2, set3, set4, set5, set6, set7, result);	
					break;
			    }
	    case 3: {
					Myset <float> set1(num1);
                    cout<<"Enter elements of Set A \n";
                    set1.input();
                    Myset <float> set2(num2);
                    cout<<"Enter elements of Set B \n";
                    set2.input();
                    Myset <float> set3 = set1 + set2;                                   
                    Myset <float> set4 = set1 * set2;       
                    Myset <float> set5 = set1 - set2;;       
                    Myset <float> set6 = set1^set2;
                    int result = set1 == set2;
                    Myset <float> set7=set1;
					printSets(set1, set2, set3, set4, set5, set6, set7, result);	
				    break;
				}
	}
	cout<<"\nWant to enter more?? (Y/y)";
	cin>>ch;
	}while(ch=='y'||ch=='Y');
	return 0;
}
