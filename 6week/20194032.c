#include <stdio.h>
#include <stdlib.h>
typedef struct student {
	int num;
	char name[20];
	int lan;
	int math;
	int eng;
	int com;
}student;

typedef struct {
	int num1;
	char name1[20];
	int lan1;
	int math1;
	int eng1;
	int com1;
	struct NODE *link;
}NODE;

int main()
{
	student temp;
	student s[100];
	int count = 0;
	NODE *list = NULL;
	NODE *prev, *p;
	FILE *fp;
	fp=fopen("data.txt","r");
	if (fp == NULL)
	{
		printf("파일을 찾지 못했어요\n");
		return 0;
	}
	while (!feof(fp))
	{
		fscanf(fp, "%d %s %d %d %d %d", &s[count].num, s[count].name, &s[count].lan, &s[count].math, &s[count].eng, &s[count].com);
		count++;
		
	}
for (int i = 0; i < 10; i++)
		{
			for (int j = i + 1; j < 10; j++)
			{
				if (s[i].num <s[j+1].num) {
					temp = s[i];
					s[i] = s[j];
					s[j] = temp;
				}
			}
		}
	int input;
	int search;
	int number;
	int num;
	char name[20];
	int lan, math, eng, com;
	
	while (1)
	{
		p = (NODE *)malloc(sizeof(NODE)*10);
		printf("0: 종료 1: 학생 데이터 입력 2: 학생 검색 3: 목록 보기\n");
		scanf("%d", &input);
		if (input == 0)
			exit(1);
		if (input == 1)
		{
			printf("추가할 학생 번호: ");
			scanf("%d", &number);
			p->num1 = number;
			printf("이름: ");
			getchar();
			gets_s(name, 20);
			strcpy(p->name1, name);
			printf("언어 성적: ");
			scanf("%d", &lan);
			p->lan1 = lan;
			printf("수리 성적: ");
			scanf("%d", &math);
			p->math1 = math;
			printf("영어 성적: ");
			scanf("%d", &eng);
			p->eng1 = eng;
			printf("컴퓨터 성적: ");
			scanf("%d", &com);
			p->com1 = com;
			if (list == NULL)
				list = p;
			else
				prev->link = p;
			p->link = NULL;
			prev = p;
		}
		if (input == 2)
		{
			p = list;
			printf("검색할 학생 번호: ");
			scanf("%d", &search);
			if (search <= 3)
			{
				printf("번호\t이름\t언어\t수리\t영어\t컴퓨터\n");
				printf("%d\t%s\t%d\t%d\t%d\t%d\n", s[search - 1].num, s[search - 1].name, s[search - 1].lan, s[search - 1].math, s[search - 1].eng, s[search - 1].com);
			}
			if (search > 3)
			{
				
				
				{	
					while (p != NULL)
					{
						if (p->num1 == search)
						{
							printf("번호\t이름\t언어\t수리\t영어\t컴퓨터\n");
							printf("%d\t%s\t%d\t%d\t%d\t%d\n", p->num1, p->name1, p->lan1, p->math1, p->eng1, p->com1);
							

							
						}
						p = p->link;
					}
				}
				
			}
				
			
		}
		if (input == 3)
		{
			printf("번호\t이름\t언어\t수리\t영어\t컴퓨터\n");
			for (int i = 0; i < count; i++)
			{
				
				printf("%d\t%s\t%d\t%d\t%d\t%d\n", s[i].num, s[i].name, s[i].lan, s[i].math, s[i].eng, s[i].com);
			}
			p = list;
			while (p != NULL)
			{
				printf("%d\t%s\t%d\t%d\t%d\t%d\n", p->num1, p->name1, p->lan1, p->math1, p->eng1, p->com1);
				p = p->link;
			}
		}
	}
	fclose(fp);
	free(p);

}