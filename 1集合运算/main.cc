#include <cstdio>
#include <cstdlib>
#include "llist.h"
#include "listset.h"
#include <cstring>


//去重排序
void sort(char *s)
{	int j = 0;
	//asc字符表
	char list[128]={0};
	//printf("%s\n",s);
	for(int i=0;s[i]!='\0'; i++){
		list[s[i]] = 1;
	}
	for(int i=0;i<128;i++){
		if(list[i]==1){
			s[j] = i;
			j++;
		}
	}
	s[j]=0;
	//printf("%s\n",s);
}


int main() {
	char sa[1024],sb[1024],*p;
	LinkList *A, *B, *S = NULL, *U = NULL, *D = NULL;

	// 初始化两个列表用于存放初始集合
	InitList(A);
	InitList(B);
	
	// 获取两个集合
	scanf("%s%s", sa, sb);
	printf("A:%s\t\tB:%s\n",sa,sb);
	
	sort(sa);
	sort(sb);
	printf("Sort\nA:%s\t\tB:%s\n",sa,sb);

	// 读入集合 A, 假设输入是已排序的, 并且不存在重复的元素
	for (unsigned int i = 0; i < strlen(sa); i++) {
		if( LocateElem(A, sa[i]) ==-1){ 
			ListInsert(A, i, sa[i]);
		}
	}

	// 读入集合 A, 假设输入是已排序的, 并且不存在重复的元素
	for (unsigned int i = 0; i < strlen(sb); i++) {
		if( LocateElem(B, sb[i]) ==-1)
			ListInsert(B, i, sb[i]);
	}

	// 计算交、并、差
	Intersection(S, A, B);
	Union(U, A, B);
	Difference(D, A, B);

	// 输出结果
	printf("Set A (Size %d): \n\t", ListLength(A));
	DispList(A);
	printf("Set B (Size %d): \n\t", ListLength(B));
	DispList(B);
	printf("\n");

	printf("A ^ B (Size %d): \n\t", ListLength(S));
	DispList(S);

	printf("A U B (Size %d): \n\t", ListLength(U));
	DispList(U);

	printf("A - B (Size %d): \n\t", ListLength(D));
	DispList(D);

	return 0;
}
