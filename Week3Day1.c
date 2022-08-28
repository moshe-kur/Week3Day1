#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

int main1()
{
	int nums[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &nums[i]);
	}
	FILE* f = fopen("EX1.bin", "w");
	for (int i = 0; i < 10; i++)
	{
		fwrite(&nums[i], sizeof(int), 1, f);

	}
	fclose(f);
	return 0;
}
//קלטו מהמשתמש 2 מערכים, אחד בגודל 4 ואחד בגודל 8. המערך שסכומו הכי גבוהה אותו יש לשמור בקובץ 
int main2()
{
	int arr1[4];
	int arr2[8];
	int sum1 = 0;
	int sum2 = 0;

	printf("enter 4 numner\n");
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &arr1[i]);
		sum1 += arr1[i];
		
	}
	printf("enter 8 numner\n");
	for (int i = 0; i < 8; i++)
	{
		scanf("%d", &arr2[i]);
		sum2 += arr2[i];
	}
	int winnum;
	winnum = (sum1 > sum2) ? 4 : 8;

	if (sum1 == sum2)
	{
		printf("The same sum try again");
	}
	else
	{
		FILE* f = fopen("EX2.bin", "w");
		if (winnum==4)
		{
			for (int i = 0; i < 4; i++)
			{
				fwrite(&arr1[i], sizeof(int), 1, f);

			}
		}
		else
		{
			for (int i = 0; i < 8; i++)
			{
				fwrite(&arr2[i], sizeof(int), 1, f);

			}
		}

		
		fclose(f);

		
	}
	return 0;
}

int main3()
{
	struct question
	{
		int val;
		char name[100];
		short answer;
	};
	struct question check[3];
	for (int i = 0; i < 3; i++)
	{
		scanf(" %s %d", check[i].name, &check[i].val);
	}
	for (int i = 0; i < 3; i++)
	{
		if (check[i].val>10 && strlen(check[i].name) > 5)
		{
			check[i].answer = 1;
		}
		else
		{
			check[i].answer = 0;
		}
	}
	FILE* f = fopen("EX3.bin", "w");
	for (int i = 0; i < 3; i++)
	{
		fwrite(&check, sizeof(struct question),3, f);
	}
	fclose(f);
	return 0;
}
//EX4
int main()
{
	int nums[15];
	int numnum = 11;
	for (int i = 0; i < 15; i++)
	{
		nums[i] = numnum;
		numnum += 11;
	}
	FILE* f = fopen("EX4.bin", "w");
	fwrite(&nums, sizeof(int), 15, f);
	fclose(f);

	return 0;
}