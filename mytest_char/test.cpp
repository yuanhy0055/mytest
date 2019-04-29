#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <time.h>

/*
void tt(void)
{
char *p="abcefghijklmn"+5;
printf("c%",p[3]);
}
*/

struct device {
	char bus_id[16];
	int a;
	int b;
};

void sub_call(struct device *dev)
{
	char buf[1024];

	memset(buf, 0, 1024);
	sprintf(buf, "%s", __FUNCTION__);
	sprintf(buf, "device: '%s': %s()--who call me? [%p]=%08x\n",
		dev->bus_id, __FUNCTION__,
		((&dev)-1) , *((unsigned *)((&dev)-1))
	);

	//debugPrintf(buf);
	OutputDebugString(L"Kill.......................%d\n");

	double fn = 200.0;
	for (int i = 0; i < 10; i++) {
		fn = (fn + 4/fn) / 2;
	}
	sprintf(buf, "\t\t%f\n\n", fn);
	OutputDebugStringA(buf);
}


static char k101[] = "qwerasdfzxcv1";

void c_firar(struct device *p)
{
	sub_call(p);
}

void pc_main()
{
	//int i;

	struct device aa = {
		"1234567",
		15,
		32,
	};
	

	printf("I am main(), main_addr=%p\n", pc_main);

	c_firar(&aa);
	printf("sub_call exit\n");

/*
	i = 0;
	while(k101[i])
		printf("%02x ", k101[i++]);
*/
}

void TT_pi(void)
{
	int M = 0;
	int N = 0;
	int i = 1;

	unsigned int X, Y, R2 = 0;

	srand((unsigned)time(NULL));

	do {
		X = rand();
		Y = rand();
		R2 = X * X + Y * Y;

		if (R2 >= 32767*32767) {
			N = N + 1;
		}
		else {
			M = M + 1;
		}

		i = i + 1;

	} while (i < 1001);

	printf("N=%d, M=%d ....... %f\n", N, M, 4.0*M/(N+M));
}