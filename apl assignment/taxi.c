/*
 * taxi.c — Таксины тариф
 * Зай (км), хүлээлгийн минут, шөнийн нэмэгдэл -> аяллын үнэ;
 * 1–10 км-ийн үнийн хүснэгт; 3 аяллыг үнээр эрэмбэлэх.
 *
 * Ажиллуулах (VS Code terminal):
 *   chcp 65001            <- Windows дээр монгол үсэг зөв харагдуулна (нэг удаа)
 *   gcc taxi.c -o taxi
 *   .\taxi
 */
#include <stdio.h>

#define BASE_FARE 1000.0   /* суух хөлс (₮)        — жишээ утга */
#define PER_KM    1500.0   /* 1 км-ийн үнэ (₮)                  */
#define PER_MIN   200.0    /* хүлээлгийн 1 минут (₮)            */
#define NIGHT_PCT 20.0     /* шөнийн нэмэгдэл (%)               */
#define N 3                /* аяллын тоо                        */

int main(void)
{
    double dist[N], wait[N], price[N];
    int rank[N];
    int km, i, j, r, night;
    double p;

    /* 1. 1–10 км-ийн үнийн хүснэгт */
    printf("Км | Өдөр  | Шөнө\n");
    for (km = 1; km <= 10; km++) {
        p = BASE_FARE + km * PER_KM;
        printf("%2d | %5.0f | %5.0f\n", km, p, p + p * NIGHT_PCT / 100);
    }

    /* 2. 3 аяллын үнэ */
    for (i = 0; i < N; i++) {
        printf("\nАялал %d — зай (км): ", i + 1);
        scanf("%lf", &dist[i]);
        printf("Хүлээлэг (мин): ");
        scanf("%lf", &wait[i]);
        printf("Шөнө үү? (1 = тийм, 0 = үгүй): ");
        scanf("%d", &night);

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
