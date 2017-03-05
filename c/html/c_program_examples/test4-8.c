#include<stdio.h>

int main()
{
    float score;
    char grade;
input_score:
    printf("input a score[0--100]:");
    scanf("%f", &score);

    if(score<0 || score>100){
        printf("error input. ");
        goto input_score;
    }

    switch( (int)(score/10)){
        case 10: case 9: grade='A'; break;
        case 8: grade='B'; break;
        case 7: grade='C'; break;
        case 6: grade='D'; break;
        case 5: case 4: case 3: case 2: case 1: case 0:
            grade='E';break;
    }
    printf("score=%.2f, grade=%c\n", score, grade);
    return 0;
}
