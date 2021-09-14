#include <stdio.h>
//converting a bitmask in input to the corresponding days of the week

int main() {
    int week, i;
    int first = 0;
    printf("Enter number: ");
    scanf("%d", &week);
    for (i = 1; i <= 7; i++) {
        if (week & 1) {
            if (!first) first = 1;
            else printf("-");
            switch (i) {
                case 1:
                    printf("Sun");
                    break;
                case 2:
                    printf("Mon");
                    break;
                case 3:
                    printf("Tue");
                    break;
                case 4:
                    printf("Wed");
                    break;
                case 5:
                    printf("Thru");
                    break;
                case 6:
                    printf("Fri");
                    break;
                case 7:
                    printf("Sat");
                    break;
                default:
                    printf("Invalid input!");
            }
        }
        week = week >> 1;

    }
    return 0;
}
