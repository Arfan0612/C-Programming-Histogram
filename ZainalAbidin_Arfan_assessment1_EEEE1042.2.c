#include<stdio.h>
#include<math.h>

//function declaration
void getfile(char *filename);
void vertical(int label[],int listing[]);

int main(){
  FILE *f;//FILE pointer
  char filename[50];//to store filename from user
  double num1;
  double num2;
  int i=0;//to determine array position
  int listing[7];//store label
  int label[7];//store quantity
  
  
  getfile(filename);//to call function to get user input

  if((f=fopen(filename,"r"))!=NULL){//open txt file in read mode
    
    while(fscanf(f,"%lf %lf",&num1,&num2)!=EOF){//to read until end of file
      
      label[i]=(int)num1;//to store value of 1st colomn
      listing[i]=ceil(num2);//to store value of 2nd colomn
      i++;
      
    }
    vertical(label,listing);//calling function

    fclose(f);//to close file 
  }
  
  else printf("sorry but file does not exist");//if file cannot be find 
  
  return 0;
}

void getfile(char *filename){
  
  printf("Enter filename: ");
  scanf("%s",filename);//get input filename from user
  
}

void vertical(int label[],int listing[]){
  int maxi;//to store max value from the listing[]
  
  maxi = listing[0];//set reference to compare with

  //to find max number in the list 
  for(int j=0;j<7;j++){
    if (maxi<listing[j]){//to see if the number is larger than the one before
      maxi=listing[j];
    }
  }
  
  //print vertical histogram
  for(int j=maxi;j>0;j-- ){
    
    for(int k=0 ; k<7 ; k++){
      
      //print * only if the value is larger than current value of k
      if(listing[k]>=j){ 
	printf("*");
      }
      else printf(" ");
      printf(" ");//to have space between histogram
	
    }
    printf("\n");
      
  }
  
  //to print the labelling
  for(int j=0;j<7;j++){ 
    printf("%d",label[j]);
    printf(" ");
  }
  printf("\n");
  
}
