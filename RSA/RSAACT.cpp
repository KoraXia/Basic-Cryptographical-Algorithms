 #include "stdafx.h"



int smallprimes[] =
{ 2, 1, 2, 2, 4, 2, 4, 2, 4, 6, 2, 6, 4, 2, 4, 6, 6, 2, 6, 4, 2,
6, 4, 6, 8, 4, 2, 4, 2, 4, 14, 4, 6, 2, 10, 2, 6, 6, 4, 6, 6,
2, 10, 2, 4, 2, 12, 12, 4, 2, 4, 6, 2, 10, 6, 6, 6, 2, 6, 4, 2,
10, 14, 4, 2, 4, 14, 6, 10, 2, 4, 6, 8, 6, 6, 4, 6, 8, 4, 8, 10,
2, 10, 2, 6, 4, 6, 8, 4, 2, 4, 12, 8, 4, 8, 4, 6, 12, 2, 18, 6,
10, 6, 6, 2, 6, 10, 6, 6, 2, 6, 6, 4, 2, 12, 10, 2, 4, 6, 6, 2,
12, 4, 6, 8, 10, 8, 10, 8, 6, 6, 4, 8, 6, 4, 8, 4, 14, 10, 12, 2,
10, 2, 4, 2, 10, 14, 4, 2, 4, 14, 4, 2, 4, 20, 4, 8, 10, 8, 4, 6,
6, 14, 4, 6, 6, 8, 6, 12, 4, 6, 2, 10, 2, 6, 10, 2, 10, 2, 6, 18,
4, 2, 4, 6, 6, 8, 6, 6, 22, 2, 10, 8, 10, 6, 6, 8, 12, 4, 6, 6,
2, 6, 12, 10, 18, 2, 4, 6, 2, 6, 4, 2, 4, 12, 2, 6, 34, 6, 6, 8,
18, 10, 14, 4, 2, 4, 6, 8, 4, 2, 6, 12, 10, 2, 4, 2, 4, 6, 12, 12,
8, 12, 6, 4, 6, 8, 4, 8, 4, 14, 4, 6, 2, 4, 6, 2, 6, 10, 20, 6,
4, 2, 24, 4, 2, 10, 12, 2, 10, 8, 6, 6, 6, 18, 6, 4, 2, 12, 10, 12,
8, 16, 14, 6, 4, 2, 4, 2, 10, 12, 6, 6, 18, 2, 16, 2, 22, 6, 8, 6,
4, 2, 4, 8, 6, 10, 2, 10, 14, 10, 6, 12, 2, 4, 2, 10, 12, 2, 16, 2,
6, 4, 2, 10, 8, 18, 24, 4, 6, 8, 16, 2, 4, 8, 16, 2, 4, 8, 6, 6,
4, 12, 2, 22, 6, 2, 6, 4, 6, 14, 6, 4, 2, 6, 4, 6, 12, 6, 6, 14,
4, 6, 12, 8, 6, 4, 26, 18, 10, 8, 4, 6, 2, 6, 22, 12, 2, 16, 8, 4,
12, 14, 10, 2, 4, 8, 6, 6, 4, 2, 4, 6, 8, 4, 2, 6, 10, 2, 10, 8,
4, 14, 10, 12, 2, 6, 4, 2, 16, 14, 4, 6, 8, 6, 4, 18, 8, 10, 6, 6,
8, 10, 12, 14, 4, 6, 6, 2, 28, 2, 10, 8, 4, 14, 4, 8, 12, 6, 12, 4,
6, 20, 10, 2, 16, 26, 4, 2, 12, 6, 4, 12, 6, 8, 4, 8, 22, 2, 4, 2,
12, 28, 2, 6, 6, 6, 4, 6, 2, 12, 4, 12, 2, 10, 2, 16, 2, 16, 6, 20,
16, 8, 4, 2, 4, 2, 22, 8, 12, 6, 10, 2, 4, 6, 2, 6, 10, 2, 12, 10,
2, 10, 14, 6, 4, 6, 8, 6, 6, 16, 12, 2, 4, 14, 6, 4, 8, 10, 8, 6,
6, 22, 6, 2, 10, 14, 4, 6, 18, 2, 10, 14, 4, 2, 10, 14, 4, 8, 18, 4,
6, 2, 4, 6, 2, 12, 4, 20, 22, 12, 2, 4, 6, 6, 2, 6, 22, 2, 6, 16,
6, 12, 2, 6, 12, 16, 2, 4, 6, 14, 4, 2, 18, 24, 10, 6, 2, 10, 2, 10,
2, 10, 6, 2, 10, 2, 10, 6, 8, 30, 10, 2, 10, 8, 6, 10, 18, 6, 12, 12,
2, 18, 6, 4, 6, 6, 18, 2, 10, 14, 6, 4, 2, 4, 24, 2, 12, 6, 16, 8,
6, 6, 18, 16, 2, 4, 6, 2, 6, 6, 10, 6, 12, 12, 18, 2, 6, 4, 18, 8,
24, 4, 2, 4, 6, 2, 12, 4, 14, 30, 10, 6, 12, 14, 6, 10, 12, 2, 4, 6,
8, 6, 10, 2, 4, 14, 6, 6, 4, 6, 2, 10, 2, 16, 12, 8, 18, 4, 6, 12,
2, 6, 6, 6, 28, 6, 14, 4, 8, 10, 8, 12, 18, 4, 2, 4, 24, 12, 6, 2,
16, 6, 6, 14, 10, 14, 4, 30, 6, 6, 6, 8, 6, 4, 2, 12, 6, 4, 2, 6,
22, 6, 2, 4, 18, 2, 4, 12, 2, 6, 4, 26, 6, 6, 4, 8, 10, 32, 16, 2,
6, 4, 2, 4, 2, 10, 14, 6, 4, 8, 10, 6, 20, 4, 2, 6, 30, 4, 8, 10,
6, 6, 8, 6, 12, 4, 6, 2, 6, 4, 6, 2, 10, 2, 16, 6, 20, 4, 12, 14,
28, 6, 20, 4, 18, 8, 6, 4, 6, 14, 6, 6, 10, 2, 10, 12, 8, 10, 2, 10,
8, 12, 10, 24, 2, 4, 8, 6, 4, 8, 18, 10, 6, 6, 2, 6, 10, 12, 2, 10,
6, 6, 6, 8, 6, 10, 6, 2, 6, 6, 6, 10, 8, 24, 6, 22, 2, 18, 4, 8,
10, 30, 8, 18, 4, 2, 10, 6, 2, 6, 4, 18, 8, 12, 18, 16, 6, 2, 12, 6,
10, 2, 10, 2, 6, 10, 14, 4, 24, 2, 16, 2, 10, 2, 10, 20, 4, 2, 4, 8,
16, 6, 6, 2, 12, 16, 8, 4, 6, 30, 2, 10, 2, 6, 4, 6, 6, 8, 6, 4,
12, 6, 8, 12, 4, 14, 12, 10, 24, 6, 12, 6, 2, 22, 8, 18, 10, 6, 14, 4,
2, 6, 10, 8, 6, 4, 6, 30, 14, 10, 2, 12, 10, 2, 16, 2, 18, 24, 18, 6,
16, 18, 6, 2, 18, 4, 6, 2, 10, 8, 10, 6, 6, 8, 4, 6, 2, 10, 2, 12,
4, 6, 6, 2, 12, 4, 14, 18, 4, 6, 20, 4, 8, 6, 4, 8, 4, 14, 6, 4,
14, 12, 4, 2, 30, 4, 24, 6, 6, 12, 12, 14, 6, 4, 2, 4, 18, 6, 12, 8,
6, 4, 12, 2, 12, 30, 16, 2, 6, 22, 14, 6, 10, 12, 6, 2, 4, 8, 10, 6,
6, 24, 14, 6, 4, 8, 12, 18, 10, 2, 10, 2, 4, 6, 20, 6, 4, 14, 4, 2,
4, 14, 6, 12, 24, 10, 6, 8, 10, 2, 30, 4, 6, 2, 12, 4, 14, 6, 34, 12,
8, 6, 10, 2, 4, 20, 10, 8, 16, 2, 10, 14, 4, 2, 12, 6, 16, 6, 8, 4,
8, 4, 6, 8, 6, 6, 12, 6, 4, 6, 6, 8, 18, 4, 20, 4, 12, 2, 10, 6,
2, 10, 12, 2, 4, 20, 6, 30, 6, 4, 8, 10, 12, 6, 2, 28, 2, 6, 4, 2,
16, 12, 2, 6, 10, 8, 24, 12, 6, 18, 6, 4, 14, 6, 4, 12, 8, 6, 12, 4,
6, 12, 6, 12, 2, 16, 20, 4, 2, 10, 18, 8, 4, 14, 4, 2, 6, 22, 6, 14,
6, 6, 10, 6, 2, 10, 2, 4, 2, 22, 2, 4, 6, 6, 12, 6, 14, 10, 12, 6,
8, 4, 36, 14, 12, 6, 4, 6, 2, 12, 6, 12, 16, 2, 10, 8, 22, 2, 12, 6,
4, 6, 18, 2, 12, 6, 4, 12, 8, 6, 12, 4, 6, 12, 6, 2, 12, 12, 4, 14,
6, 16, 6, 2, 10, 8, 18, 6, 34, 2, 28, 2, 22, 6, 2, 10, 12, 2, 6, 4,
8, 22, 6, 2, 10, 8, 4, 6, 8, 4, 12, 18, 12, 20, 4, 6, 6, 8, 4, 2,
16, 12, 2, 10, 8, 10, 2, 4, 6, 14, 12, 22, 8, 28, 2, 4, 20, 4, 2, 4,
14, 10, 12, 2, 12, 16, 2, 28, 8, 22, 8, 4, 6, 6, 14, 4, 8, 12, 6, 6,
4, 20, 4, 18, 2, 12, 6, 4, 6, 14, 18, 10, 8, 10, 32, 6, 10, 6, 6, 2,
6, 16, 6, 2, 12, 6, 28, 2, 10, 8, 16, 6, 8, 6, 10, 24, 20, 10, 2, 10,
2, 12, 4, 6, 20, 4, 2, 12, 18, 10, 2, 10, 2, 4, 20, 16, 26, 4, 8, 6,
4, 12, 6, 8, 12, 12, 6, 4, 8, 22, 2, 16, 14, 10, 6, 12, 12, 14, 6, 4,
20, 4, 12, 6, 2, 6, 6, 16, 8, 22, 2, 28, 8, 6, 4, 20, 4, 12, 24, 20,
4, 8, 10, 2, 16, 2, 12, 12, 34, 2, 4, 6, 12, 6, 6, 8, 6, 4, 2, 6,
24, 4, 20, 10, 6, 6, 14, 4, 6, 6, 2, 12, 6, 10, 2, 10, 6, 20, 4, 26,
4, 2, 6, 22, 2, 24, 4, 6, 2, 4, 6, 24, 6, 8, 4, 2, 34, 6, 8, 16,
12, 2, 10, 2, 10, 6, 8, 4, 8, 12, 22, 6, 14, 4, 26, 4, 2, 12, 10, 8,
4, 8, 12, 4, 14, 6, 16, 6, 8, 4, 6, 6, 8, 6, 10, 12, 2, 6, 6, 16,
8, 6, 6, 12, 10, 2, 6, 18, 4, 6, 6, 6, 12, 18, 8, 6, 10, 8, 18, 4,
14, 6, 18, 10, 8, 10, 12, 2, 6, 12, 12, 36, 4, 6, 8, 4, 6, 2, 4, 18,
12, 6, 8, 6, 6, 4, 18, 2, 4, 2, 24, 4, 6, 6, 14, 30, 6, 4, 6, 12,
6, 20, 4, 8, 4, 8, 6, 6, 4, 30, 2, 10, 12, 8, 10, 8, 24, 6, 12, 4,
14, 4, 6, 2, 28, 14, 16, 2, 12, 6, 4, 20, 10, 6, 6, 6, 8, 10, 12, 14,
10, 14, 16, 14, 10, 14, 6, 16, 6, 8, 6, 16, 20, 10, 2, 6, 4, 2, 4, 12,
2, 10, 2, 6, 22, 6, 2, 4, 18, 8, 10, 8, 22, 2, 10, 18, 14, 4, 2, 4,
18, 2, 4, 6, 8, 10, 2, 30, 4, 30, 2, 10, 2, 18, 4, 18, 6, 14, 10, 2,
4, 20, 36, 6, 4, 6, 14, 4, 20, 10, 14, 22, 6, 2, 30, 12, 10, 18, 2, 4,
14, 6, 22, 18, 2, 12, 6, 4, 8, 4, 8, 6, 10, 2, 12, 18, 10, 14, 16, 14,
4, 6, 6, 2, 6, 4, 2, 28, 2, 28, 6, 2, 4, 6, 14, 4, 12, 14, 16, 14,
4, 6, 8, 6, 4, 6, 6, 6, 8, 4, 8, 4, 14, 16, 8, 6, 4, 12, 8, 16,
2, 10, 8, 4, 6, 26, 6, 10, 8, 4, 6, 12, 14, 30, 4, 14, 22, 8, 12, 4,
6, 8, 10, 6, 14, 10, 6, 2, 10, 12, 12, 14, 6, 6, 18, 10, 6, 8, 18, 4,
6, 2, 6, 10, 2, 10, 8, 6, 6, 10, 2, 18, 10, 2, 12, 4, 6, 8, 10, 12,
14, 12, 4, 8, 10, 6, 6, 20, 4, 14, 16, 14, 10, 8, 10, 12, 2, 18, 6, 12,
10, 12, 2, 4, 2, 12, 6, 4, 8, 4, 44, 4, 2, 4, 2, 10, 12, 6, 6, 14,
4, 6, 6, 6, 8, 6, 36, 18, 4, 6, 2, 12, 6, 6, 6, 4, 14, 22, 12, 2,
18, 10, 6, 26, 24, 4, 2, 4, 2, 4, 14, 4, 6, 6, 8, 16, 12, 2, 42, 4,
2, 4, 24, 6, 6, 2, 18, 4, 14, 6, 28, 18, 14, 6, 10, 12, 2, 6, 12, 30,
6, 4, 6, 6, 14, 4, 2, 24, 4, 6, 6, 26, 10, 18, 6, 8, 6, 6, 30, 4,
12, 12, 2, 16, 2, 6, 4, 12, 18, 2, 6, 4, 26, 12, 6, 12, 4, 24, 24, 12,
6, 2, 12, 28, 8, 4, 6, 12, 2, 18, 6, 4, 6, 6, 20, 16, 2, 6, 6, 18,
10, 6, 2, 4, 8, 6, 6, 24, 16, 6, 8, 10, 6, 14, 22, 8, 16, 6, 2, 12,
4, 2, 22, 8, 18, 34, 2, 6, 18, 4, 6, 6, 8, 10, 8, 18, 6, 4, 2, 4,
8, 16, 2, 12, 12, 6, 18, 4, 6, 6, 6, 2, 6, 12, 10, 20, 12, 18, 4, 6,
2, 16, 2, 10, 14, 4, 30, 2, 10, 12, 2, 24, 6, 16, 8, 10, 2, 12, 22, 6,
2, 16, 20, 10, 2, 12, 12, 18, 10, 12, 6, 2, 10, 2, 6, 10, 18, 2, 12, 6,
4, 6, 2, 24, 28, 2, 4, 2, 10, 2, 16, 12, 8, 22, 2, 6, 4, 2, 10, 6,
20, 12, 10, 8, 12, 6, 6, 6, 4, 18, 2, 4, 12, 18, 2, 12, 6, 4, 2, 16,
12, 12, 14, 4, 8, 18, 4, 12, 14, 6, 6, 4, 8, 6, 4, 20, 12, 10, 14, 4,
2, 16, 2, 12, 30, 4, 6, 24, 20, 24, 10, 8, 12, 10, 12, 6, 12, 12, 6, 8,
16, 14, 6, 4, 6, 36, 20, 10, 30, 12, 2, 4, 2, 28, 12, 14, 6, 22, 8, 4,
18, 6, 14, 18, 4, 6, 2, 6, 34, 18, 2, 16, 6, 18, 2, 24, 4, 2, 6, 12,
6, 12, 10, 8, 6, 16, 12, 8, 10, 14, 40, 6, 2, 6, 4, 12, 14, 4, 2, 4,
2, 4, 8, 6, 10, 6, 6, 2, 6, 6, 6, 12, 6, 24, 10, 2, 10, 6, 12, 6,
6, 14, 6, 6, 52, 20, 6, 10, 2, 10, 8, 10, 12, 12, 2, 6, 4, 14, 16, 8,
12, 6, 22, 2, 10, 8, 6, 22, 2, 22, 6, 8, 10, 12, 12, 2, 10, 6, 12, 2,
4, 14, 10, 2, 6, 18, 4, 12, 8, 18, 12, 6, 6, 4, 6, 6, 14, 4, 2, 12,
12, 4, 6, 18, 18, 12, 2, 16, 12, 8, 18, 10, 26, 4, 6, 8, 6, 6, 4, 2,
10, 20, 4, 6, 8, 4, 20, 10, 2, 34, 2, 4, 24, 2, 12, 12, 10, 6, 2, 12,
30, 6, 12, 16, 12, 2, 22, 18, 12, 14, 10, 2, 12, 12, 4, 2, 4, 6, 12, 2,
16, 18, 2, 40, 8, 16, 6, 8, 10, 2, 4, 18, 8, 10, 8, 12, 4, 18, 2, 18,
10, 2, 4, 2, 4, 8, 28, 2, 6, 22, 12, 6, 14, 18, 4, 6, 8, 6, 6, 10,
8, 4, 2, 18, 10, 6, 20, 22, 8, 6, 30, 4, 2, 4, 18, 6, 30, 2, 4, 8,
6, 4, 6, 12, 14, 34, 14, 6, 4, 2, 6, 4, 14, 4, 2, 6, 28, 2, 4, 6,
8, 10, 2, 10, 2, 10, 2, 4, 30, 2, 12, 12, 10, 18, 12, 14, 10, 2, 12, 6,
10, 6, 14, 12, 4, 14, 4, 18, 2, 10, 8, 4, 8, 10, 12, 18, 18, 8, 6, 18,
16, 14, 6, 6, 10, 14, 4, 6, 2, 12, 12, 4, 6, 6, 12, 2, 16, 2, 12, 6,
4, 14, 6, 4, 2, 12, 18, 4, 36, 18, 12, 12, 2, 4, 2, 4, 8, 12, 4, 36,
6, 18, 2, 12, 10, 6, 12, 24, 8, 6, 6, 16, 12, 2, 18, 10, 20, 10, 2, 6,
18, 4, 2, 40, 6, 2, 16, 2, 4, 8, 18, 10, 12, 6, 2, 10, 8, 4, 6, 12,
2, 10, 18, 8, 6, 4, 20, 4, 6, 36, 6, 2, 10, 6, 24, 6, 14, 16, 6, 18,
2, 10, 20, 10, 8, 6, 4, 6, 2, 10, 2, 12, 4, 2, 4, 8, 10, 6, 12, 18,
14, 12, 16, 8, 6, 16, 8, 4, 2, 6, 18, 24, 18, 10, 12, 2, 4, 14, 10, 6,
6, 6, 18, 12, 2, 28, 18, 14, 16, 12, 14, 24, 12, 22, 6, 2, 10, 8, 4, 2,
4, 14, 12, 6, 4, 6, 14, 4, 2, 4, 30, 6, 2, 6, 10, 2, 30, 22, 2, 4,
6, 8, 6, 6, 16, 12, 12, 6, 8, 4, 2, 24, 12, 4, 6, 8, 6, 6, 10, 2,
6, 12, 28, 14, 6, 4, 12, 8, 6, 12, 4, 6, 14, 6, 12, 10, 6, 6, 8, 6,
6, 4, 2, 4, 8, 12, 4, 14, 18, 10, 2, 16, 6, 20, 6, 10, 8, 4, 30, 36,
12, 8, 22, 12, 2, 6, 12, 16, 6, 6, 2, 18, 4, 26, 4, 8, 18, 10, 8, 10,
6, 14, 4, 20, 22, 18, 12, 8, 28, 12, 6, 6, 8, 6, 12, 24, 16, 14, 4, 14,
12, 6, 10, 12, 20, 6, 4, 8, 18, 12, 18, 10, 2, 4, 20, 10, 14, 4, 6, 2,
10, 24, 18, 2, 4, 20, 16, 14, 10, 14, 6, 4, 6, 20, 6, 10, 6, 2, 12, 6,
30, 10, 8, 6, 4, 6, 8, 40, 2, 4, 2, 12, 18, 4, 6, 8, 10, 6, 18, 18,
2, 12, 16, 8, 6, 4, 6, 6, 2, 52, 14, 4, 20, 16, 2, 4, 6, 12, 2, 6,
12, 12, 6, 4, 14, 10, 6, 6, 14, 10, 14, 16, 8, 6, 12, 4, 8, 22, 6, 2,
18, 22, 6, 2, 18, 6, 16, 14, 10, 6, 12, 2, 6, 4, 8, 18, 12, 16, 2, 4,
14, 4, 8, 12, 12, 30, 16, 8, 4, 2, 6, 22, 12, 8, 10, 6, 6, 6, 14, 6,
18, 10, 12, 2, 10, 2, 4, 26, 4, 12, 8, 4, 18, 8, 10, 14, 16, 6, 6, 8,
10, 6, 8, 6, 12, 10, 20, 10, 8, 4, 12, 26, 18, 4, 12, 18, 6, 30, 6, 8,
6, 22, 12, 2, 4, 6, 6, 2, 10, 2, 4, 6, 6, 2, 6, 22, 18, 6, 18, 12,
8, 12, 6, 10, 12, 2, 16, 2, 10, 2, 10, 18, 6, 20, 4, 2, 6, 22, 6, 6,
18, 6, 14, 12, 16, 2, 6, 6, 4, 14, 12, 4, 2, 18, 16, 36, 12, 6, 14, 28,
2, 12, 6, 12, 6, 4, 2, 16, 30, 8, 24, 6, 30, 10, 2, 18, 4, 6, 12, 8,
22, 2, 6, 22, 18, 2, 10, 2, 10, 30, 2, 28, 6, 14, 16, 6, 20, 16, 2, 6,
4, 32, 4, 2, 4, 6, 2, 12, 4, 6, 6, 12, 2, 6, 4, 6, 8, 6, 4, 20,
4, 32, 10, 8, 16, 2, 22, 2, 4, 6, 8, 6, 16, 14, 4, 18, 8, 4, 20, 6,
12, 12, 6, 10, 2, 10, 2, 12, 28, 12, 18, 2, 18, 10, 8, 10, 48, 2, 4, 6,
8, 10, 2, 10, 30, 2, 36, 6, 10, 6, 2, 18, 4, 6, 8, 16, 14, 16, 6, 14,
4, 20, 4, 6, 2, 10, 12, 2, 6, 12, 6, 6, 4, 12, 2, 6, 4, 12, 6, 8,
4, 2, 6, 18, 10, 6, 8, 12, 6, 22, 2, 6, 12, 18, 4, 14, 6, 4, 20, 6,
16, 8, 4, 8, 22, 8, 12, 6, 6, 16, 12, 18, 30, 8, 4, 2, 4, 6, 26, 4,
14, 24, 22, 6, 2, 6, 10, 6, 14, 6, 6, 12, 10, 6, 2, 12, 10, 12, 8, 18,
18, 10, 6, 8, 16, 6, 6, 8, 16, 20, 4, 2, 10, 2, 10, 12, 6, 8, 6, 10,
20, 10, 18, 26, 4, 6, 30, 2, 4, 8, 6, 12, 12, 18, 4, 8, 22, 6, 2, 12,
34, 6, 18, 12, 6, 2, 28, 14, 16, 14, 4, 14, 12, 4, 6, 6, 2, 36, 4, 6,
20, 12, 24, 6, 22, 2, 16, 18, 12, 12, 18, 2, 6, 6, 6, 4, 6, 14, 4, 2,
22, 8, 12, 6, 10, 6, 8, 12, 18, 12, 6, 10, 2, 22, 14, 6, 6, 4, 18, 6,
20, 22, 2, 12, 24, 4, 18, 18, 2, 22, 2, 4, 12, 8, 12, 10, 14, 4, 2, 18,
16, 38, 6, 6, 6, 12, 10, 6, 12, 8, 6, 4, 6, 14, 30, 6, 10, 8, 22, 6,
8, 12, 10, 2, 10, 2, 6, 10, 2, 10, 12, 18, 20, 6, 4, 8, 22, 6, 6, 30,
6, 14, 6, 12, 12, 6, 10, 2, 10, 30, 2, 16, 8, 4, 2, 6, 18, 4, 2, 6,
4, 26, 4, 8, 6, 10, 2, 4, 6, 8, 4, 6, 30, 12, 2, 6, 6, 4, 20, 22,
8, 4, 2, 4, 72, 8, 4, 8, 22, 2, 4, 14, 10, 2, 4, 20, 6, 10, 18, 6,
20, 16, 6, 8, 6, 4, 20, 12, 22, 2, 4, 2, 12, 10, 18, 2, 22, 6, 18, 30,
2, 10, 14, 10, 8, 16, 50, 6, 10, 8, 10, 12, 6, 18, 2, 22, 6, 2, 4, 6,
8, 6, 6, 10, 18, 2, 22, 2, 16, 14, 10, 6, 2, 12, 10, 20, 4, 14, 6, 4,
36, 2, 4, 6, 12, 2, 4, 14, 12, 6, 4, 6, 2, 6, 4, 20, 10, 2, 10, 6,
12, 2, 24, 12, 12, 6, 6, 4, 24, 2, 4, 24, 2, 6, 4, 6, 8, 16, 6, 2,
10, 12, 14, 6, 34, 6, 14, 6, 4, 2, 30, 22, 8, 4, 6, 8, 4, 2, 28, 2,
6, 4, 26, 18, 22, 2, 6, 16, 6, 2, 16, 12, 2, 12, 4, 6, 6, 14, 10, 6,
8, 12, 4, 18, 2, 10, 8, 16, 6, 6, 30, 2, 10, 18, 2, 10, 8, 4, 8, 12,
24, 40, 2, 12, 10, 6, 12, 2, 12, 4, 2, 4, 6, 18, 14, 12, 6, 4, 14, 30,
4, 8, 10, 8, 6, 10, 18, 8, 4, 14, 16, 6, 8, 4, 6, 2, 10, 2, 12, 4,
2, 4, 6, 8, 4, 6, 32, 24, 10, 8, 18, 10, 2, 6, 10, 2, 4, 18, 6, 12,
2, 16, 2, 22, 6, 6, 8, 18, 4, 18, 12, 8, 6, 4, 20, 6, 30, 22, 12, 2,
6, 18, 4, 62, 4, 2, 12, 6, 10, 2, 12, 12, 28, 2, 4, 14, 22, 6, 2, 6,
6, 10, 14, 4, 2, 10, 6, 8, 10, 14, 10, 6, 2, 12, 22, 18, 8, 10, 18, 12,
2, 12, 4, 12, 2, 10, 2, 6, 18, 6, 6, 34, 6, 2, 12, 4, 6, 18, 18, 2,
16, 6, 6, 8, 6, 10, 18, 8, 10, 8, 10, 2, 4, 18, 26, 12, 22, 2, 4, 2,
22, 6, 6, 14, 16, 6, 20, 10, 12, 2, 18, 42, 4, 24, 2, 6, 10, 12, 2, 6,
10, 8, 4, 6, 12, 12, 8, 4, 6, 12, 30, 20, 6, 24, 6, 10, 12, 2, 10, 20,
6, 6, 4, 12, 14, 10, 18, 12, 8, 6, 12, 4, 14, 10, 2, 12, 30, 16, 2, 12,
6, 4, 2, 4, 6, 26, 4, 18, 2, 4, 6, 14, 54, 6, 52, 2, 16, 6, 6, 12,
26, 4, 2, 6, 22, 6, 2, 12, 12, 6, 10, 18, 2, 12, 12, 10, 18, 12, 6, 8,
6, 10, 6, 8, 4, 2, 4, 20, 24, 6, 6, 10, 14, 10, 2, 22, 6, 14, 10, 26,
4, 18, 8, 12, 12, 10, 12, 6, 8, 16, 6, 8, 6, 6, 22, 2, 10, 20, 10, 6,
44, 18, 6, 10, 2, 4, 6, 14, 4, 26, 4, 2, 12, 10, 8, 4, 8, 12, 4, 12,
8, 22, 8, 6, 10, 18, 6, 6, 8, 6, 12, 4, 8, 18, 10, 12, 6, 12, 2, 6,
4, 2, 16, 12, 12, 14, 10, 14, 6, 10, 12, 2, 12, 6, 4, 6, 2, 12, 4, 26,
6, 18, 6, 10, 6, 2, 18, 10, 8, 4, 26, 10, 20, 6, 16, 20, 12, 10, 8, 10,
2, 16, 6, 20, 10, 20, 4, 30, 2, 4, 8, 16, 2, 18, 4, 2, 6, 10, 18, 12,
14, 18, 6, 16, 20, 6, 4, 8, 6, 4, 6, 12, 8, 10, 2, 12, 6, 4, 2, 6,
10, 2, 16, 12, 14, 10, 6, 8, 6, 28, 2, 6, 18, 30, 34, 2, 16, 12, 2, 18,
16, 6, 8, 10, 8, 10, 8, 10, 44, 6, 6, 4, 20, 4, 2, 4, 14, 28, 8, 6,
16, 14, 30, 6, 30, 4, 14, 10, 6, 6, 8, 4, 18, 12, 6, 2, 22, 12, 8, 6,
12, 4, 14, 4, 6, 2, 4, 18, 20, 6, 16, 38, 16, 2, 4, 6, 2, 40, 42, 14,
4, 6, 2, 24, 10, 6, 2, 18, 10, 12, 2, 16, 2, 6, 16, 6, 8, 4, 2, 10,
6, 8, 10, 2, 18, 16, 8, 12, 18, 12, 6, 12, 10, 6, 6, 18, 12, 14, 4, 2,
10, 20, 6, 12, 6, 16, 26, 4, 18, 2, 4, 32, 10, 8, 6, 4, 6, 6, 14, 6,
18, 4, 2, 18, 10, 8, 10, 8, 10, 2, 4, 6, 2, 10, 42, 8, 12, 4, 6, 18,
2, 16, 8, 4, 2, 10, 14, 12, 10, 20, 4, 8, 10, 38, 4, 6, 2, 10, 20, 10,
12, 6, 12, 26, 12, 4, 8, 28, 8, 4, 8, 24, 6, 10, 8, 6, 16, 12, 8, 10,
12, 8, 22, 6, 2, 10, 2, 6, 10, 6, 6, 8, 6, 4, 14, 28, 8, 16, 18, 8,
4, 6, 20, 4, 18, 6, 2, 24, 24, 6, 6, 12, 12, 4, 2, 22, 2, 10, 6, 8,
12, 4, 20, 18, 6, 4, 12, 24, 6, 6, 54, 8, 6, 4, 26, 36, 4, 2, 4, 26,
12, 12, 4, 6, 6, 8, 12, 10, 2, 12, 16, 18, 6, 8, 6, 12, 18, 10, 2, 54,
4, 2, 10, 30, 12, 8, 4, 8, 16, 14, 12, 6, 4, 6, 12, 6, 2, 4, 14, 12,
4, 14, 6, 24, 6, 6, 10, 12, 12, 20, 18, 6, 6, 16, 8, 4, 6, 20, 4, 32,
4, 14, 10, 2, 6, 12, 16, 2, 4, 6, 12, 2, 10, 8, 6, 4, 2, 10, 14, 6,
6, 12, 18, 34, 8, 10, 6, 24, 6, 2, 10, 12, 2, 30, 10, 14, 12, 12, 16, 6,
6, 2, 18, 4, 6, 30, 14, 4, 6, 6, 2, 6, 4, 6, 14, 6, 4, 8, 10, 12,
6, 32, 10, 8, 22, 2, 10, 6, 24, 8, 4, 30, 6, 2, 12, 16, 8, 6, 4, 6,
8, 16, 14, 6, 6, 4, 2, 10, 12, 2, 16, 14, 4, 2, 4, 20, 18, 10, 2, 10,
6, 12, 30, 8, 18, 12, 10, 2, 6, 6, 4, 12, 12, 2, 4, 12, 18, 24, 2, 10,
6, 8, 16, 8, 6, 12, 10, 14, 6, 12, 6, 6, 4, 2, 24, 4, 6, 8, 6, 4,
2, 4, 6, 14, 4, 8, 10, 24, 24, 12, 2, 6, 12, 22, 30, 2, 6, 18, 10, 6,
6, 8, 4, 2, 6, 10, 8, 10, 6, 8, 16, 6, 14, 6, 4, 24, 8, 10, 2, 12,
6, 4, 36, 2, 22, 6, 8, 6, 10, 8, 6, 12, 10, 14, 10, 6, 18, 12, 2, 12,
4, 26, 10, 14, 16, 18, 8, 18, 12, 12, 6, 16, 14, 24, 10, 12, 8, 22, 6, 2,
10, 60, 6, 2, 4, 8, 16, 14, 10, 6, 24, 6, 12, 18, 24, 2, 30, 4, 2, 12,
6, 10, 2, 4, 14, 6, 16, 2, 10, 8, 22, 20, 6, 4, 32, 6, 18, 4, 2, 4,
2, 4, 8, 52, 14, 22, 2, 22, 20, 10, 8, 10, 2, 6, 4, 14, 4, 6, 20, 4,
6, 2, 12, 12, 6, 12, 16, 2, 12, 10, 8, 4, 6, 2, 28, 12, 8, 10, 12, 2,
4, 14, 28, 8, 6, 4, 2, 4, 6, 2, 12, 58, 6, 14, 10, 2, 6, 28, 32, 4,
30, 8, 6, 4, 6, 12, 12, 2, 4, 6, 6, 14, 16, 8, 30, 4, 2, 10, 8, 6,
4, 6, 26, 4, 12, 2, 10, 18, 12, 12, 18, 2, 4, 12, 8, 12, 10, 20, 4, 8,
16, 12, 8, 6, 16, 8, 10, 12, 14, 6, 4, 8, 12, 4, 20, 6, 40, 8, 16, 6,
36, 2, 6, 4, 6, 2, 22, 18, 2, 10, 6, 36, 14, 12, 4, 18, 8, 4, 14, 10,
2, 10, 8, 4, 2, 18, 16, 12, 14, 10, 14, 6, 6, 42, 10, 6, 6, 20, 10, 8,
12, 4, 12, 18, 2, 10, 14, 18, 10, 18, 8, 6, 4, 14, 6, 10, 30, 14, 6, 6,
4, 12, 38, 4, 2, 4, 6, 8, 12, 10, 6, 18, 6, 50, 6, 4, 6, 12, 8, 10,
32, 6, 22, 2, 10, 12, 18, 2, 6, 4, 30, 8, 6, 6, 18, 10, 2, 4, 12, 20,
10, 8, 24, 10, 2, 6, 22, 6, 2, 18, 10, 12, 2, 30, 18, 12, 28, 2, 6, 4,
6, 14, 6, 12, 10, 8, 4, 12, 26, 10, 8, 6, 16, 2, 10, 18, 14, 6, 4, 6,
14, 16, 2, 6, 4, 12, 20, 4, 20, 4, 6, 12, 2, 36, 4, 6, 2, 10, 2, 22,
8, 6, 10, 12, 12, 18, 14, 24, 36, 4, 20, 24, 10, 6, 2, 28, 6, 18, 8, 4,
6, 8, 6, 4, 2, 12, 28, 18, 14, 16, 14, 18, 10, 8, 6, 4, 6, 6, 8, 22,
12, 2, 10, 18, 6, 2, 18, 10, 2, 12, 10, 18, 32, 6, 4, 6, 6, 8, 6, 6,
10, 20, 6, 12, 10, 8, 10, 14, 6, 10, 14, 4, 2, 22, 18, 2, 10, 2, 4, 20,
4, 2, 34, 2, 12, 6, 10, 2, 10, 18, 6, 14, 12, 12, 22, 8, 6, 16, 6, 8,
4, 12, 6, 8, 4, 36, 6, 6, 20, 24, 6, 12, 18, 10, 2, 10, 26, 6, 16, 8,
6, 4, 24, 18, 8, 12, 12, 10, 18, 12, 2, 24, 4, 12, 18, 12, 14, 10, 2, 4,
24, 12, 14, 10, 6, 2, 6, 4, 6, 26, 4, 6, 6, 2, 22, 8, 18, 4, 18, 8,
4, 24, 2, 12, 12, 4, 2, 52, 2, 18, 6, 4, 6, 12, 2, 6, 12, 10, 8, 4,
2, 24, 10, 2, 10, 2, 12, 6, 18, 40, 6, 20, 16, 2, 12, 6, 10, 12, 2, 4,
6, 14, 12, 12, 22, 6, 8, 4, 2, 16, 18, 12, 2, 6, 16, 6, 2, 6, 4, 12,
30, 8, 16, 2, 18, 10, 24, 2, 6, 24, 4, 2, 22, 2, 16, 2, 6, 12, 4, 18,
8, 4, 14, 4, 18, 24, 6, 2, 6, 10, 2, 10, 38, 6, 10, 14, 6, 6, 24, 4,
2, 12, 16, 14, 16, 12, 2, 6, 10, 26, 4, 2, 12, 6, 4, 12, 8, 12, 10, 18,
6, 14, 28, 2, 6, 10, 2, 4, 14, 34, 2, 6, 22, 2, 10, 14, 4, 2, 16, 8,
10, 6, 8, 10, 8, 4, 6, 2, 16, 6, 6, 18, 30, 14, 6, 4, 30, 2, 10, 14,
4, 20, 10, 8, 4, 8, 18, 4, 14, 6, 4, 24, 6, 6, 18, 18, 2, 36, 6, 10,
14, 12, 4, 6, 2, 30, 6, 4, 2, 6, 28, 20, 4, 20, 12, 24, 16, 18, 12, 14,
6, 4, 12, 32, 12, 6, 10, 8, 10, 6, 18, 2, 16, 14, 6, 22, 6, 12, 2, 18,
4, 8, 30, 12, 4, 12, 2, 10, 38, 22, 2, 4, 14, 6, 12, 24, 4, 2, 4, 14,
12, 10, 2, 16, 6, 20, 4, 20, 22, 12, 2, 4, 2, 12, 22, 24, 6, 6, 2, 6,
4, 6, 2, 10, 12, 12, 6, 2, 6, 16, 8, 6, 4, 18, 12, 12, 14, 4, 12, 6,
8, 6, 18, 6, 10, 12, 14, 6, 4, 8, 22, 6, 2, 28, 18, 2, 18, 10, 6, 14,
10, 2, 10, 14, 6, 10, 2, 22, 6, 8, 6, 16, 12, 8, 22, 2, 4, 14, 18, 12,
6, 24, 6, 10, 2, 12, 22, 18, 6, 20, 6, 10, 14, 4, 2, 6, 12, 22, 14, 12,
4, 6, 8, 22, 2, 10, 12, 8, 40, 2, 6, 10, 8, 4, 42, 20, 4, 32, 12, 10,
6, 12, 12, 2, 10, 8, 6, 4, 8, 4, 26, 18, 4, 8, 28, 6, 18, 6, 12, 2,
10, 6, 6, 14, 10, 12, 14, 24, 6, 4, 20, 22, 2, 18, 4, 6, 12, 2, 16, 18,
14, 6, 6, 4, 6, 8, 18, 4, 14, 30, 4, 18, 8, 10, 2, 4, 8, 12, 4, 12,
18, 2, 12, 10, 2, 16, 8, 4, 30, 2, 6, 28, 2, 10, 2, 18, 10, 14, 4, 26,
6, 18, 4, 20, 6, 4, 8, 18, 4, 12, 26, 24, 4, 20, 22, 2, 18, 22, 2, 4,
12, 2, 6, 6, 6, 4, 6, 14, 4, 24, 12, 6, 18, 2, 12, 28, 14, 4, 6, 8,
22, 6, 12, 18, 8, 4, 20, 6, 4, 6, 2, 18, 6, 4, 12, 12, 8, 28, 6, 8,
10, 2, 24, 12, 10, 24, 8, 10, 20, 12, 6, 12, 12, 4, 14, 12, 24, 34, 18, 8,
10, 6, 18, 8, 4, 8, 16, 14, 6, 4, 6, 24, 2, 6, 4, 6, 2, 16, 6, 6,
20, 24, 4, 2, 4, 14, 4, 18, 2, 6, 12, 4, 14, 4, 2, 18, 16, 6, 6, 2,
16, 20, 6, 6, 30, 4, 8, 6, 24, 16, 6, 6, 8, 12, 30, 4, 18, 18, 8, 4,
26, 10, 2, 22, 8, 10, 14, 6, 4, 18, 8, 12, 28, 2, 6, 4, 12, 6, 24, 6,
8, 10, 20, 16, 8, 30, 6, 6, 4, 2, 10, 14, 6, 10, 32, 22, 18, 2, 4, 2,
4, 8, 22, 8, 18, 12, 28, 2, 16, 12, 18, 14, 10, 18, 12, 6, 32, 10, 14, 6,
10, 2, 10, 2, 6, 22, 2, 4, 6, 8, 10, 6, 14, 6, 4, 12, 30, 24, 6, 6,
8, 6, 4, 2, 4, 6, 8, 6, 6, 22, 18, 8, 4, 2, 18, 6, 4, 2, 16, 18,
20, 10, 6, 6, 30, 2, 12, 28, 6, 6, 6, 2, 12, 10, 8, 18, 18, 4, 8, 18,
10, 2, 28, 2, 10, 14, 4, 2, 30, 12, 22, 26, 10, 8, 6, 10, 8, 16, 14, 6,
6, 10, 14, 6, 4, 2, 10, 12, 2, 6, 10, 8, 4, 2, 10, 26, 22, 6, 2, 12,
18, 4, 26, 4, 8, 10, 6, 14, 10, 2, 18, 6, 10, 20, 6, 6, 4, 24, 2, 4,
8, 6, 16, 14, 16, 18, 2, 4, 12, 2, 10, 2, 6, 12, 10, 6, 6, 20, 6, 4,
6, 38, 4, 6, 12, 14, 4, 12, 8, 10, 12, 12, 8, 4, 6, 14, 10, 6, 12, 2,
10, 18, 2, 18, 10, 8, 10, 2, 12, 4, 14, 28, 2, 16, 2, 18, 6, 10, 6, 8,
16, 14, 30, 10, 20, 6, 10, 24, 2, 28, 2, 12, 16, 6, 8, 36, 4, 8, 4, 14,
12, 10, 8, 12, 4, 6, 8, 4, 6, 14, 22, 8, 6, 4, 2, 10, 6, 20, 10, 8,
6, 6, 22, 18, 2, 16, 6, 20, 4, 26, 4, 14, 22, 14, 4, 12, 6, 8, 4, 6,
6, 26, 10, 2, 18, 18, 4, 2, 16, 2, 18, 4, 6, 8, 4, 6, 12, 2, 6, 6,
28, 38, 4, 8, 16, 26, 4, 2, 10, 12, 2, 10, 8, 6, 10, 12, 2, 10, 2, 24,
4, 30, 26, 6, 6, 18, 6, 6, 22, 2, 10, 18, 26, 4, 18, 8, 6, 6, 12, 16,
6, 8, 16, 6, 8, 16, 2, 42, 58, 8, 4, 6, 2, 4, 8, 16, 6, 20, 4, 12,
12, 6, 12, 2, 10, 2, 6, 22, 2, 10, 6, 8, 6, 10, 14, 6, 6, 4, 18, 8,
10, 8, 16, 14, 10, 2, 10, 2, 12, 6, 4, 20, 10, 8, 52, 8, 10, 6, 2, 10,
8, 10, 6, 6, 8, 10, 2, 22, 2, 4, 6, 14, 4, 2, 24, 12, 4, 26, 18, 4,
6, 14, 30, 6, 4, 6, 2, 22, 8, 4, 6, 2, 22, 6, 8, 16, 6, 14, 4, 6,
18, 8, 12, 6, 12, 24, 30, 16, 8, 34, 8, 22, 6, 14, 10, 18, 14, 4, 12, 8,
4, 36, 6, 6, 2, 10, 2, 4, 20, 6, 6, 10, 12, 6, 2, 40, 8, 6, 28, 6,
2, 12, 18, 4, 24, 14, 6, 6, 10, 20, 10, 14, 16, 14, 16, 6, 8, 36, 4, 12,
12, 6, 12, 50, 12, 6, 4, 6, 6, 8, 6, 10, 2, 10, 2, 18, 10, 14, 16, 8,
6, 4, 20, 4, 2, 10, 6, 14, 18, 10, 38, 10, 18, 2, 10, 2, 12, 4, 2, 4,
14, 6, 10, 8, 40, 6, 20, 4, 12, 8, 6, 34, 8, 22, 8, 12, 10, 2, 16, 42,
12, 8, 22, 8, 22, 8, 6, 34, 2, 6, 4, 14, 6, 16, 2, 22, 6, 8, 24, 22,
6, 2, 12, 4, 6, 14, 4, 8, 24, 4, 6, 6, 2, 22, 20, 6, 4, 14, 4, 6,
6, 8, 6, 10, 6, 8, 6, 16, 14, 6, 6, 22, 6, 24, 32, 6, 18, 6, 18, 10,
8, 30, 18, 6, 16, 12, 6, 12, 2, 6, 4, 12, 8, 6, 22, 8, 6, 4, 14, 10,
18, 20, 10, 2, 6, 4, 2, 28, 18, 2, 10, 6, 6, 6, 14, 40, 24, 2, 4, 8,
12, 4, 20, 4, 32, 18, 16, 6, 36, 8, 6, 4, 6, 14, 4, 6, 26, 6, 10, 14,
18, 10, 6, 6, 14, 10, 6, 6, 14, 6, 24, 4, 14, 22, 8, 12, 10, 8, 12, 18,
10, 18, 8, 24, 10, 8, 4, 24, 6, 18, 6, 2, 10, 30, 2, 10, 2, 4, 2, 40,
2, 28, 8, 6, 6, 18, 6, 10, 14, 4, 18, 30, 18, 2, 12, 30, 6, 30, 4, 18,
12, 2, 4, 14, 6, 10, 6, 8, 6, 10, 12, 2, 6, 12, 10, 2, 18, 4, 20, 4,
6, 14, 6, 6, 22, 6, 6, 8, 18, 18, 10, 2, 10, 2, 6, 4, 6, 12, 18, 2,
10, 8, 4, 18, 2, 6, 6, 6, 10, 8, 10, 6, 18, 12, 8, 12, 6, 4, 6, 14,
16, 2, 12, 4, 6, 38, 6, 6, 16, 20, 28, 20, 10, 6, 6, 14, 4, 26, 4, 14,
10, 18, 14, 28, 2, 4, 14, 16, 2, 28, 6, 8, 6, 34, 8, 4, 18, 2, 16, 8,
6, 40, 8, 18, 4, 30, 6, 12, 2, 30, 6, 10, 14, 40, 14, 10, 2, 12, 10, 8,
4, 8, 6, 6, 28, 2, 4, 12, 14, 16, 8, 30, 16, 18, 2, 10, 18, 6, 32, 4,
18, 6, 2, 12, 10, 18, 2, 6, 10, 14, 18, 28, 6, 8, 16, 2, 4, 20, 10, 8,
18, 10, 2, 10, 8, 4, 6, 12, 6, 20, 4, 2, 6, 4, 20, 10, 26, 18, 10, 2,
18, 6, 16, 14, 4, 26, 4, 14, 10, 12, 14, 6, 6, 4, 14, 10, 2, 30, 18, 22, 2 };


