#include <stdio.h>
#define MONTH 13
#define YEAR 8

int main()
{
	FILE *fp;

	fp = fopen("data.txt", "r");
	int data[YEAR][MONTH];
	int monthaverage[12] = { 0 };
	int sum = 0;
	int count = 0;
	if (fp == NULL)
	{
		printf("���� �ҷ����⸦ �����߽��ϴ�.\n");
		return 0;
	}
	printf("l=================================================================================l\n");
	printf("l �⵵ l 1��l 2��l 3��l 4�� l 5�� l 6�� l 7�� l 8�� l 9�� l10�� l11��l12��l�⺰����l\n");
	while (!feof(fp))
	{
		fscanf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d %d", &data[count][0],
			&data[count][1],
			&data[count][2],
			&data[count][3],
			&data[count][4],
			&data[count][5],
			&data[count][6],
			&data[count][7],
			&data[count][8],
			&data[count][9],
			&data[count][10],
			&data[count][11],
			&data[count][12]
		);
			count++;
	}
	for (int i = 0; i < count; i++)
	{
		sum = data[i][1] + data[i][2] + data[i][3] + data[i][4] + data[i][5] + data[i][6] + data[i][7] + data[i][8] + data[i][9] + data[i][10] + data[i][11] + data[i][12];
		printf("l%d��l  %dl  %dl  %dl  %dl  %dl  %dl  %dl  %dl  %dl  %dl %dl  %dl  %d  l\n", data[i][0], data[i][1], data[i][2], data[i][3], data[i][4],
			data[i][5], data[i][6], data[i][7], data[i][8], data[i][9], data[i][10], data[i][11], data[i][12], sum);
			monthaverage[0] += data[i][1];
			monthaverage[1] += data[i][2];
			monthaverage[2] += data[i][3];
			monthaverage[3] += data[i][4];
			monthaverage[4] += data[i][5];
			monthaverage[5] += data[i][6];
			monthaverage[6] += data[i][7];
			monthaverage[7] += data[i][8];
			monthaverage[8] += data[i][9];
			monthaverage[9] += data[i][10];
			monthaverage[10] += data[i][11];
			monthaverage[11] += data[i][12];
			
	}
	printf("l=================================================================================l\n");
	printf("l������� %d�� %d�� %d�� %d�� %d�� %d�� %d�� %d�� %d�� %d�� %d�� %dl", monthaverage[0]/count, monthaverage[1] / count, monthaverage[2] / count, monthaverage[3] / count, monthaverage[4] / count
	, monthaverage[5] / count, monthaverage[6] / count, monthaverage[7] / count, monthaverage[8] / count, monthaverage[9] / count, monthaverage[10] / count, monthaverage[11] / count);
	printf("\nl=========================================================================l");
	fclose(fp);
}