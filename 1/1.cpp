#include<bits/stdc++.h>
using namespace std;
int main()
{
	system("ifconfig wlp2s0 1> ifconfig");
	ifstream f1("ifconfig");
	char x;
	// string y="";
	string y;
	while(f1.get(x))
	{
		f1>>y;
		// // if(x==' ' || x=='	' || x=='\n' || x==':')

		{
			
			if(y=="HWaddr")
			{
				cout<<"Mac Address:";
				// y="";
				f1>>y;
				cout<<y;
				// y="";
				cout<<endl;
			}
			else if(y=="inet")
			{
				cout<<"IP Address:";
				// y="";
				f1>>y;
				cout<<y;
				// y="";
				cout<<endl;
			}
			else if(y=="Bcast:")
			{
				cout<<"Broadcast:";
				// y="";
				f1>>y;
				cout<<y;
				// y="";
				cout<<endl;
			}
			else if(y=="Mask:")
			{
				cout<<"Netmask:";
				// y="";
				f1>>y;
				cout<<y;
				// y="";
				cout<<endl;
			}
			
		}
		// else
		// {
		// 	y+=x;
		// }
	}
	system("nmcli device show wlp2s0 1>nmcli"); 
    fstream file("nmcli");
    string word; 
    while (file >> word) 
    { 
      if(word=="IP4.ADDRESS[1]:")
      {
         file >> word;
         cout<<"IP address is : "<<word<<endl;
      }
      else if(word=="IP4.GATEWAY:")
      {
         file >> word;
         cout<<"IP gateway is : "<<word<<endl;
      }
      else if(word=="IP4.DNS[1]:")
      {
         file >> word;
         cout<<"IP4 DNS is : "<<word<<endl;
      }
      else if(word=="IP4.DNS[2]:")
      {
         file >> word;
         cout<<"IP4 DNS is : "<<word<<endl;
      }
     } 
}