//�������
#include<stdio.h>
	int i,j=0,k,l,o,temp,number=0;
	char arr[9900];
	char arr1[9900],arr2[9900];
//ð�ݷ�����
int maopao(int num,char array[]){
	for(k=0;k<number-1;k++){
		for(l=k+1;l<num;l++){
			if(array[k]>array[l]){
				temp=array[l];
				array[l]=array[k];
				array[k]=temp;		
			}
		}
	}	
	return 0;
}
//������
int main(){
	printf("������Ҫ���������������Сд��ĸ�����:\n");
	scanf("%s",&arr);//Ϊʲô���ﲻдarr[9900]???
	//ȡ�������ַ��е�����
	for(i=0;i<100;i++){
	
		if(48<=arr[i] && arr[i]<=57){
			
			arr1[j]=arr[i];
			j++;
			number++;
		}

	}
	//ð����������
	maopao(number,arr1);
	for(o=0;o<number;o++){
	
		printf("%c",arr1[o]);
	
	}
	//ȡ�������ַ��е���ĸ
	j=0;number=0;
	for(i=0;i<100;i++){
	
		if(97<=arr[i] && arr[i]<=122){
				
			arr2[j]=arr[i];
			j++;
			number++;
		}

	}
	//ð����������
	maopao(number,arr2);
	for(o=0;o<number;o++){
	
		printf("%c",arr2[o]);
	
	}
	printf("\n");
	return 0;
}
