#include<iostream>
#include<conio.h>
using namespace std;
class FCFS
{
      private:
              int AT[100],BT[100],CT[100],E[100],WT[100],ST[100],P[100],TAT[100];
              float AWT,ATAT;
      public:
             FCFS(int n)
             {
                      CT[0]=0;ST[0]=0;AWT=0;ATAT=0;
                      cout<<"Enter Arrival time and Burst time"<<endl;
                 for(int i=0;i<n;i++)
                 {
                         cout<<"Enter Arrival Time process "<<i<<":";
                         cin>>AT[i];
                         cout<<"Enter Burst Time of process "<<i<<":";
                         cin>>BT[i];
                 }
                  cout<<"Calculating Completion time..."<<endl;
                 for(int i=0;i<n;i++)
                 {
                         if(i==0)
                         {	
                         	CT[i]=BT[i];
                         	E[i]=BT[i];
						 }
                         else
                         {
                         	if(AT[i]>CT[i-1])
                         	{	
                                    CT[i]=CT[i-1]+BT[i]+(AT[i]-CT[i-1]);
                                    E[i]=E[i-1]+BT[i];
                         	}
                            else
                         	{
                             CT[i]=CT[i-1]+BT[i];
                             E[i]=E[i-1]+BT[i];
                         	}
						 }
                 }
                         cout<<"Calculating Scheduling time..."<<endl;
                for(int i=0;i<n;i++)
                {
                		if(i==0)
                		ST[i]=AT[i];
                		else
                		{
                			if(CT[i]>E[i])
                        	 {
                            ST[i]=AT[i];
                         	}
                         	else
                         	{
                             ST[i]=CT[i-1];
                         	}
						}
				}
                         cout<<"Calculating Wait Time..."<<endl;
                         for(int i=0;i<n;i++)
                         WT[i]=ST[i]-AT[i];
                         cout<<"Calculating Turn around time.."<<endl;
                         for(int i=0;i<n;i++)
                         TAT[i]=WT[i]+BT[i];
                 for(int i=0;i<n;i++)
                 {
                         P[i]=i;
                         AWT=AWT+WT[i];
                         ATAT=ATAT+TAT[i];
                 }
             }
             void print(int n)
             {
             	  cout<<"Process-"<<"P[]"<<"\t"<<"AT[]"<<"\t"<<"BT[]"<<"\t"<<"CT[]"<<"\t"<<"WT[]"<<"\t"<<"TAT[]"<<endl;	
                  for(int i=0;i<n;i++)
                  {
                          cout<<"Process-"<<P[i]<<"\t"<<AT[i]<<"\t"<<BT[i]<<"\t"<<CT[i]<<"\t"<<WT[i]<<"\t"<<TAT[i]<<endl;
                  }
                  cout<<"Average Wait Time:"<<AWT/n<<endl;
                  cout<<"Average Turn around Time:"<<ATAT/n<<endl;
             }
};
int main()
{
    int n;
    cout<<"Enter Number of Processes"<<endl;
    cin>>n;
    FCFS obj(n);
    obj.print(n);
    getch();
    return 0;
}

                         
