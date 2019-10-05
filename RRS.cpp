#include<iostream>
#include<conio.h>
using namespace std;
int np,n,flag[10],track=0,count=0;
int min(int arr[],int np){
	int minv=INT_MAX,mini=0;
	for(int i=0;i<np;i++){
		if(flag[i]==1)
		continue;
		if(minv>arr[i]){
			minv=arr[i];
			mini=i;
		}
	}
	return mini;
}
int sumA(int arr[]){
	int sum=0;
	for(int i=0;i<np;i++){
		sum+=arr[i];
	}
	return sum;
}
void sort(int arr[],int arr2[]){
	for(int i=0;i<np;i++){
		for(int j=i+1;j<np;j++){
			if(arr[i]>arr[j]){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
				int temp2=arr2[i];
				arr2[i]=arr2[j];
				arr2[j]=temp2;
			}
		}
	}
}
int search(int val,int arr[],int np){
	for(int i=0;i<np;i++){
		if(val==arr[i])
		return i;
	}
}
int max(int arr[],int np){
	int maxv=arr[0],maxi=0;
	for(int i=0;i<np;i++){
		if(!flag[i])
		if(maxv<arr[i]){
			maxv=arr[i];
			maxi=i;
		}
	}
	return maxi;
}
void copy(int arr[],int arr2[]){
	for(int i=0;i<np;i++){
		arr2[i]=arr[i];
	}
}
class RRS
{
	public:
		int AT[10],BT[10],BTC[10],P[100],RQ[100],CT[10],RT[10],WT[10],TAT[10];
		float AWT,ATAT,ART;
		RRS()
		{
			cout<<"Enter Number Of Processes:";
			cin>>np;
			AWT=0;
			ATAT=0;
			ART=0;
			cout<<"Enter Arrival Time of every process"<<endl;
			for(int i=0;i<np;i++){
				cin>>AT[i];
				flag[i]=0;
				RQ[i]=0;
			}
			cout<<"Enter Burst Time of every process"<<endl;
			for(int i=0;i<np;i++){
				cin>>BT[i];
				BTC[i]=BT[i];
			}
			if(AT[max(AT,np)]>=sumA(BT))
			n=AT[max(AT,np)]+BT[max(AT,np)];
			else
			n=(AT[min(AT,np)]+sumA(BT));
			for(int i=0;i<n;i++){
				P[i]=0;
			}
		}
		void reccur(int TQ)
		{
			sort(AT,BT);
			copy(BT,BTC);
			int t,p=0;
			for(t=0;t<n;t++)
			{
				track[t]=track;
				int e;
					if(AT[p]==t)
					{
						if(RQ[count]!=0){
							RQ[count-1]=p+1;
							count++;
						}
						else{
							RQ[count]=p+1;
							count++;
						}
						p++;
					}
				for(e=0;e<np;e++)
				{
					if(RQ[e]!=0)
					break;
				}
				int index=RQ[track]-1;
				if(e==np)
				P[t]=0;
				else
				P[t]=index+1;
				BTC[index]-=1;
				if(BTC[index]==0)
				{
					flag[index]=1;
					track++;
				}
				else if(((BT[index]-BTC[index])%TQ)==0)
				{
					cout<<"p="<<p<<" AT"<<AT[p]<<"t="<<t<<endl;
					if(AT[p]==t+1&&t<AT[max(AT,np)])
					{
						RQ[count+1]=index+1;
					}
					else
					{
						RQ[count]=index+1;
					}
					count++;
					track++;
				}
			}
		}
		void calP()
		{
			int track[10],tr[10];
			for(int i=0;i<np;i++)
			{
				track[i]=0;
				tr[i]=0;
			}
			for(int i=n-1;i>=0;i--){
				for(int j=0;j<np;j++){
					if(track[j]==0)
					if(j==(P[i]-1))
					{
						CT[j]=i+1;
						track[j]=1;
					}
				}
			}
			for(int i=0;i<np;i++){
				TAT[i]=CT[i]-AT[i];
				WT[i]=TAT[i]-BT[i];
				ATAT+=TAT[i];
				AWT+=WT[i];
				ART+=RT[i];
			}
		}
};
int main()
{
	cout<<"Enter Time Quantum"<<endl;
	int TQ;
	cin>>TQ;
	RRS o;
	o.reccur(TQ);
	o.calP();
	cout<<n<<endl;
	for(int i=0;i<count;i++){
		cout<<o.RQ[i]<<"\t";
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<o.P[i]<<"\t";
	}
	cout<<endl;
	cout<<"Process\t"<<"\t"<<"[AT]"<<"\t"<<"[BT]"<<"\t"<<"[CT]"<<"\t"<<"[WT]"<<"\t"<<"[TAT]"<<endl;
	for(int i=0;i<np;i++){
		cout<<"Process"<<i<<"\t"<<o.AT[i]<<"\t"<<o.BT[i]<<"\t"<<o.CT[i]<<"\t"<<o.WT[i]<<"\t"<<o.TAT[i]<<endl;
	}
	cout<<endl;
	cout<<"AWT="<<o.AWT/np<<endl;
	cout<<"ATAT="<<o.ATAT/np;
}
