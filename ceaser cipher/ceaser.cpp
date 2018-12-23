#include<iostream>
using namespace std;
void encryption(char* message,int key);
void decryption(char* message,int key);

void encryption(char* message,int key){
	char ch;

	for(int i=0;message[i]!='\0'; ++i){
		ch=message[i];
		if(ch>='a' && ch <='z')
		{
			ch=ch+key;
			if(ch>'z')
				ch=ch-'z'+'a'-1;
			message[i]=ch;
		}
		else if(ch>='A' && ch <='Z')
		{
			ch=ch+key;
			if(ch>'Z')
				ch=ch-'Z'+'A'-1;
			message[i]=ch;
		}
	}
}

void decryption(char* message,int key){
	char ch;
        for(int i=0;message[i]!='\0'; ++i){
                ch=message[i];
                if(ch>='a' && ch <='z')
                {       
                        ch=ch-key;
                        if(ch<'a')
                                ch=ch+'z'-'a'+1;
                        message[i]=ch;
                }       
                else if(ch>='A' && ch <='Z')
                {
                        ch=ch+key;
                        if(ch<'A')
                                ch=ch+'Z'-'A'+1;
                        message[i]=ch;
                }
        }
}

int main(){

	char message[100];
	cout<<"Enter a message to encrypt"<<endl;
	cin>>message;
	int key;
	cout<<"Enter the key"<<endl;
	cin>>key;
	encryption(message,key);
	cout<<"The encrypted message is :"<<message<<endl;
	decryption(message,key);
        cout<<"The decrypted message is :"<<message<<endl;


}
