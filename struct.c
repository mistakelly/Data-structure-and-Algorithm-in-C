#include <stdio.h>

/* Define a c structure to represent a "person" ,
	with the following information: name (a string of up to 50 characters),
	age(an integer), height (a
		- floating point number ) write a program that reads data of three people,
		stores it in an array of "person"  structures,
			and then displays the information for the person with the highest age
*/

/**
 * @struct-person - struct of a student.
 * @name - student name.
 * @age - student age.
 * @height - student height
 */
struct		Person
{
	char	name[50];
	int		age;
	float	height;
};

/**
 * @brief - function that takes input bout students and finds
 * the student with the highest age then displays that student details
 *
 * @param pers - array of students information.
 * @param pers_size - size of the array.
 * @return - the index of the student with the highest age in the array.
 */
int			findHighestAge(struct Person pers[], int pers_size);

/*Driver code */
int	main(void)
{
	struct Person	pers[3];
	int				pers_size;
	int				highestAgeIndex;

	pers_size = sizeof(pers) / sizeof(pers[0]);
	for (int i = 0; i < pers_size; i++)
	{
		/* code */
		printf("Enter person name [%d]: ", i + 1);
		scanf("%s", pers[i].name);
		printf("Enter person age [%d]: ", i + 1);
		scanf("%d", &pers[i].age);
		printf("Enter person height [%d]: ", i + 1);
		scanf("%f", &pers[i].height);
		printf("\n");
	}
	highestAgeIndex = findHighestAge(pers, pers_size);
	/*printing the values*/
	printf("Details of the person with the highest age\n");
	printf("\n%s\n", pers[highestAgeIndex].name);
	printf("%d\n", pers[highestAgeIndex].age);
	printf("%f\n", pers[highestAgeIndex].height);
	return (0);
}

int	findHighestAge(struct Person pers[], int pers_size)
{
	int i;
	int highestAge;
	int highestAgeIndex;

	highestAge = pers[0].age;
	highestAgeIndex = 0;

	for (i = 0; i < pers_size; i++)
	{
		/* code */
		/*Finding and displaying the information of the person with the highest age*/
		if (pers[i].age > highestAge)
		{
			highestAge = pers[i].age;
			/*keep track of the person with the highest age*/
			highestAgeIndex = i;
		}
	}
	printf("\n");
	return (highestAgeIndex);
}
