#include"array.h"
#include<stdio.h>

int *setArr(int arr[],int x,int len)//ȫ��Ԫ����Ϊͬһֵ 
{
	printf("��������Ԫ��ȫ��Ϊ%d�������\n",x);
	for(int i=0;i<len;i++){
		arr[i] = x;
		printf("%d ",arr[i]);
	}
	return arr;
}

int mergeArr(int arr1[],int arr2[],int len1,int len2)//�ϲ��������飬����������������
{
	printf("�ϲ����飬�������arr3��\n");
	int *newArr = new int[len1 + len2];
	int k = 0;
	for(int i=0;i<len1;i++)
	{
		newArr[k++] = arr1[i];
	}
	for(int i=0;i<len2;i++)
	{
		newArr[k++] = arr2[i];
	}
	
	for(int i=0;i<(len1+len2);i++)
	{
		printf("arr3[%d] = %d\n",i,newArr[i]);
	}
	
	return 0;
}

int searchArr(int arr[],int value,int len) //����ĳ�����������е�λ��
{
	int index;
	for(int i=0;i<len;i++)
	{
		if(arr[i] == value){
			index = i;
			printf("%d�������е�λ����arr[%d]\n",value,i);
			break;
		}
		else
			index = -1;
	}
	if(index == -1)
		printf("��������������\n");
	return index;
}

int *deleteArr(int arr[],int y,int len) //��������ɾ��ĳ�������м���ɾ����
{
	int j = 0;
	printf("ɾ��%d���arr:{",y);
	for(int i=0;i<len;i++)
	{
		
		if(arr[i] != y)
		{
			arr[j] = arr[i];
			j++;
			printf("%d ",arr[i]);
		}
	
	}
		printf("}\n");
	return arr;
} 




