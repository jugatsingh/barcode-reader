#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <cv.h>
#include <iostream>
#include <fstream>
#include <cstring>

 #include <QApplication>
 #include <QDialog>
 #include <QLabel>
 #include "ui_design.h"
 #include "ui_design2.h"

#define isBlack <100
#define isWhite >200

using namespace cv;
using namespace std;
class product
{
  public:
  char name[100];
  float price;
  char product_code[13];
  void display(){
   
    cout<<name<<endl;
    cout<<price<<endl;
  }
};

int main( int argc,char** argv )
{
	QApplication program(argc,argv);
  QDialog dialog;
  ui_design interface;
  interface.setupUi(&dialog);
  dialog.show();
  program.exec();
  string command_name=(interface.input).toStdString();
  
  ifstream f1;
  // int bill=0;
	f1.open("data.txt");
      

     Mat img = imread(command_name,0); //read the image data in the file "MyPic.JPG" and store it in 'img'

     if (img.empty()) //check whether the image is loaded or not
     {
     	cout << "Error : Image cannot be loaded..!!" << endl;
           //wait for a key press
          return -1;
      }


      int a=img.rows;
      int b=img.cols;
      
      int **arr=new int*[a];
      for(int i=0;i<a;i++)
      	arr[i]=new int[b];
      
      for (int i=0;i<img.rows;i++)
      {
      	for (int j=0;j<img.cols;j++)
      	{
      		arr[i][j]=img.at<uchar>(i,j);
      	}
      }
           
          f1.close();

          int mid=img.rows/2;
          int i=0;
          mid-=20;
          while(arr[mid][i] isWhite)
          {
          	i++;
          }

          int mod_size=0;

          while(arr[mid][i] isBlack)
          {
          	i++;
          	mod_size++;
          }
          i-=mod_size;

          int prev=255;
          int width=0;

          int bin_code[95];
          int index=0;
          for(;i<img.cols;i++)
          {
          	
          	if((arr[mid][i] isWhite && prev isBlack) || (arr[mid][i] isBlack && prev isWhite) || width>mod_size)
          	{
          		if(arr[mid][i] isWhite)
          			bin_code[index++]=0;
          		else
          			bin_code[index++]=1;

          		width=0;
          	}      
          	prev=arr[mid][i];
          	width++;
          }
            
       	const char* sequence[]={"000000","001011","001101","001110","010011","011001","011100","010101","010110","011010"};
       	const char* table0[]={"0001101","0011001","0010011","0111101","0100011","0110001","0101111","0111011","0110111","0001011"};
       	const char* table1[]={"0100111","0110011","0011011","0100001","0011101","0111001","0000101","0010001","0001001","0010111"};
       	const char* table2[]={"1110010","1100110","1101100","1000010","1011100","1001110","1010000","1000100","1001000","1110100"};
       	char parity[6];
       	char compare[7];
       	char prod_code[13];

       	for (int i = 1,m = 0,k = 3,y=1; i < 7; ++i)
       	{
       		int ctr=0;
       		for (int j = 0; j < 7; ++j,++k)
       		{
       			compare[j]=bin_code[k]+48;

       		}

       		for (int  l= 0; l < 7; ++l)
       		{
       			if (compare[l]=='1')
       			{
       				ctr++;
       			}
       		}

       		if (ctr%2==0)
       		{
       			parity[m++]='1'; 
       			for (int x = 0; x < 9; ++x)
       			{
       				if(strcmp(compare,table1[x])==0)
       				{
       					prod_code[y++] = x+48;
       					break;
       				}
       			}
       		}
       		else
       		{
       			parity[m++]='0';
       			for (int x = 0; x < 9; ++x)
       			{
       				if(strcmp(compare,table0[x])==0)
       				{
       					prod_code[y++] = x+48;
       					break;
       				}
       			}

       		}

       	}

       	for (int i = 0; i < 10; ++i)
       	{
       		if (strcmp(parity,sequence[i])==0)
       		{
       			prod_code[0]=i
       			+48;
       			break;
       		}
       	}

       	for (int i = 50, k = 7; i < 92;)
       	{
       		for (int j = 0; j < 7; ++j)
       		{
       			compare[j]=bin_code[i++]+48;
       		}
       		
       		for (int l = 0; l < 10; ++l)
       		{
       			if (strcmp(compare,table2[l])==0)
       			{		
       				prod_code[k++] =l+48;
       				break;
       			}
       		}
         

       	}
            
            
        QApplication program2(argc,argv);
        QWidget result;
        ui_design2 interface2;
        interface2.setupUi(&result);
        interface2.textBrowser->setText(prod_code);
        result.show();
        program2.exec();

         
       	return 0;
       }

