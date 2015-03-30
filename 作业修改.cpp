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
        cout << "需要尝试一次游戏吗（Y/N）?";  cin >> answer;
        if (answer=='N') {
			cout << "你一共玩了" << n << "局，游戏结束";
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
                cout << "请输入你猜测的数字：";
			    
			    while(!(cin>>inp1>>inp2>>inp3)) 
			    {   cin.clear();
			        cin.sync();
			        cout << "您的输入应为数字，请重新输入：" << endl; 
				};
           
                num_A = 0;  num_B = 0;  
        
                if (inp1==a[0])  ++num_A;                                  //judge whether the answer is correct. 
                else if (inp1==a[1] || inp1==a[2])  ++num_B;
            
                if (inp2==a[1])  ++num_A;
                else if (inp2==a[0] || inp2==a[2])  ++num_B;  
            
                if (inp3==a[2])  ++num_A;
                else if (inp3==a[0] || inp3==a[1])  ++num_B;
        
                if (num_A==3) {
		            cout << "恭喜，你猜对了" << "\n" << endl;                          
			     	break;                                                 //print the result.
                }
                else cout << num_A << "A" << num_B << "B" << endl << "你一共有7次机会" << endl;
        
		        ++i; 
            }
    
            if (i==8)  cout << "很遗憾，你没有在规定的次数内答对  答案是：" << a[0] << a[1] << a[2] << "\n" << endl;
            ++n;
        }
    }
}
 
