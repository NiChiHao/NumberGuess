//Numguess.cpp
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int a[3], num_A, num_B, n=0, i, j, k, Temp;
    float inp1, inp2, inp3;
    char answer;
    bool flag;
    while(true) {                                                    //Ask whether to start the game.
        cout << "��Ҫ����һ����Ϸ��Y/N��?";  cin >> answer;
        if (answer=='N') {
			cout << "��һ������" << n << "�֣���Ϸ����";
			break;
    	}
    	else {		                                            
            srand(time(NULL));                                       //Create 3 random numbers.
            j=1;
            a[0] = rand()%10;
            while (j<3)                                           
            {	flag = true;
	            Temp = rand()%10;
	            for (k=0;k<j;++k) 
	        	{   if(a[k]==Temp) {flag=false; break;}
        	    }
	            if(flag==true) {a[j]=Temp; ++j;}            
            }
            
	        i=1;	
	        while (i<8) {
                cout << "��������²�����֣�";
			    
			    while(!(cin>>inp1>>inp2>>inp3)) 
			    {   cin.clear();
			        cin.sync();
			        cout << "��������ӦΪ���֣����������룺" << endl; 
				};
           
                num_A = 0;  num_B = 0;  
        
                if (inp1==a[0])  ++num_A;                                  //judge whether the answer is correct. 
                else if (inp1==a[1] || inp1==a[2])  ++num_B;
            
                if (inp2==a[1])  ++num_A;
                else if (inp2==a[0] || inp2==a[2])  ++num_B;  
            
                if (inp3==a[2])  ++num_A;
                else if (inp3==a[0] || inp3==a[1])  ++num_B;
        
                if (num_A==3) {
		            cout << "��ϲ����¶���" << "\n" << endl;                          
			     	break;                                                 //print the result.
                }
                else cout << num_A << "A" << num_B << "B" << endl << "��һ����7�λ���" << endl;
        
		        ++i; 
            }
    
            if (i==8)  cout << "���ź�����û���ڹ涨�Ĵ����ڴ��  ���ǣ�" << a[0] << a[1] << a[2] << "\n" << endl;
            ++n;
        }
    }
}
 
