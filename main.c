#include <stdio.h>
#include <dlfcn.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  DIR *fd=opendir("./plugin1/");
  struct dirent *q;
  struct name{
    float (*fun)(float*,float*);
  }mass[100];
  void* bibl[100];
  int i=0,w=0;
  while((q = readdir(fd)) != NULL){
    if((strcmp(q->d_name,".")!=0)&&(strcmp(q->d_name,"..")!=0)){
      printf("%d) %s\n",i,q->d_name);
      bibl[i]=dlopen(q->d_name,RTLD_NOW);
      mass[i].fun = dlsym(bibl[i],q->d_name);
      i++;
    }
  }
  printf(" 11111111");
  float a,b,rez;
  char zn;
  printf("!!!!!!!!!   %f   !!!!!!!!!",mass[0].fun(5,6));
 // scanf("%f %c %f",&a,&zn,&b);
 // if(zn=='+') rez=add(&a,&b);
 // else if(zn=='-') {zn='+'; b=-b;rez=add(&a,&b);}
 // else if(zn=='/') rez=sub(&a,&b);
 // else if(zn=='*') rez=mul(&a,&b);
  //printf("\n%f %c %f = %f\n",a,zn,b,rez);
  i--;
  while(i>=0) dlclose(bibl[i]),i--;
  closedir(fd);
  return 0;
}
