/*
 * main.c — Таксины тариф (APL121, Бие даалт №1 — Code Quest)
 * Зай (км), хүлээлгийн минут, шөнийн нэмэгдэл -> аяллын үнэ;
 * 1–10 км-ийн үнийн хүснэгт; 3 аяллыг үнээр эрэмбэлэх.
 * quest.fprg блок схемтэй алхам алхмаар тохирно.
 */
#include <stdio.h>

#define BASE_FARE 1000.0   /* суух хөлс (₮)           */
#define PER_KM    1500.0   /* 1 км-ийн үнэ (₮)        */
#define PER_MIN   200.0    /* хүлээлгийн 1 минут (₮)  */
#define NIGHT_PCT 20.0     /* шөнийн нэмэгдэл (%)     */
#define N 3                /* аяллын тоо              */

int main(void)
{
    double dist[N], wait[N], price[N];
    int rank[N];
    int km, i, j, r, night;
    double p;

    /* 1. 1–10 км-ийн үнийн хүснэгт (хүлээлэггүй) */
    printf("Км | Өдөр  | Шөнө\n");
    for (km = 1; km <= 10; km++) {
        p = BASE_FARE + km * PER_KM;
        printf("%2d | %5.0f | %5.0f\n", km, p, p + p * NIGHT_PCT / 100);
    }

    /* 2. 3 аяллын үнэ — оролтыг do-while-аар шалгана */
    for (i = 0; i < N; i++) {
        printf("\nАялал %d\n", i + 1);

        do {
            printf("Зай (км, 0-ээс их): ");
            scanf("%lf", &dist[i]);
            if (dist[i] <= 0) {
                printf("Буруу утга! Дахин оруулна уу.\n");
            }
        } while (dist[i] <= 0);

        do {
            printf("Хүлээлэг (мин, 0 ба түүнээс их): ");
            scanf("%lf", &wait[i]);
            if (wait[i] < 0) {
                printf("Буруу утга! Дахин оруулна уу.\n");
            }
        } while (wait[i] < 0);

        do {
            printf("Шөнө үү? (1 = тийм, 0 = үгүй): ");
            scanf("%d", &night);
            if (night != 0 && night != 1) {
                printf("Буруу утга! Дахин оруулна уу.\n");
            }
        } while (night != 0 && night != 1);

        price[i] = BASE_FARE + dist[i] * PER_KM + wait[i] * PER_MIN;
        if (night == 1) {
            price[i] = price[i] + price[i] * NIGHT_PCT / 100;
        }
        printf("Үнэ: %.0f₮\n", price[i]);
    }

    /* 3. Эрэмбэ: өөрөөсөө хямд аялал хэд байна вэ гэж тоолно */
    for (i = 0; i < N; i++) {
        rank[i] = 1;
        for (j = 0; j < N; j++) {
            if (price[j] < price[i]) {
                rank[i]++;
            }
        }
    }

    printf("\n--- Хямдаас үнэтэй рүү ---\n");
    for (r = 1; r <= N; r++) {
        for (i = 0; i < N; i++) {
            if (rank[i] == r) {
                printf("%d. Аялал %d: %.0f₮\n", r, i + 1, price[i]);
            }
        }
    }

    return 0;
}
