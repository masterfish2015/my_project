#include "stdio.h"
#include "math.h"
#define MIN 1e-8
int main()
{
	double pi, team, s, sign=-1.0;
	int i;
	for(team=2.0,i=2, s=1; 
		fabs(team)>MIN; i++){
		team=sign/(2*i-1);
		s+=team;
		sign*=-1;
	}
	pi = 4*s;
	printf("pi = %.8lf.\n", pi); 
	//输出：pi = 3.14159267.
	return 0;
}