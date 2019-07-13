#include<iostream>
#include<fstream>
#include<sstream>
#include<bitset>

using namespace std;

//function to complement boolean array
void complement(bool *ans)
{
	for(int i=0;i<16;i++)
	{
		if(ans[i]==0)
			ans[i]=1;
		else
			ans[i]=0;
	}
}

// TO ADD 2, 16 BIT BOOLEAN ARRAYS
void add(bool *arr, bool *ans) {
    bool carry = 0;
    for(int i = 15; i >= 0; i--) {
        if(carry) {
            if(!arr[i] && !ans[i]) {
                ans[i] = 1;
                carry = 0;
            }
            else if((!arr[i] && ans[i]) || (arr[i] && !ans[i])) {
                ans[i] = 0;
                carry = 1;
            }
            else if(arr[i] && ans[i]) {
                ans[i] = 1;
                carry = 1;
            }
            // else {

            // }
        }
        else {
            if(arr[i] && ans[i]) {
                ans[i] = 0;
                carry = 1;
            }
            else {
                ans[i] += arr[i];
            }
        }
    }
    int i = 15;
    while(carry) {
        if(!ans[i]) {
            ans[i] = 1;
            carry = 0;
        }
        else {
            ans[i] = 0;
            carry = 1;
        }
        i--;
    }

}

int main()
{
	ifstream f("packet.pcap", ios::binary | ios::in);
	char c;
	int count1=0,aslicount=1;

	bitset<8> x1;
	bitset<8> x2;

	bool sum[16];
	bool ans[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	while(f.get(c))
	{


		if(count1>=40)
		{
			aslicount++;

			if(aslicount==26)
			{
				cout<<"Check Sum of the captured packet -> ";
				std::bitset<8> x(c);
				cout<<std::hex<<x.to_ulong()<<":";
			}

			if(aslicount==27)
			{
				std::bitset<8> x(c);
				cout<<std::hex<<x.to_ulong()<<endl;
			}

			if(aslicount%2==0 && aslicount>=16 && aslicount<=35 && aslicount!=26)
			{
				std::bitset<8> x(c);
				x1=x;
			}
			else if(aslicount%2!=0 && aslicount>=16 && aslicount<=35 && aslicount!=27)
			{
				std::bitset<8> x(c);
				x2=x;

                                //cout<<endl<<x1<<" x1 adn x2 "<<x2<<endl;

				sum[0]=x1[7];
				sum[1]=x1[6];
				sum[2]=x1[5];
				sum[3]=x1[4];
				sum[4]=x1[3];
				sum[5]=x1[2];
				sum[6]=x1[1];
				sum[7]=x1[0];

				sum[8]=x2[7];
				sum[9]=x2[6];
				sum[10]=x2[5];
				sum[11]=x2[4];
				sum[12]=x2[3];
				sum[13]=x2[2];
				sum[14]=x2[1];
				sum[15]=x2[0];

				//for(int i=0;i<16;i++) cout<<sum[i];
				add(sum,ans);



			}
		}
		count1++;
	}

	complement(ans);

	cout<<"Computed Checksum in binary digits :-"<<endl;

	for(int i=0;i<16;i++)
	{
		cout<<ans[i];
	}

	cout<<endl;
	cout<<"Computed Check Sum of the catured packet -> ";

	x1[0]=ans[7];
	x1[1]=ans[6];
	x1[2]=ans[5];
	x1[3]=ans[4];
	x1[4]=ans[3];
	x1[5]=ans[2];
	x1[6]=ans[1];
	x1[7]=ans[0];

	x2[0]=ans[15];
	x2[1]=ans[14];
	x2[2]=ans[13];
	x2[3]=ans[12];
	x2[4]=ans[11];
	x2[5]=ans[10];
	x2[6]=ans[9];
	x2[7]=ans[8];

	cout<<std::hex<<x1.to_ulong()<<":"<<std::hex<<x2.to_ulong()<<endl;

	return 0;
}