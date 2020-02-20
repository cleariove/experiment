#include<stdio.h>
#include<math.h>
void main()
{
	float a,b;
	scanf("%f",&a);
	int c,d,e,f,g;
	b=(int)log10(a)+1;
	c=(int)a/10000;
	d=(int)a/1000-10*c;
	e=(int)a/100-100*c-10*d;
	f=(int)a/10-1000*c-100*d-10*e;
	g=(int)a-10000*c-1000*d-100*e-10*f;
	if(a<100000&&a>=0)
	{
     printf("位数为%0.0f\n",b);
	 if (c>0)
		 {printf("%d%d%d%d%d\n",c,d,e,f,g);
	 printf("%d%d%d%d%d\n",g,f,e,d,c);}
	 if(c==0&&d>0)
		 {printf("%d%d%d%d\n",d,e,f,g);
	 printf("%d%d%d%d\n",g,f,e,d);}
	 if(c==0&&d==0&&e>0)
		 {printf("%d%d%d\n",e,f,g);
	 printf("%d%d%d\n",g,f,e);}
	 if(c==0&&d==0&&e==0&&f>0)
		{ printf("%d%d\n",f,g);
	 printf("%d%d\n",g,f);}
	 if(c==0&&d==0&&e==0&&f==0&&g>0)
		{ printf("%d\n",g);
	 printf("%d\n",g);}
	}
	else printf("数据错误\n");
} 