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
//    float (*fun)(float*,float*);
    char str[100];
  }mass[100];
  void* bibl[100];
  int i=0,w=0;
  while((q = readdir(fd)) != NULL){
    if((strcmp(q->d_name,".")!=0)&&(strcmp(q->d_name,"..")!=0)){
      printf("%d) %s\n",i,q->d_name);
      sprintf(mass[i].str,"%s",q->d_name);
      i++;
    }
  }
  float a,b,rez;
  int op;
  printf("%d) exit\n",i);
  while(1){
    printf("\n? a b\n");
    scanf("%d",&op);
    if(op==i) break;
    scanf("%f %f",&a,&b);
    char path[100];
    sprintf(path,"./plugin1/%s",mass[op].str);
    void* fd1=dlopen(path,RTLD_NOW);
    float (*func)(float*,float*)=dlsym(fd1,(char*)mass[i].str);
    printf("\n = %f\n",func(&a,&b));
    fflush(stdout);
    dlclose(fd1);
  }
  closedir(fd);
  return 0;
}
