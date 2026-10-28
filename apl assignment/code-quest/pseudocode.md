# Псевдокод — Таксины тариф

Блок схем (`quest.fprg`) болон `main.c`-тэй алхам алхмаар тохирно. `←` нь утга оноох үйлдэл.

```
ALGORITHM TaxiFare
  // Тариф (тогтмол утга)
  baseFare ← 1000          // суух хөлс, ₮
  perKm    ← 1500          // 1 км, ₮
  perMin   ← 200           // хүлээлгийн 1 минут, ₮
  nightPct ← 20            // шөнийн нэмэгдэл, %

  // 1. 1–10 км-ийн үнийн хүснэгт (хүлээлэггүй)
  OUTPUT "Км | Өдөр | Шөнө"
  FOR km ← 1 TO 10
    p ← baseFare + km * perKm
    OUTPUT km, p, p + p * nightPct / 100
  END FOR

  // 2. 3 аяллын үнэ
  FOR i ← 0 TO 2
    OUTPUT "Аялал", i + 1

    DO
      INPUT dist[i]
      IF dist[i] <= 0 THEN OUTPUT "Буруу утга! Дахин оруулна уу."
    WHILE dist[i] <= 0

    DO
      INPUT wait[i]
      IF wait[i] < 0 THEN OUTPUT "Буруу утга! Дахин оруулна уу."
    WHILE wait[i] < 0

    DO
      INPUT night                       // 1 = шөнө, 0 = өдөр
      IF night ≠ 0 AND night ≠ 1 THEN OUTPUT "Буруу утга! Дахин оруулна уу."
    WHILE night ≠ 0 AND night ≠ 1

    price[i] ← baseFare + dist[i] * perKm + wait[i] * perMin
    IF night = 1 THEN
      price[i] ← price[i] + price[i] * nightPct / 100
    END IF
    OUTPUT "Үнэ:", price[i]
  END FOR

  // 3. Эрэмбэ: өөрөөсөө хямд аялал хэд байгааг тоолно
  FOR i ← 0 TO 2
    rank[i] ← 1
    FOR j ← 0 TO 2
      IF price[j] < price[i] THEN
        rank[i] ← rank[i] + 1
      END IF
    END FOR
  END FOR

  // Хямдаас үнэтэй рүү хэвлэх
  OUTPUT "--- Хямдаас үнэтэй рүү ---"
  FOR r ← 1 TO 3
    FOR i ← 0 TO 2
      IF rank[i] = r THEN
        OUTPUT r, "Аялал", i + 1, price[i]
      END IF
    END FOR
  END FOR
END
```