///////////////////////////////////////
long modExpFun(long a, int e, long m)//a ���� eָ�� mģ��
{
	// step1: ����ֲ�����
	__int64 p;   //��p����Ϊһ��64λ�������Ա���Խ��нϴ��������㣬���������p���ڼ���p = p*p mod m
	long int tmpbase, r = 0;   // rΪ���,tmpbaseΪ���ױ���
	int k = 0x40000000;         //k��������exponent��ÿ������������

								//��ο�������ʾ���������룬��ɹ���

								// step2: �������ֵ����Ч��
								// case 1 - m,a,e�и���	
	if (a<0 || m<0 || e<0) {
		r = -1;
		return r;
	}
	// case 2 - ģ��Ϊ0,��ʾ�������ģ����Ч 
	if (m == 0) {
		r = -2;
		return r;
	}
	// step3: ����ֵ����
	// case 1 - ģ��Ϊ1
	if (m == 1) {
		r = 0;
		return r;
	}
	// case 2 - ��Ϊ0����ģ����Ϊ0
	if (a == 0 && m != 0) {
		r = 0;
		return r;
	}
	// case 3 - ָ��Ϊ0����������Ϊ0
	if (e == 0 && a != 0) {
		r = 1;
		return r;
	}
	// step4: ���������������y
	r = 1;
	tmpbase = a;
	while (k != 0) {
		r = (r*r) % m;
		if ((e&k) != 0)
			r = (r*tmpbase) % m;
		k >>= 1;
	}
	return r;
}





