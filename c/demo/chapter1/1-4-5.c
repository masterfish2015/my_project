#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14159

int main()
{
    /*创建一个svg文件 */
    FILE *svg_file;
    int i;
    double x,y;
    int x1, y1;

    char filename[100];
    printf("input svg file name:");
    scanf("%s", filename);

    svg_file=fopen(filename,"w");
    if(svg_file==NULL){
        printf("error, can not create file:%s\n", filename);
        exit(-1);
    }
    /* 写入svg头*/
    fprintf(svg_file, "<svg width=\"600\" height=\"300\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">");
    fprintf(svg_file, "<polyline style=\"fill:white;stroke:red;stroke-width:2\" points=\"");
    for(i=0;i<=360;i++){
        x = i*PI/180.0;
        y = sin(x);
        x1 = floor(x*300.0/(2*PI)+0.5);
        y1 = floor(300.0*(1-y)/2.0+0.5);
        fprintf(svg_file, " %d,%d ", x1,y1);
    }
    fprintf(svg_file, "\"/>");
    /* 写入svg结尾*/
    fprintf(svg_file, "</svg>");
    fclose(svg_file);
}
