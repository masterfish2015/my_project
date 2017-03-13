#include<stdio.h>
#include<math.h>
#define DELTA 1e-6
#define F(x) (2*(x)*(x)*(x)-4*(x)*(x)+3*(x)-6)

int main(void)
{
    double x_min=-10, x_max=10, f1, f2, fc, x_center;
    int i = 0;

    printf("[No.]%15s%15s%15s%15s%15s%15s%15s\n",
              "x_min","f(x_min)","x_center","f(x_center)",
              "x_max","f(x_max)","|x_max-x_min|");
    
    do{
        x_center = (x_max + x_min)/2.0; //找到 x_min 和 x_max 的中点
        fc = F(x_center);
        //如果f1和fc符号相同，则x_min和x_center在根的同一侧，因此要替换x_min
        if(f1*fc>0){
            x_min = x_center;
            f1 = fc;
        }else{//否则x_max和x_center在同一侧，要替换x_max
            x_max = x_center;
            f2 = fc;
        }
        printf("[%3d]%15.6f%15.6f%15.6f%15.6f%15.6f%15.6f%15g\n",
            ++i,x_min,f1,x_center,fc,x_max,f2, fabs(x_max-x_min));
    }while(fabs(x_max-x_min)>DELTA);

    return 0;
}