//
////////////////////////////////////////////////////////////////
long inv(long a, long m)
{
	long remainder, u, g, q, v1, t3, t1;  //��������ľֲ�����
	static  long gcdInvOutArr[2] = { 0,0 };    	//gcdInvOutArr[0]���gcd(a,m), gcdInvOutArr[1]��ų˷���Ԫ

	// case 1 - ������������飬������������Ԫ�����������Լ��
	if (a == 0 || m == 0) 
	{
		gcdInvOutArr[1] = 0;
		gcdInvOutArr[0] = 0;
		return gcdInvOutArr[1];
	}

	// case 2 - a �� m ���������� 

	//ͨ�����������μ�������Լ��remainder����Ԫinverse
	u = 1; g = a; v1 = 0; remainder = m;

	do {
		q = g / remainder;
		t3 = g%remainder;
		if (t3 != 0) {
			t1 = (u - q*v1) % m;
			u = v1;
			v1 = t1;

			g = remainder;    //շת�����
			remainder = t3;
		}
	} while (t3 != 0);

	gcdInvOutArr[0] = remainder;

	if (gcdInvOutArr[0] == 1) {    //������Լ��Ϊ1
		gcdInvOutArr[1] = (v1 + m) % m;       //��v1Ϊ���������m
	}
	else {                            //��������Ԫ������0
		gcdInvOutArr[1] = 0;
	}
	return gcdInvOutArr[1];
}

