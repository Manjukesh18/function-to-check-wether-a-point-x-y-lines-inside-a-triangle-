#include<stdio.h>
#include<math.h>
void res(float,float,float,float,float,float,float,float,float*,int*);
float dist(float,float,float,float);
float cal_area(float , float , float );
int pos(float,float,float,float);
int main()
{
    float x1,y1,x2,y2,x3,y3,x,y;
    float area=0;
    int flag =0;
    float a,b,c,d,e,f;


    printf("Enter x1,y1:\n"); //gets x1,y1 value
    scanf("%f %f",&x1,&y1);

    printf("Enter x2,y2:\n"); //x2,y2 value
    scanf("%f %f",&x2,&y2);

    printf("Enter x3,y3:\n"); //x3,y3 value
    scanf("%f %f",&x3,&y3);

    printf("Enter x,y:\n");   //x,y value
    scanf("%f %f",&x,&y);

    res(x1,y1,x2,y2,x3,y3,x,y,&area,&flag); //res,calling a single function that has all other functions for dist,area

    printf("Area pf triangle is :\n",area);

    if(flag==1)
    {
        printf("point %f,%f lies inside the triangle",x,y); //returned value

    }
    else
    {
        printf("Point %f ,%f lies outside the triangle",x,y);
    }


    return 0;
}
void res(float x1,float y1,float x2,float y2,float x3,float y3,float x, float y,float*area,int*flag) //res,called.
{
    printf("hi");
    float a,b,c,d,e,f,A,B,C;
    a = dist(x1,y1,x2,y2);  // calling a dist function to find distance btw x1 and x2
    b = dist(x2,y2,x3,y3); // calling again to find distance btw x2 and x3
    c = dist(x3,y3,x1,y1); // calling again to find distance btw  x3 and x1

    *area = cal_area(a,b,c); // calls a function cal_area to find the outer area of the triangle

    d = dist(x1,y1,x,y); // calls a function to calc distance bte x1 and x
    e = dist(x2,y2,x,y); //calls again
    f = dist(x3,y3,x,y); // calls again


    /* Now there's a point connecting all corners. Such that three inner triangles are formed.So, Calculating the area of
    the respective triangles*/

    A = cal_area(d,e,a);
    B = cal_area(e,b,f);
    C = cal_area(f,c,d);

    *flag=pos(*area,A,B,C); // This function calls to check the position of the point
}
float dist(float x1,float y1,float x2, float y2)
{
return (sqrt(pow((x2-x1),2)+pow((y2-y1),2))); // one function calculates distances for all sides
}
float cal_area(float a,float b,float c)
{
    float S,ar;
    S = (a+b+c)/2.0;

    ar = (sqrt(S*(S-a)*(S-b)*(S-c)));
    return (ar);                              // one function calculates area for all triangles
}
int pos(float area,float A,float B,float C)
{
    float res;
    res=area-(A+B+C);

    if(res==0 || res<0.0001)   // if value is less than 0 then it lies inside the triangle
    {
        return (1);  // returns the flag to the calling func(main func)
    }
    else
    {
        return (0);
    }
}

