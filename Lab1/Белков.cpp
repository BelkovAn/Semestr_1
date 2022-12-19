#include <iostream>
#define N 5
int main()
{
	int arr[N][N]; //matrix
	arr[0][0] = 1;
	int vr = 0; //vertical real
	int hr = 1; //horizont real
	int vc, hc, i1; //vertical change, horizont change, index
	char x = 1; //pokazatel' kraia
	int n = N * N;
	for (i1 = 2; i1 < n; i1++)
	{
		if ((vr == 0) && (hr == (N - 1)) && (x == 0)) // left-down from corner
		{
			x = 1;
			vc = 1;
			hc = 0;
		}
		else if ((vr == 0) && (hr == (N - 1)) && (x == 1)) // left-down from line
		{
			x = 0;
			vc = 1;
			hc = -1;
		}
		else if ((hr == 0) && (vr == (N - 1)) && (x == 0)) // right-up from corner
		{
			x = 1;
			vc = 0;
			hc = 1;
		}
		else if ((hr == 0) && (vr == (N - 1)) && (x == 1)) // right-up from line
		{
			x = 0;
			vc = -1;
			hc = 1;
		}
		else if ((vr == 0) && (x == 0)) // just left
		{
			x = 1;
			hc = 1;
			vc = 0;
		}
		else if ((vr == 0) && (x == 1))
		{
			x = 0;
			vc = 1;
			hc = -1;
		}
		else if((hr == 0) && (x == 0)) // just up
		{
			x = 1;
			hc = 0;
			vc = 1;
		}
		else if ((hr == 0) && (x == 1))
		{
			x = 0;
			hc = 1;
			vc = -1;
		}
		else if ((x == 0) && (vr == (N - 1))) // just right
		{
			x = 1;
			vc = 0;
			hc = 1;
		}
		else if ((x == 1) && (vr == (N - 1)))
		{
			x = 0;
			vc = -1;
			hc = 1;
		}
		else if ((x == 0) && (hr == (N - 1))) // just down
		{
			x = 1;
			vc = 1;
			hc = 0;
		}
		else if ((x == 1) && (hr == (N - 1)))
		{
			x = 0;
			vc = 1;
			hc = -1;
		}
		arr[vr][hr] = i1; // end
		hr += hc;
		vr += vc;
	}
	arr[N - 1][N - 1] = n;
	for (i1 = 0; i1 < n; i1++)
	{
		printf("%t %t %d", arr[i1 % N][i1 / N]);
		if (i1 % N == N - 1)
		{
			printf("\n");
		}
	}
}