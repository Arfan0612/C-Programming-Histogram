#include<stdio.h>
#include<math.h>

//function declaration
void getfile(char *filename);
void horizontal(int x, double num1, double num2);


int main(){
  FILE *f;//FILE pointer
  char filename[50];//to store filename from user
  double num1;
  double num2;
  int x;//store quantity 
  
  getfile(filename);//to call function to get user input
  
  if((f=fopen(filename,"r"))!=NULL){//open txt file in read mode
    
    while(fscanf(f,"%lf %lf",&num1,&num2)!=EOF){//to read until end of file
      x=ceil(num2*2);//quantity of (*)
      horizontal(x,num1,num2);//calling function
      printf("\n");
    }

    fclose(f);//to close file 
  }
  else printf("sorry but file does not exist");//if file cannot be find 
  
  
  
  return 0;
}

void getfile(char *filename){
  printf("Enter filename: ");
  scanf("%s",filename);//get input filename from user
  
}

void horizontal(int x, double num1, double num2){//horizontal histogram
  printf("%.1f/%.2f ",num1,num2);//the label
  for(int i=0;i<x;i++){//to print asterisk
	printf("*");
  }
}
