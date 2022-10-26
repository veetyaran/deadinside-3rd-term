#ifndef ERRORS_H
#define ERRORS_H
enum errors
{
	SUCCESS,
	ERROR_OPEN,
	ERROR_READ,
	ERROR_MEM,
};

int errors_array (int ret);

#endif