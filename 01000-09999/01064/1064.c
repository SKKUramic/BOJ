// 1064 평행사변형
#include <stdio.h>
#include <math.h>

int main(){
    double point[3][2];
    double length[3];
    double temp;
    double error = -1;
    for (int i = 0; i < 3; i++){
        scanf("%lf %lf", &point[i][0], &point[i][1]);
    }
    /*
    if (point[0][0] == point[1][0] && point[1][0] == point[2][0]){
        printf("%lf", error);
        return 0;
    }
    else if (point[0][1] == point[1][1] && point[1][1] == point[2][1]){
        printf("%lf", error);
        return 0;
    }
    else*/ 
    if ( fabs((point[1][0] - point[0][0])*(point[2][1] - point[0][1]) - (point[1][1] - point[0][1])*(point[2][0] - point[0][0])) < 0.000001){
        printf("%lf", error);
        return 0;
    }
    length[0] = (point[0][0] - point[1][0]) * (point[0][0] - point[1][0]) + (point[0][1] - point[1][1]) * (point[0][1] - point[1][1]);
    length[1] = (point[1][0] - point[2][0]) * (point[1][0] - point[2][0]) + (point[1][1] - point[2][1]) * (point[1][1] - point[2][1]);
    length[2] = (point[2][0] - point[0][0]) * (point[2][0] - point[0][0]) + (point[2][1] - point[0][1]) * (point[2][1] - point[0][1]);
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2 - i; j++){
            if (length[j] > length[j + 1]){
                temp = length[j];
                length[j] = length[j + 1];
                length[j + 1] = temp;
            }
        }
    }
    //printf("%lf %lf %lf\n", length[0], length[1], length[2]);
    printf("%.15lf", 2 * (sqrt(length[2]) - sqrt(length[0])));
    return 0;
}