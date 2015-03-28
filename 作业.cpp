//Numguess.cpp
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    int a[3], inp1, inp2, inp3, num_A, num_B, n=0, i, j, k, Temp;
    char answer;
    bool flag;
    while(true) {                                                    //Ask whether to start the game.
        cout << "Do you want to start the game(Y/N)?";  cin >> answer;
        if (answer=='N') {
			cout << "You have played " << n << " times, game is over.";
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
                cout << "Please input the numbers you guess:";
			    cin >> inp1 >> inp2 >> inp3;
           
                num_A = 0;  num_B = 0;  
        
                if (inp1==a[0])  ++num_A;                                  //judge whether the answer is correct. 
                else if (inp1==a[1] || inp1==a[2])  ++num_B;
            
                if (inp2==a[1])  ++num_A;
                else if (inp2==a[0] || inp2==a[2])  ++num_B;  
            
                if (inp3==a[2])  ++num_A;
                else if (inp3==a[0] || inp3==a[1])  ++num_B;
        
                if (num_A==3) {
		            cout << "Congratulations, you are right!" << "\n" << endl;                          
			     	break;                                                 //print the result.
                }
                else cout << num_A << "A" << num_B << "B" << endl << "You have 7 times in total." << endl;
        
		        ++i; 
            }
    
            if (i==8)  cout << "Sorry, you haven't got the right numbers  The answer is: " << a[0] << a[1] << a[2] << "\n" << endl;
            ++n;
        }
    }
}
 
