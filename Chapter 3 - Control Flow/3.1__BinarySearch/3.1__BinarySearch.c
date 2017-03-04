#include "stdio.h"
#include "Global.h"

int binSearch(int element, int range)
{
	int min, max, mid;

	min = 0;
	max = range - 1;

	while(min <= max)
	{
		mid = (min + max) / 2;

		if(element <= buffer[mid])
			max = mid - 1;

		else
			min = mid + 1;
	}

	if(buffer[min] == element)
		return min;
	else
		return NOTFOUND;
}

int getElementToBeSearched(int element)
{
	printf("\n\tEnter the element to be searched : ");

	scanf("%d", &element);

	return element;
}

int populateInputArray()
{
	int index;

	printf("\n\tNumber of elements : ");

	scanf("%d", &range);

	for(index = 0; index < range; ++index)
	{
		printf("\nEnter element %d : ", index + 1);
		scanf("%d", &buffer[index]);
	}

	return range;
}

int main()
{
	int element, range, position;

	range = populateInputArray();

	element	= getElementToBeSearched(element);

	position = binSearch(element , range);

	if(position != -1)
		printf("\nElement found at position %d !\n", position + 1);

	else
		printf("\nNot Found !\n");

	return 0;
}