//�����������
unsigned long FindAPrime(int num)
{
	//�������
	unsigned long n = 0;

	for (int i = 0; i <= num; i++)
	{
		n += smallprimes[i];
	}

	return n; 
} 

// ���ɹ�Կ��˽Կ
void GenKeyPair(unsigned long &publicmod, unsigned long &publickey, unsigned long &privatekey)
{
	//�������
	unsigned long p, q;
	p = FindAPrime(30);
	for (q = p; q == p;) { q = FindAPrime(40); }

	unsigned long n, eular;
	
	n = p*q;
	eular = (p - 1)*(q - 1);

	unsigned long e=2,d;
	int i = 5;
	while(1<e<eular)
	{
		e = FindAPrime(i);
		if (modExpFun(e, 1, eular) > 0) break;
		else {  i++; e = FindAPrime(i); }
	}
	d = inv(e, eular);

	privatekey = d;
	publickey = e;
	publicmod = n;
}

// RSA���ܺ���
void RSAEncrypt(unsigned long publickey,unsigned long publicmod, unsigned long *output, unsigned long input)
{
	//�������
	*output = modExpFun(input, publickey, publicmod);

}

// RSA����
void RSADecrypt(unsigned long privateKey, unsigned long publicmod, unsigned long *output, unsigned long input)
{
	//�������
	*output = modExpFun(input, privateKey, publicmod);
}