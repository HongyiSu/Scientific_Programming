#include  <stdio.h>
#include <stdbool.h>
int main()
{
  //bool  mjhnsn=true, fjhnsn=true, tim=true, sarah=true, jack=true;
  //not sure how bool works with the loops...
  for(int mjhnsn=0;mjhnsn<2;mjhnsn++)
    {
      for(int fjhnsn=0;fjhnsn<2;fjhnsn++)
      {
       for(int tim=0;tim<2;tim++)
	 {
	   for(int sarah=0;sarah<2;sarah++)
	   {
	     for(int jack=0;jack<2;jack++)
	      {
		if((!mjhnsn||fjhnsn) && (jack||sarah) && (fjhnsn!=tim) && (tim==sarah)&&(!jack||(sarah && mjhnsn)))
		  {
			 printf("%d,%d,%d,%d,%d\n", mjhnsn,fjhnsn,tim,sarah,jack);
			 if(mjhnsn ==1)
			   {
			     printf("Mr. Johnson comes\n");
			   }
			  if(fjhnsn ==1)
			   {
			     printf("Mrs. Johnson comes\n");
			   }
			  if(tim ==1)
			   {
			     printf("Timothy comes\n");
			   }
			   if(sarah ==1)
			   {
			     printf("Sarah comes\n");
			   }
			    if(jack ==1)
			   {
			     printf("Jack comes\n");
			   }
			 break;
		  }
	      }
	   }
	 }
      }
    }



}
