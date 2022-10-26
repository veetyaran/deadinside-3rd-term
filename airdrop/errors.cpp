#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
int errors_array(int ret)
{
	if(ret != SUCCESS)
    {
		switch(ret)
		{
			case ERROR_OPEN:
				printf("Cannot open\n");
					break;
			case ERROR_READ:
				printf("Cannot read\n");
					break;
			case ERROR_MEM:
				printf("Not enough memory\n");
					break;
			default:
				printf("Unknown ERROR %d in\n", ret);
		}
	}
	return ret;
}