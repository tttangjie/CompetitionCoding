#include<stdio.h>
int main()
{
	FILE* file = NULL;
	unsigned char buff[2];
	unsigned int order;
	unsigned int position;
	unsigned char buffer[32];
	int i,j,k;
	file = fopen("HZK16","rb");
	scanf("%s",buff);
	printf("%.2x %.2x\n",buff[0],buff[1]);
	order = 94*(unsigned int)(buff[0]-0xa1)+(unsigned int)(buff[1]-0xa1);
	position = order*32;
	printf("offset is %d\n",position);
	
	fseek(file, position, SEEK_SET);
	fread(buffer, 1, 32, file);
	for(i=0;i<16;i++) {
		for(j=0;j<2;j++) 
			for(k=7;k>=0;k--)
				if(buffer[i*2+j]&1<<k)
					putchar('*');
				else
					putchar(' ');
		putchar('\n');
	}
	printf("uchar code key[32] = {");
	for(i=0;i<32;i++) {
		if(i==31)
			printf("0x%02x}",buffer[i]);
		else
			printf("0x%02x,",buffer[i]);
	} 
	fclose(file);
	return 0;
 } 
