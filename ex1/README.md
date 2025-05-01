<<<<<<< HEAD
# README - תרגיל ראשון במערכות הפעלה

## הקדמה

בתרגיל זה יש 7 שאלות, כל אחת ממומשת בתיקייה נפרדת (`q1` עד `q7`) תחת התיקייה הראשית `ex1`. לכל שאלה קובץ `Makefile` משלה שמאפשר לקמפל (ולפעמים גם להריץ) את הקוד. קובץ `Makefile` הראשי בתיקיית `ex1` מריץ את הקימפול (או הניקוי) של כל השאלות.

## איך מקמפלים את כל התרגיל

```bash
cd "/home/orel/Documents/C Projects/OS_ex1/os-assignments/ex1"
make all       # מקמפל את כל השאלות
make clean     # מנקה את כל הקבצים שהתקבלו מהקומפילציה
```

---

## שאלה 1 - קריסות עקב זיכרון (stack overflow, invalid memory, memory leaks)

**דרישות**:
לממש 3 תוכניות שגויות (debug / no-debug).

**מימוש**:

* קבצים: `bad_prog_1.c`, `bad_prog_2.c`, `bad_prog_3.c`
* המייקפיל מקמפל 6 גרסאות (debug ו־non-debug).

**הרצה**:

```bash
cd "/home/orel/Documents/C Projects/OS_ex1/os-assignments/ex1/q1"
make all
./bad_prog_1
```

**פלט צפוי:**

```
Segmentation fault (core dumped)
```

---

## שאלה 2 - קבוצת מנדלברוט בסיסית

**דרישות**:
בודקת האם מספר מרוכב שייך לקבוצת מנדלברוט בעזרת פרמטרים משורת הפקודה.

**הרצה**:

```bash
cd "/home/orel/Documents/C Projects/OS_ex1/os-assignments/ex1/q2"
make all
./mandelbrot -1.627 -0.001
```

**פלט צפוי:**

```
-1.627 + -0.001i is in the Mandelbrot set
```

---

## שאלה 3 - מנדלברוט באמצעות ספרייה דינמית

**דרישות**:

* לפצל את קוד הלוגיקה לקובץ `.so`
* לקשר מול הספרייה הראשית בעת הריצה

**הרצה**:

```bash
cd "/home/orel/Documents/C Projects/OS_ex1/os-assignments/ex1/q3"
make all
LD_LIBRARY_PATH=. ./main
```

**דוגמת קלט:**

```
Enter a complex number (real and imaginary parts): -1.627 -0.001
```

**פלט צפוי:**

```
-1.627 + -0.001i is in the Mandelbrot set
```

---

## שאלה 4 - כיסוי קוד עם `gcov`

**דרישות**:

* לקמפל עם דגלי כיסוי קוד
* להריץ עם קלט תקין ושגוי

**הרצה**:

```bash
cd "/home/orel/Documents/C Projects/OS_ex1/os-assignments/ex1/q4"
make all
make run
```

**פלט צפוי:**

```
main.c:...Lines executed: XX%...
```

---

## שאלה 5 - פרופיל ביצועים עם `gprof`

**דרישות**:

* לממש שלוש גרסאות של אלגוריתם מציאת תת־מערך מירבי
* לקמפל עם `-pg` ולנתח עם `gprof`

**הרצה**:

```bash
cd "/home/orel/Documents/C Projects/OS_ex1/os-assignments/ex1/q5"
make all
make run
```

**פלט צפוי (קטע מתוך קובץ output100.txt):**

```
~ maximum subarray O(n) ~
...
~ maximum subarray O(n^2) ~
...
~ maximum subarray O(n^3) ~
...
```

---

## שאלה 6 - תקשורת בין תהליכים עם `signal`

**דרישות**:

* מימוש מקלט ומשדר באמצעות `SIGUSR1` ו־`SIGUSR2`
* שליחת מסר סיביות־סיביות

**הרצה (בשני טרמינלים)**:

```bash
cd "/home/orel/Documents/C Projects/OS_ex1/os-assignments/ex1/q6"
make all
make run_receiver   # טרמינל ראשון
make run_sender     # טרמינל שני
```

**פלט צפוי:**

```
Receiver terminal:
My PID is 77260
Bit received: 0
Bit received: 1
...
```

```
Sender terminal:
Enter receiver PID: 77260
Enter message: 37
```

---

## שאלה 7 - תהליכים ו־fork/exec/wait

**דרישות**:

* שימוש בפורק והרצת תוכניות אחרות

**הרצה**:

```bash
cd "/home/orel/Documents/C Projects/OS_ex1/os-assignments/ex1/q7"
make all
./findPhone
./add2PB
```

**פלט צפוי:**

```
Please enter a name to search:
...
Found phone: 054-xxx-xxxx
```

---

## קובץ Makefile ראשי - סיכום

```makefile
.PHONY: all clean q1 q2 q3 q4 q5 q6 q7

all: q1 q2 q3 q4 q5 q6 q7

q1 q2 q3 q4 q5 q6 q7:
    @echo "===> Building $@..."
    $(MAKE) -C $@ all

clean:
    @$(MAKE) -C q1 clean
    @$(MAKE) -C q2 clean
    @$(MAKE) -C q3 clean
    @$(MAKE) -C q4 clean
    @$(MAKE) -C q5 clean
    @$(MAKE) -C q6 clean
    @$(MAKE) -C q7 clean
```

---

