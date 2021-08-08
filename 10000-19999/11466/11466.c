// 11466 Alex Origami Squares
#include <stdio.h>

int main(){
    double height, width, bigger, smaller;
    scanf("%lf %lf", &height, &width);
    bigger = height > width ? height : width;
    smaller = height < width ? height : width;
    if (bigger > 3 * smaller){
        printf("%lf", smaller);
    }
    else if (bigger > 1.5 * smaller){
        printf("%lf", bigger / 3);
    }
    else {
        printf("%lf", smaller / 2);
    }
    return 0;
}