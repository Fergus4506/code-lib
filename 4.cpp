#define EQD(x, y) ((x) - (y) ? (x) - (y) : (x))
int main()
{
    int m = 3, n = 7;
    int *p, *q = &m;
    int a[5] = {m, n, m + n};
    //(a) 
    p = a;
    q = a + 3;
    //(b) 
    *p = *p + 2;
    *q = *p;
    //(c) 
    n = *q;
    m = *q * *p + 2;
    //(d) 
    p++;
    //(e) 
    m = EQD(*p, *q);
    //(f) 
    *p = EQD(1, 1 + 1);
}