NIS LAB 01

// NIS Lab 1
// Vivek Shah
// Additive & Multiplicative Cipher



#include<stdio.h>
void encrypt(char *plain, int key, char *cipher);
void decrypt(char *cipher, int key, char *plain);
void breakCipher(char *cipher);
void encryptM(char *plain, int key, char *cipher);
void decryptM(char *cipher, int key, char *plain);
void breakCipherM(char *cipher);

#define MENUSHOW 1
#define ENCPT 2
#define DECPT 3
#define BREAK 4
#define ENCPTM 5
#define DECPTM 6
#define BREAKM 7

#define EXIT 0

int main()
{
	int key;
	char plain[500];
	char cipher[200];
	
	int menu = 1;
	printf("CIPHER TEXT CONVERTER\n**********************\n");
	while(menu)
	{
		
		switch(menu)
		{
			case MENUSHOW:
				printf("1 > SHOW OPTIONS\n2 > ENCRYPTING THE TEXT\n3 > DECRYPT THE CIPHER\n4 > BREAK THE CIPHER\n5 > ENCRYPTING THE TEXT [MULTIPLICATIVE]\n6 > DECRYPTING THE TEXT [MULTIPLICATIVE]\n7 > BREAK THE CIPHER [MULTIPLICATIVE]\n0 > EXIT\n");
				break;
			case ENCPT:
				printf("Enter Plain Text: ");
				scanf("%s",plain);
				printf("Enter Cipher Key: ");
				scanf("%d",&key);
				encrypt(plain,key,cipher);
				printf("Encrypted Text: ");
				printf("%s\n",cipher);
				break;
				
			case DECPT:
				printf("Enter Cipher Text: ");
				scanf("%s",cipher);
				printf("Enter Cipher Key: ");
				scanf("%d",&key);
				decrypt(cipher,key,plain);
				printf("Decrypted Text: ");
				printf("%s\n",plain);
				break;
			
			case BREAK:
				printf("Enter Cipher Text: ");
				scanf("%s",cipher);
				printf("ALL POSIBILITIES:\n");
				breakCipher(cipher);
				break;
				
			case ENCPTM:
				printf("Enter Plain Text: ");
				scanf("%s",plain);
				printf("Enter Cipher Key MULTIPLICATIVE: ");
				scanf("%d",&key);
				encryptM(plain,key,cipher);
				printf("Encrypted Text: ");
				printf("%s\n",cipher);
				break;
				
			case DECPTM:
				printf("Enter Cipher Text: ");
				scanf("%s",cipher);
				printf("Enter Cipher Key MULTIPLICATIVE: ");
				scanf("%d",&key);
				decryptM(cipher,key,plain);
				printf("Decrypted Text: ");
				printf("%s\n",plain);
				break;
			
			case BREAKM:
				printf("Enter Cipher Text: ");
				scanf("%s",cipher);
				printf("ALL POSIBILITIES:\n");
				breakCipherM(cipher);
				break;
			case EXIT:
				return 0;
			
		}
		printf("\nCHOICE: ");
		scanf("%d%*c",&menu);
	}
	
		
	return 0;
}

void encrypt(char *plain, int key, char *cipher)
{
	int i=0;
	for(i=0;plain[i] != '\0';i++)
	{
		
		cipher[i] = ((plain[i]-97)+key)%26 + 97;
	}
	return;
}

void decrypt(char *cipher, int key, char *plain)
{
	int i=0;
	for(i=0;cipher[i] != '\0';i++)
	{
		
		plain[i] = ((cipher[i]-97)-key)%26 + 97;
	}
	return;
}

void breakCipher(char *cipher)
{
	int key=1;
	char decoded[200];
	for(key=1;key<26;key++)
	{
		decrypt(cipher,key,decoded);
		printf("KEY: %2d | %s\n",key,decoded);
	}
	return;
}

void encryptM(char *plain,int key, char *cipher)
{
	int i=0;
	for(i=0;plain[i] != '\0';i++)
	{
		cipher[i] = ((plain[i]-97)*key)%26 + 97;
	}
	cipher[i] = '\0';
	return;
}


void decryptM(char *cipher,int key, char *plain)
{
	int i=0;
	
	// find inverse
	int dekey = key;
	for(i=2;1;i++)
	{
		if( (key*i)%26 == 1)
		{
			dekey = i;
			break;
		}
	}
	
	for(i=0;cipher[i] != '\0';i++)
	{
		plain[i] = ((cipher[i]-97)*dekey)%26 + 97;
	}
	plain[i] = '\0';
	return;
}

void breakCipherM(char *cipher)
{
	int key=2;
	char decoded[200];
	for(key=2;key<26;key++)
	{
		decryptM(cipher,key,decoded);
		printf("KEY: %2d | %s\n",key,decoded);
	}
	return;
}
