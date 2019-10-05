#include <iostream>
using namespace std;

int least(int a[],int n) 
{
	int min = a[0];
	for (int k=0;k<n;k++) 
	{
		if (a[k] < min)
		min = a[k];
	}
	return min;
}


void SJF() {
	int n,track;
	float ATAT=0,AWT=0;
	cout << "Number of Processes :" ;
	cin >> n;
	int P[10],AT[10],BT[10],CT[10],TAT[10],WT[10],flag[10];
	cout<<"Enter Arrival time of: "<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<"Process-- "<<i<<":";
			cin>>AT[i];
			flag[i]=0;
		}
	cout<<"Enter Burst time of : "<<endl;
		for(int i=0;i<n;i++)
		{
				cout<<"Process-- "<<i<<":";
				cin>>BT[i];
		}
	
	track = least(AT,n);
	int minimum,ind;
	for (int i=0;i<n;i++) 
	{
		minimum = INT_MAX;
		for (int j=0;j<n;j++) 
		{
			if (flag[j]==0) 
			{
				
				if (AT[j] <= track) 
				{
					if (BT[j] < minimum) 
					{
						minimum = BT[j];
						ind = j;
					}
				}
			} 
			else 
			continue;
		}
		
		flag[ind] = 1;
		track += BT[ind];
		CT[ind] = track;
	
	}
	for (int i=0;i<n;i++) {
		TAT[i] = CT[i] - AT[i];
		WT[i] = TAT[i] - BT[i];
		AWT += WT[i];
		ATAT += TAT[i];
	}
	cout << "Process[] " << '\t' << "AT[]" << '\t' << "BT[]" << '\t' << "CT[]" << '\t' << "WT[]" << '\t' << "TAT[]" << '\t' << endl;
	for (int t=0;t<n;t++) {
		cout << "Process-"<<t<<":" << '\t' << AT[t] << '\t' << BT[t] << '\t' << CT[t] << '\t' << WT[t] << '\t' << TAT[t] << endl;
	}
	cout << endl;
	cout << "Average Waiting Time : " << AWT/n << endl;
	cout << "Average Turn-Around-Time : " << ATAT/n << endl;
	
}
int main()
{
	int num;
	cout<<"Enter reps"<<endl;
	cin>>num;
	while(num--)
	{
		SJF();
	}
	return 0;
}
