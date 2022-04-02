#include <stdio.h>

int qualityPoints(void);

int main() {

    int score;

    score = qualityPoints();

    printf("Student's mark is %d\n", score);

return 0;
}

int qualityPoints(void) {

    int points;

    printf("Enter student's points(1 - 100): ");
    scanf("%d", &points);

    if (points <= 100 && points >= 90)
        return 4;
    else
        if (points < 90 && points >= 80)
            return 3;
        else
            if (points < 80 && points >= 70)
                return 2;
            else
                if (points < 70 && points >= 60)
                    return 1;
                else
                    return 0;
}
