/*
FCAI - Programing 1 - 2022 - Assignment 3
Program Name : Photoshop 
Program Description : Apply filters on images RGB
 Author1: Ahmed Mohamed Hany 20210038
 Author2: ahmed Alaa Mohamed 20210027
 Author3: Omnia Magdy abdelnaby 20211018
 Date: 21-4-2022
 Version: 1.0
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char imgRGB[SIZE][SIZE][3];

void loadRGBImage();
void saveRGBImage();

void filter1(); //Black and white
void filter2(); //Invert filter
void filter3(); //Merge filter
void filter4(); //Flip Filter
void filter5(); //Rotate Filter
void filter6(); //Darken and Lighten
void filter7(); //Detect image Filter
void filter8(); //Enlarge image Filter
void filter9(); //shrink image Filter
void filtera(); //Mirror 1/2 Image filter
void filterb(); //shuffle image filter
void filterc(); //Blur Filter


int main()
{
    char userinput;
    bool runner = true;
    cout << "Ahlan ya user ya habiby\n";
    loadRGBImage(); //call load image function
    while (runner)
    {
        //choices of filters to apply
        cout << "Please select a filter to apply or 0 to exit:\n1-Black & White Filter\n2-Invert Filter\n"
             << "3-Merge Filter\n4-Flip Filter\n5-Rotate Image\n6-Darken and Lighten Image\n7-Detect Image Edges\n8-Enlarge Image\n"
             <<"9-Shrink Image\na-Mirror 1/2 IMage\nb-Shuffle Image\nc-Blur Image\ns-Save the image to a file\n0-Exit\n";
        cout << "Your Choice : ";
        cin >> userinput; // take from user his choice
        switch (userinput) //switch statment for the choice
        {
        case '1':
            filter1(); //call filter 1 function
            cout << "_________________Black & White Done____________________\n\n";
            break;
        case '2':
            filter2(); //call filter 2 function
            cout << "_________________Invert Done____________________\n\n";
            break;
        case '3':
            filter3(); //call filter 3 function
            cout << "_________________Merge Done____________________\n\n";
            break;
        case '4':
            filter4(); //call filter 4 function
            cout << "_________________Flip Done____________________\n\n";
            break;
        case '5':
            filter5(); //call filter 5 function
            cout << "_________________Rotate Done____________________\n\n";
            break;
        case '6':
            filter6(); //call filter 6 function
            cout << "_________________Darken and Lighten Done____________________\n\n";
            break;
        case '7':
            filter7(); //call filter 7 function
            cout << "_________________Detect Image Edge Done____________________\n\n";
            break;
        case '8':
            filter8(); //call filter 8 function
            cout << "_________________Enlarge Done____________________\n\n";
            break;
        case '9':
            filter9(); //call filter 9 function
            cout << "_________________Shrink Done____________________\n\n";
            break;
        case 'a':
            filtera(); //call filter a function
            cout << "_________________Mirror Done____________________\n\n";
            break;
        case 'b':
            filterb(); //call filter b function
            cout << "_________________shuffle Done____________________\n\n";
            break;
        case 'c':
            filterc(); //call filter c function
            cout << "_________________Blur Done____________________\n\n";
            break;
        case 's':
            saveRGBImage(); //call save image function
            cout << "_________________Saving File Done____________________\n\n";
            break;
        case '0':
            cout << "Thanks for using our Photoshop\n";
            runner = false; //stop the program runner
            break;

        default:
            cout<<"wrong input Please enter a vaild choice\n";
            break;
        }
    }

    return 0;
}



void loadRGBImage () { // function for loading image
   char imageFileName[100];
   cout << "Enter the source image file name: ";
   cin >> imageFileName; //take input from user
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, imgRGB); //call function readRGBBMP to read file
}

void saveRGBImage () { //function for loading image
   char imageFileName[100];
   cout << "Enter the target image file name: ";
   cin >> imageFileName; //take input from user
   strcat (imageFileName, ".bmp"); 
   writeRGBBMP(imageFileName, imgRGB); //call function writeRGBBMP to write file
}


void filter1(){ //Black and white
    int avg=0,sum=0;
  for(int i=0; i < SIZE; i++){
    for(int j=0; j < SIZE; j++){

        avg += ((imgRGB[i][j][0]+imgRGB[i][j][1]+imgRGB[i][j][2])/3); //Add the size of each pixel color to the avg to get avg
    }
  }
  avg = avg/(SIZE*SIZE); //avg 
  for(int i=0; i < SIZE; i++){
    for(int j=0; j < SIZE; j++){
      for(int k=0; k < RGB; k++){
        sum += imgRGB[i][j][k]; //get sum of the one pixel colors
      }
      sum =sum /3; //get avg by divided by 3
      if (sum < avg) 
      {
        imgRGB[i][j][0] = 0; //set to 0
        imgRGB[i][j][1] = 0;
        imgRGB[i][j][2] = 0;
      }else{
        imgRGB[i][j][0] = 255;
        imgRGB[i][j][1] = 255; //set to 255
        imgRGB[i][j][2] = 255;

      }
      sum=0;

    }
  }
}

void filter2(){ //invert
    for(int i=0; i < SIZE; i++){
    for(int j=0; j < SIZE; j++){
      for(int k=0; k < RGB; k++){
        // get every color of the pixel in the image and subtract it from 255
        imgRGB[i][j][k]= 255 - imgRGB[i][j][k]; 
      }

    }
  }
}

void filter3(){
    unsigned char image2[SIZE][SIZE][3];
    char imageFileName [100];
    cout<<"enter the image 2 file name : ";
    cin >> imageFileName; //get the file name from user
    strcat (imageFileName , ".bmp");
    readRGBBMP(imageFileName, image2); //to load the image

    for (int i = 0; i < SIZE; i++) { //row
        for (int j = 0; j< SIZE; j++) { //columns
            for (int k = 0; k < 3; k++)
            {
                int average = 0;
                average = (imgRGB[i][j][k] + image2[i][j][k])/2;  //get the average color by get the sum of two pictures pixel color and dividing by 2
                imgRGB[i][j][k]= average;                       // set the new value to image pixel
            }
        }
    }
}


void filter4(){
    int x =0;
   char input;//to choosen between Flip (h)orizontally or (v)ertically

   cout<<"Flip (h)orizontally or (v)ertically : ";
   cin>>input;

   if (input == 'v')
   {
    for(int i=0; i < SIZE; i++)
    {
     for(int j=0; j < SIZE/2; j++)
     {
         for (int k = 0; k < 3; k++)
         {
         
        // to Swap the first pixel with last pixel in the coulmn
            x = imgRGB[i][j][k];
            imgRGB[i][j][k]=imgRGB[i][SIZE-1-j][k];
            imgRGB[i][SIZE-1-j][k]= x;
         }

      }
    }
   }

   else if(input == 'h')
   {

   for(int i=0; i < SIZE/2; i++)
   {
     for(int j=0; j < SIZE; j++)
     {
         for (int k = 0; k < 3; k++)
         {
          
   // to Swap the first pixel with last pixel in the coulmn 
            x = imgRGB[i][j][k];
            imgRGB[i][j][k]=imgRGB[SIZE-1-i][j][k];
            imgRGB[SIZE-1-i][j][k]= x;
         }
      }
    }
   }
   
   else //to avoid error
   {
     cout<<"unvalid input!";
   }
}

void filter5(){
    int tmp, deg; //declear variables tmp and deg
    cout << "Please Choose Rotation Degree:\n1-90 degree\n2-180 degree\n3-270 degree\nyour choice: ";
    cin >> deg; //take from user what the degree he want to rotate
    for (int i = 0; i < deg; i++)
    {

        for (int i = 0; i < SIZE / 2; i++) //rows till half
        {
            for (int j = i; j < SIZE - i - 1; j++) //subtract rows from 255
            {
              for (int k = 0; k < 3; k++)
              {
                tmp = imgRGB[i][j][k]; //save the value of image 
                imgRGB[i][j][k] = imgRGB[SIZE - j - 1][i][k]; //get top left side pixel equal bottom left side pixel
                imgRGB[SIZE - j - 1][i][k] = imgRGB[SIZE - i - 1][SIZE - j - 1][k];//get bottom left side pixel equal bottom right side pixel
                imgRGB[SIZE - i - 1][SIZE - j - 1][k] = imgRGB[j][SIZE - i - 1][k];//get bottom right side equal top right side pixel
                imgRGB[j][SIZE - i - 1][k] = tmp;//get right side pixel equal top left side pixel that we save it at tmp
              }
            }
        }
    }
}

//darken
void darken()
{
  for (int i =0 ; i < SIZE ; i++){
    for ( int j = 0 ; j < SIZE ; j++){
        for (int k = 0; k < 3; k++)
        {  
            imgRGB[i][j][k]= imgRGB[i][j][k]/2;  //dividing each pixel color (image[i][j]) by 2
        }
    }
  }
}


// lighten
void lighten()
{
   for (int i =0 ; i < SIZE ; i++){
    for ( int j = 0 ; j < SIZE ; j++){
      int light ;
      for (int k = 0; k < 3; k++)
      {
      
      light = imgRGB[i][j][k] + (imgRGB[i][j][k]/2); //get 50% of pixel color (image[i][j]/2) + the original pixel color
      if ( light > 255)  //compare it with 255 incase light bigger than 255
      {
        imgRGB[i][j][k] = 255; //then set the color to 255
      }
      else 
      {
        imgRGB[i][j][k] = light ;
      }
      }
    }
  }
}

void filter6(){
    int choice ;
    cout<<"do you want to "<<endl<<" 1-darken" <<endl<<" 2-lighten"<<endl;
    cin>>choice;  //to choosen between darker(1) or lighter (2)

    if (choice == 1) 
    {
     darken();
    }
    else if (choice == 2)
    {
     lighten();
    }
    else  {
    cout<<"try again ";
    }
}

void filter7(){
  // nested loops for rows and columns
   for (int i = 0; i < SIZE; i++)
   {
    for (int j = 0; j < SIZE; j++)
    {
            // check if the pixel's value1 - pixel's value2 is bigger than 25 in columns
      // or if the pixel's value1 - pixel's value2 is bigger than 25 in rows
      if (abs(imgRGB[i][j+1][0]-imgRGB[i][j][0])>25 || abs(imgRGB[i+1][j][0]-imgRGB[i][j][0])>25){
        imgRGB[i][j][0]=0; //if true make it black to detect edge 
        imgRGB[i][j][1]=0;
        imgRGB[i][j][2]=0;
      }
      else{
       imgRGB[i][j][0]=255;// else make it false to detect wallpaper and anything else edges
       imgRGB[i][j][1]=255;
       imgRGB[i][j][2]=255;
      }
   }
   }
}


//----------------------------
unsigned char img2[SIZE][SIZE][3] ;//declear new imagr aaray
int x=0,y=0;

void copyRGBimage(unsigned char img2[SIZE][SIZE][3]){ //function to take a copy from the origianl image
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
        for (int k = 0; k < 3; k++)
        {
        
            img2[i][j][k]=imgRGB[i][j][k];
        }
        
        }

    }
}

void enlargeFirstQ(){// function for enlarge first Quarter
    for (int i = 0; i < SIZE/2; i++) {
      for (int j = 0; j< SIZE/2; j++) {
        for (int k = 0; k < 3; k++)
        {
        imgRGB[x][y][k] = img2[i][j][k];//take first pixel and assign it to first pixel in image
        imgRGB[x][y+1][k]= img2[i][j][k];//take second on right pixel and assign it to  second on right pixel in image
        imgRGB[x+1][y+1][k]= img2[i][j][k];//take last pixel and assign it to last pixel in image
        imgRGB[x+1][y][k]= img2[i][j][k];//take dwon pixel and assign it to dawon pixel in image
        }
        y+=2;
      }
      x+=2;
      y=0;
    }
}

void enlargeSecondQ(){// function for enlarge second Quarter
   for (int i = 0; i < SIZE/2; i++) {
      for (int j = (SIZE/2); j< SIZE; j++) {
         for (int k = 0; k < 3; k++)
        {
        imgRGB[x][y][k] = img2[i][j][k];//take first pixel and assign it to first pixel in image
        imgRGB[x][y+1][k]= img2[i][j][k];//take second on right pixel and assign it to  second on right pixel in image
        imgRGB[x+1][y+1][k]= img2[i][j][k];//take last pixel and assign it to last pixel in image
        imgRGB[x+1][y][k]= img2[i][j][k];//take dwon pixel and assign it to dawon pixel in image
        }
        y+=2;
      
      }
      x+=2;
      y=0;
    }
}

void enlargeThirdQ(){// function for enlarge third Quarter
   for (int i = (SIZE/2); i < SIZE; i++) {
      for (int j = 0; j< SIZE/2; j++) {
        for (int k = 0; k < 3; k++)
        {
        imgRGB[x][y][k] = img2[i][j][k];//take first pixel and assign it to first pixel in image
        imgRGB[x][y+1][k]= img2[i][j][k]; //take second on right pixel and assign it to  second on right pixel in image
        imgRGB[x+1][y+1][k]= img2[i][j][k];//take last pixel and assign it to last pixel in image
        imgRGB[x+1][y][k]= img2[i][j][k];//take dwon pixel and assign it to dawon pixel in image
        }
        y+=2;
      }
      x+=2;
      y=0;
    }
}

void enlargefouthQ(){// function for enlarge fourth Quarter
  for (int i = (SIZE/2); i < SIZE; i++) {
      for (int j = (SIZE/2); j< SIZE; j++) {
         for (int k = 0; k < 3; k++)
        {
        imgRGB[x][y][k] = img2[i][j][k];//take first pixel and assign it to first pixel in image
        imgRGB[x][y+1][k]= img2[i][j][k];//take second on right pixel and assign it to  second on right pixel in image
        imgRGB[x+1][y+1][k]= img2[i][j][k];//take last pixel and assign it to last pixel in image
        imgRGB[x+1][y][k]= img2[i][j][k];//take dwon pixel and assign it to dawon pixel in image
        }
        y+=2;
      }
      x+=2;
      y=0;
    }
}


void filter8(){
    int choice;
  
  copyRGBimage(img2);

  cout<<"choose which quarter you want to enlarge 1 , 2 , 3 or 4  : ";
  cin>>choice;//take user input
  if (choice == 1)
  {
   enlargeFirstQ();
  }else if (choice == 2){
    enlargeSecondQ();
  }else if (choice == 3)
  {
    enlargeThirdQ();
  }else if (choice == 4)
  {
    enlargefouthQ();
  }else{
    cout<<"unvalid quarter number, Try again!\n";
  }
}

//---------------------

unsigned char shrinkimage[SIZE][SIZE][RGB]; //declear new image aaray
void copyOfImage(unsigned char shrinkimage[SIZE][SIZE][RGB]) //function to take a copy from the origianl image
{
    for (int i = 0 ;i < SIZE ; i++) // nested loops for rows and columns
    {
        for ( int j = 0 ; j < SIZE ; j++)
        {
          for (int k = 0; k < 3; k++)
          {
            imgRGB[i][j][k]= shrinkimage[i][j][k];
          }
        }
    }
}


void shrink4() //function to shrink the image to 1/4
{
    for (int i = 0 ; i < SIZE ; i++){
        for (int j = 0 ; j < SIZE ; j++){
          for (int k = 0; k < 3; k++)
          {
            shrinkimage[i/4][j/4][k] = imgRGB[i][j][k];
          }
        }
    }

}

void shrink2() //function to shrink the image to 1/2
{
    for (int i = 0 ; i < SIZE ; i++){
        for (int j = 0 ; j < SIZE ; j++){
            for (int k = 0; k <3; k++)
          {
            shrinkimage[i/2][j/2][k] = imgRGB[i][j][k];
          }
        }
    }

}

void shrink3() //function to shrink the image to 1/3
{
    for (int i = 0 ; i < SIZE ; i++){
        for (int j = 0 ; j < SIZE ; j++){
            for (int k = 0; k < 3; k++)
          {
            shrinkimage[i/3][j/3][k] = imgRGB[i][j][k];
          }
        }
    }

}

void filter9(){
  int shrink;
  cout<<"do you want to shrink the image to :" <<endl<<"1-shrink 1/2"<<endl<<"2-shrink 1/3"<< endl<<"3-shrink 1/4"<<endl;
  cin>>shrink;
  if (shrink == 1){
      shrink2();
  }
  else if (shrink == 2){
      shrink3();
  }
  else if (shrink == 3){
      shrink4();
  }
  else {
          cout<<"try again";
  }
  copyOfImage(shrinkimage);
}


// functions to mirror the user will choose one of them

void mirror_left(){
  // nested loops for row and columns 
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE/2; j++)
    {
      for (int k = 0; k < 3; k++)
        {
      
      imgRGB[i][SIZE -j-1][k] = imgRGB[i][j][k];//make every pixel in the left half of the picture equal the equivalent to it in the right half of picture
        }
    }
    
  }

}

void mirror_right(){
  // nested loops for row and columns 
 for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE/2; j++)
    {
     for (int k = 0; k < 3; k++)
        {
      imgRGB[i][j][k] =  imgRGB[i][SIZE -j-1][k]; // make every pixel in the right half of the picture equal the equivalent to it in the left half of picture 
        }
    }
    
  }
}
void mirror_upper (){
  // nested loops for row and columns 
   for (int i = 0; i < SIZE/2; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      for (int k = 0; k < 3; k++)
        {
      imgRGB [SIZE -i-1][j][k] =imgRGB[i][j][k]; //make every pixel in the bottom half of the picture equal the equivalent to it in the top half of picture 
        }
    }
    
  }
}

void mirror_lower(){
  // nested loops for row and columns 
 for (int i = 0; i < SIZE/2; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
     for (int k = 0; k < 3; k++)
        { 
       imgRGB[i][j][k] = imgRGB [SIZE -i-1][j][k]; //make every pixel in the top half of the picture equal the equivalent to it in the bottom half of picture  
        }
    }
    
  }


}

void filtera(){
    int x=0;  // the number of mirror will user choose to do
    cout << "1-left1/2\n2-right1/2\n3-upper1/2\n4-lower1/2\nplease choose type of mirror : ";
    cin>>x;

    if(x ==1){
      mirror_left();
    }else  if(x ==2){
      mirror_right();
    }else  if(x ==3){
      mirror_upper();
    }else  if(x ==4){
      mirror_lower();
    }else{
      cout<< "Wrong input";
    }
}

//-------------------
unsigned char Q1[4][128][128][3] ; // declear quarter array for each quarter

void saveEachQuarter(){ //functon for store every quarter
  x=0,y=0;
  for (int i = 0; i < SIZE/2; i++)
  {
    for (int j = 0; j < SIZE/2; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        
      Q1[0][x][y][k]=imgRGB[i][j][k]; //get pixels of first Quarter into quarter array
      }
      
      y++;
    }
    x++;
    y=0;
  }
  x=0,y=0;
  for (int i = 0; i < SIZE/2; i++) {
      for (int j = (SIZE/2); j< SIZE; j++) {
        for (int k = 0; k < 3; k++)
      {
        
      Q1[1][x][y][k]=imgRGB[i][j][k]; //get pixels of second Quarter into quarter array
      }
        y++;
      }
      x++;
      y=0;
    }
    x=0,y=0;
    for (int i = (SIZE/2); i < SIZE; i++) {
      for (int j = 0; j< SIZE/2; j++) {
        for (int k = 0; k < 3; k++)
      {
        
      Q1[2][x][y][k]=imgRGB[i][j][k]; //get pixels of third Quarter into quarter array
      }
        y++;
      }
      x++;
      y=0;
  }

  x=0,y=0;
  for (int i = (SIZE/2); i < SIZE; i++) {
      for (int j = (SIZE/2); j< SIZE; j++) {
        for (int k = 0; k < 3; k++)
      {
        
      Q1[3][x][y][k]=imgRGB[i][j][k]; //get pixels of fourth Quarter into quarter array
      }
        y++;
      }
      x++;
      y=0;
  }
}

void filterb(){
    saveEachQuarter();  //call save each quarter function
    int choice[4];
    x=0,y=0;

  cout<<"Enter new order of Quarters: ";
  for (int i = 0; i < 4; i++)
  {
  cin>>choice[i]; //take from user the new order and save them in array
  }

    for (int i = 0; i < SIZE/2; i++) {
      for (int j = 0; j< SIZE/2; j++) {
        for (int k = 0; k < 3; k++)
      {
        
        imgRGB[i][j][k] = Q1[choice[0]-1][x][y][k]; //take the first index the user input and add it to first quarter at image
      }
        y++;
      }
      x++;
      y=0;
    }
    x=0,y=0;
    for (int i = 0; i < SIZE/2; i++) {
      for (int j = (SIZE/2); j< SIZE; j++) {
         for (int k = 0; k < 3; k++)
      {
        //take the second index the user input and add it to second quarter at image
        imgRGB[i][j][k] = Q1[choice[1]-1][x][y][k];
      }

        y++;
      }
      x++;
      y=0;
    }

    x=0,y=0;

    for (int i = (SIZE/2); i < SIZE; i++) {
      for (int j = 0; j< SIZE/2; j++) {
        for (int k = 0; k < 3; k++)
      {
        //take the third index the user input and add it to third quarter at image
        imgRGB[i][j][k] = Q1[choice[2]-1][x][y][k];
      }
        y++;
      }
      x++;
      y=0;
    }

    x=0,y=0;

    for (int i = (SIZE/2); i < SIZE; i++) {
      for (int j = (SIZE/2); j< SIZE; j++) {
         for (int k = 0; k < 3; k++)
      {
        //take the fourth index the user input and add it to fourth quarter at image
        imgRGB[i][j][k] = Q1[choice[3]-1][x][y][k];
      }
        y++;
      }
      x++;
      y=0;
    }
}


unsigned char m[3][3][3]; //declear new aaray 3x3x3

void part(int k,int f){
  int sum=0;
  for (int x= 0; x < 3; x++)
  { 
    sum =0;
    for (int i =k ; i < k+3 ; i++){ //nested loops for each 3 pixels (rows and columns)
      for ( int j = f ; j < f+3 ; j++){
        m[i-k][j-f][x]=imgRGB[i][j][x];
        sum += imgRGB[i][j][x];
        }
      }
    sum = sum/9; //to calculate the average
    m[1][1][x]=sum;
  }
  for (int i =k ; i < k+3 ; i++){
      for ( int j = f ; j < f+3 ; j++){
        for (int v = 0; v < 3; v++)
        {
          imgRGB[i][j][v]=m[i-k][j-f][v];
        }
      }
  }
}

void filterc(){

  for (int v = 0; v < 2; v++)
  {
    for (int i =0 ; i < SIZE ; i++){
        for ( int j = 0 ; j < SIZE ; j++){
          part(i,j);
        }
    }
  }
}
