#include <stdio.h>

int main(int argc, char* argv[]) {
    system("chcp 1251>nul");
    int a = 10;
    int b = 2;
    int c = Summ(a, b);
    int r = Delenie(a, b);
    int d = Razn(a, b);
    int u = Umn(a, b);
    int ost = Ostatok(a, b);
    int z2 = Swap(0, b);

    printf("%d + %d = %d\n", a, b, c);
    printf("%d : %d = %d\n", a, b, r);
    printf("%d - %d = %d\n", a, b, d);
    printf("%d * %d = %d\n", a, b, u);
    printf("%d : %d остаток = %d\n", a, b, ost);
    printf("%d %d = %d\n", a, b, z2);

    
    return 0;
}

int Summ(int a, int b)
{
    int c;

    __asm{
        mov    eax, a
        mov    ebx, b
        add    eax, ebx
        mov    c, eax
    }
    return c;
}

int Delenie(int a, int b)
{
    int r;

    __asm {
        mov    eax, a
        mov    ebx, b
        xor edx, edx;
        div ebx;
        mov r, eax;
    }
    return r;
}

int Razn(int a, int b)
{
    int d;

    __asm
    {
        mov eax, a
        mov ebx, b
        sub eax, ebx
        mov d, eax
    }
    return d;
}

int Umn(int a, int b)
{
    int u;

    __asm
    {
        mov eax, a
        mov ebx, b
        imul eax, ebx
        mov u, eax
    }
    return u;
}

int Ostatok(int a, int b)
{
    int ost;

    __asm {
        mov    eax, a
        mov    ebx, b
        xor edx, edx;
        div ebx;
        mov ost, edx;
    }
    return ost;
}

int Swap(int a, int b)
{
    int z1;
    int z2;

    __asm
    {
        mov eax, a
        mov ebx, b
        bswap eax
        mov z2, eax
    }
    return z2;
}