// 2D Complex Number ADT
#ifndef __COMPLEX2_H__
#define __COMPLEX2_H__
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358

typedef struct complex2_ complex2;

struct complex2_ {
    double a; // real
    double b; // imaginary
};

//FUNCTIONS PROTOTYPES
complex2 Cx2Create(double real,double imag);
double Cx2Arg(const complex2 cx); // theta
double Cx2Mod(complex2 cx); // |cx|
void Cx2Print(const complex2 cx); // print the complex number

complex2 Cx2Add(const complex2 c1,const complex2 c2); // complex addition
complex2 Cx2Mul(const complex2 c1,const complex2 c2); // complex multiplication
complex2 Cx2Inv(const complex2 cx); // complex reciprocal 
complex2 Cx2Conj(const complex2 cx); // complex conjugate

// FUNCTIONS DECLARATION
complex2 Cx2Create(double real, double imag)
{
    printf("Enter complex number(if number is a+ib then enter a and b): ");
    scanf("%lf %lf",&real, &imag);
    complex2 z ;
    z.a = real;
    z.b = imag;
    return z;
}

double Cx2Arg(const complex2 cx)
{
    if(cx.a > 0 && cx.b > 0) // 1st quadrant
    return (atan(cx.a/cx.b));

    if(cx.a < 0 && cx.b > 0) // 2nd quadrant
    return PI - (atan(-1*cx.a/cx.b));

    if(cx.a < 0 && cx.b < 0) // 3rd quadrant
    return -1*PI + (atan(cx.a/cx.b));

    if(cx.a > 0 && cx.b < 0) // 4th quadrant
    return -1*(atan(-1*cx.a/cx.b));

    if(cx.a == 0 && cx.b > 0) //positive y axis
    return PI/2;

    if(cx.a == 0 && cx.b < 0) // negative y axis
    return -1*PI / 2;

    if(cx.a > 0 && cx.b ==0) // positive x axis
    return 0;

    if(cx.a < 0 && cx.b == 0) // negative x axis
    return PI;
    
}
double Cx2Mod(complex2 cx)
{
    double x;
    x = sqrt(cx.a*cx.a + cx.b*cx.b);
    // x = sqrt(x);
    return x;
}

void Cx2Print(const complex2 cx)
{
    printf("%lf+i%lf",cx.a, cx.b);
}
complex2 Cx2Add(const complex2 c1, const complex2 c2)
{
    complex2 c3;
    c3.a = c1.a + c2.a;
    c3.b = c1.b + c2.b;

return c3;
}

complex2 Cx2Mul(const complex2 c1,const complex2 c2)
{
    complex2 c;
    c.a = c1.a*c2.a - c1.b*c2.b;
    c.b = c1.a*c2.b + c2.a*c1.b;
    return c;
}

complex2 Cx2Inv(const complex2 cx)
{
    complex2 c;
    c.a = cx.a/(cx.a*cx.a + cx.b*cx.b);
    c.b = (-1*cx.b)/(cx.a*cx.a + cx.b*cx.b);
    return c;
}

complex2 Cx2Conj(const complex2 cx)
{
    complex2 c;
    c.a = cx.a;
    c.b = -1*cx.b;
    return c;    
}
#endif