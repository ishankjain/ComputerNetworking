#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;

int main(){
	ifstream f("packet.pcap",ios::binary|ios::in) ;
	char c ;
	int ct=0;
	
	unsigned char c1 , c2 ;
	printf("Mac Address of destination : ");
	while(f.get(c)){
		++ct ;
		if(ct<=40){
			continue ;
		}
		
		printf("%02x",(unsigned char)c);
		printf(" ");
		
		if(ct > 45){
			break ;
		}
	}
	printf("\n");
	printf("Mac Address of source : ");
	while(f.get(c)){
		++ct ;
		printf("%02x",(unsigned char)c);
		printf(" ");
		
		if(ct > 51){
			break ;
		}

	}
	while(f.get(c)){
		++ct ;
		if(ct==65){
			c1=c ;
		}
		if(ct==66){
			c2=c ;
			break;
		}
		
	}
	printf("\n");
	printf("IP Address of source : ");
	while(f.get(c))
	{
		printf("%02x ", (unsigned char)c);
		ct++;
		if(ct >= 70)
			break;
	}
	printf("\n");
	printf("IP Address of destination : ");
	while(f.get(c))
	{
		printf("%02x ", (unsigned char)c);
		ct++;
		if(ct >= 74)
			break;
	}
	printf("\n");
	printf("CheckSum : %02x%02x\n",c1,c2) ;

	
	/*while(f.get(c)){
		++ct ;
		printf("%02x ",c) ;
		if(ct>300){ break ;}
	}*/

	f.close() ;
	
}