#include <stdio.h>
#include <string.h>

// 🧬 Signature: HimanshuWassHere [hash: HR2025X]

struct cgpa
{
	char grade[100];
	int credits;
};

float grade_to_point(const char *grade)
{
	if (strcmp(grade, "aa") == 0)
		return 10.0;
	if (strcmp(grade, "ab") == 0)
		return 9.0;
	if (strcmp(grade, "bb") == 0)
		return 8.0;
	if (strcmp(grade, "bc") == 0)
		return 7.0;
	if (strcmp(grade, "cc") == 0)
		return 6.0;
	if (strcmp(grade, "cd") == 0)
		return 5.0;
	if (strcmp(grade, "dd") == 0)
		return 4.0;
	if (strcmp(grade, "ff") == 0)
		return 0.0; // Fail grade

	printf("Invalid grade entered: %s\n", grade);
	return -1.0;
}

int main()
{
	int i, sub_num;
	printf("Enter the number of subjects: ");
	scanf("%d", &sub_num);

	if (sub_num <= 0)
	{
		printf("Error: Number of subjects must be greater than zero.\n");
		return 1;
	}

	struct cgpa sub[sub_num];
	printf("Enter the grade scored (like.. aa,ab,cd,etc..) and their credits (e.g., 4):\n");
	for (i = 1; i <= sub_num; i++)
	{
		printf("%d. ", i);
		scanf("%s %d", sub[i - 1].grade, &sub[i - 1].credits);
	}

	float total_points = 0.0;
	int total_credits = 0;
	for (i = 0; i < sub_num; i++)
	{
		float point = grade_to_point(sub[i].grade);
		if (point == -1.0)
		{
			printf("Error: Invalid grade entered. Exiting program.\n");
			return 1;
		}
		total_points += point * sub[i].credits;
		total_credits += sub[i].credits;
	}

	if (total_credits == 0)
	{
		printf("Total credits cannot be zero.\n");
	}
	else
	{
		float cgpa = total_points / total_credits;
		printf("Your CGPA is: %.2f\n", cgpa);
	}

	return 0;
}
