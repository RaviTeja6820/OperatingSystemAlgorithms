#include<iostream>
#include<conio.h>
using namespace std;
int  n;
int min(int arr[]){
	int small=arr[0];
	for(int i=0;i<n;i++)
		if(small>arr[i])
			small=arr[i];
	return small;
}
int copies(int val,int arr[]){
	int count=0;
	for(int i=0;i<n;i++)
	if(val==arr[i])
	count+=1;
	return count;
}
class SRTF{
	public:
		int AT[10],BT[10],CT[10],WT[10],TAT[10],rank[10],flag[10],P[100],total,BTC[10];
		float AWT,ATAT;
		SRTF(){
			cout<<"Enter Range:";
			cin>>n;
				AWT=0;
				ATAT=0;
				total=0;
			cout<<"Enter Arrival Time:"<<endl;
			for(int i=0;i<n;i++){
				cout<<"AT["<<i<<"]:";
				cin>>AT[i];
				flag[i]=0;
				P[i]=10000;
			}
			cout<<"Enter Burst Time:"<<endl;
			for(int i=0;i<n;i++){
				cout<<"BT["<<i<<"]:";
				cin>>BT[i];
				BTC[i]=BT[i];
				total+=BT[i];
			}
			total+=min(AT);
		}
		void findOrder(){
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					if(AT[i]>AT[j]){
						int temp=AT[i];
						AT[i]=AT[j];
						AT[j]=temp;
						int emp=BT[i];
						BT[i]=BT[j];
						BT[i]=temp;
					}
				}
			}
		}
		void executeProcess(){
			int count=0;
			P[min(AT)]=0;
			for(int j=0;j<total;j++){
				if(j>=min(AT)){
					for(int i=0;i<n;i++){
						cout<<"flag"<<flag[i]<<endl;
						if(!flag[i]){
							if(j==1){
								P[j]=i;
								BTC[i]-=1;
								cout<<"BTC"<<BTC[i]<<endl;
								if(BTC[i]==0){
									flag[i]=1;
								}
								break;
							}
							else
							{
								if(BTC[i]<BTC[P[j-1]]){
								P[j]=i;
								BTC[i]-=1;
								cout<<"BTC"<<BTC[i]<<endl;
								if(BTC[i]==0){
									flag[i]=1;
								}
								break;
								}
							}
						}
					}
				}
			}
		}
};
int main(){
	SRTF o;
	o.findOrder();
	o.executeProcess();
	for(int i=0;i<o.total;i++)
	cout<<"P["<<i<<"]:"<<o.P[i]<<endl;
//for(int i=0;i<n;i++){
//cout<<"A["<<i<<"]"<<o.AT[i]<<"\t";
//cout<<"B["<<i<<"]"<<o.BT[i]<<endl;
}
