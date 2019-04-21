#include <iostream>
#include "circlebuf.h"

int main()
{
	struct circlebuf* cb = new circlebuf();

	circlebuf_init(cb);


	printf("%d \n", cb->capacity);
	char data1[] = "123456789";
	char data2[] = "abcdefghi";
	char data3[] = "111111111";
	char data4[] = "222222222";
	circlebuf_push_back(cb, data1, sizeof(data1));

	printf("%d \n", cb->capacity);
	circlebuf_push_back(cb, data2, sizeof(data2));
	printf("%d \n", cb->capacity);

	circlebuf_push_front(cb, data3, sizeof(data3));
	printf("%d \n", cb->capacity);

	circlebuf_push_front(cb, data4, sizeof(data4));

	circlebuf_reserve(cb, cb->capacity * 2);
	printf("%d \n", cb->capacity);
	circlebuf_free(cb);
	free(cb);
	
	return 0;
}