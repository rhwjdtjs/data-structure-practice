#include <stdio.h>
#include <stdlib.h>
#define MAX 8

typedef struct {
	char name[100];
	double lan;
	double math;
	double computer;
	double total;
}str;
void sort_score(str *p);
int main()
{
	str *s;
	int count = 0;
	s = (str*)malloc(100 * sizeof(str));
	FILE *fp;
	int i = 0;
	int j = 0;
	char fname[1000];
	printf("입력할 파일명을 입력하세요: ");
	gets(fname);

	fp = fopen(fname, "r");

	if (fp == NULL)
	{
		printf("텍스트 파일을 찾을 수 없습니다.\n");
	}
	while (!feof(fp))
	{
		fscanf(fp, "%s %lf %lf %lf", s[count].name, &s[count].lan, &s[count].math, &s[count].computer);
		s[count].total = s[count].lan + s[count].math + s[count].computer;
		count++;
	}
	printf("------------[입력한 성적표]--------------\n");
	for (int i = 0; i < count; i++)
	{
		printf("l\t%s\t%.1lf\t%.1lf\t%.1lf\tl\n", s[i].name, s[i].lan, s[i].math, s[i].computer);
	}
	printf("-----------------------------------------\n");
	printf("\n\n");

	sort_score(s);
	printf("l-------------------[성적표 순위별]-----------------l\n");
	printf("l\t이름\t언어\t수리\t컴퓨터\t총점\t등수l\n");
	printf("l---------------------------------------------------l\n");
	for (int i = 0; i < count; i++)
	{
		printf("l\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t %d  l\n", s[i].name, s[i].lan, s[i].math, s[i].computer, s[i].total, i + 1);
		printf("l---------------------------------------------------l\n");
	}

	fclose(fp);
	free(s);
}
void sort_score(str *p)
{
	str temp;
	int i = 0;
	int j = 0;
	for (i = 0; i < MAX; i++) {
		for (j = i + 1; j < MAX; j++) {
			if (p[i].total < p[j].total) {
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
		//p[i]= p[j];
	}
}